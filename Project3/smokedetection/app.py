from flask import Flask, request, json, Response
from pymongo import MongoClient
from kafka import KafkaProducer
import logging as log
import os
import time
import csv
import random
import datetime


def generate_data():
    i = random.randint(1, 62631)

    fire = False
    if fireAlarm[i] == 1:
        fire = True

    data = {
        "database": database,
        "collection": collection,
        "Document": {
            "date": datetime.datetime.now(datetime.timezone.utc),
            "temperature": float(temperature[i]),
            "humidity": float(humidity[i]),
            "TVOC":  int(TVOC[i]),
            "eCO2": int(eCO2[i]),
            "raw H2": int(H2[i]),
            "raw Ethanol": int(ethanol[i]),
            "pressure": float(pressure[i]),
            "PM1.0": float(PM1_0[i]),
            "NC1.0": float(NC1_0[i]),
            "fire alarm": fire
        }
    }

    return data


app = Flask(__name__)

database = os.getenv('DATABASE_SENSOR')
collection = os.getenv('COLLECTION')

temperature = list()
humidity = list()
TVOC = list()
eCO2 = list()
H2 = list()
ethanol = list()
pressure = list()
PM1_0 = list()
NC1_0 = list()
fireAlarm = list()

with open("smoke_detection_iot.csv", "r") as file:
    csv_reader = csv.DictReader(file)
    for row in csv_reader:
        temperature.append(row['Temperature'])
        humidity.append(row['Humidity'])
        TVOC.append(row['TVOC'])
        eCO2.append(row['eCO2'])
        H2.append(row['Raw H2'])
        ethanol.append(row['Raw Ethanol'])
        pressure.append(row['Pressure'])
        PM1_0.append(row['PM1.0'])
        NC1_0.append(row['NC1.0'])
        fireAlarm.append(row['Fire Alarm'])



class MongoAPI:
    def __init__(self, data):
        log.basicConfig(level=log.DEBUG, format='%(asctime)s %(levelname)s:\n%(message)s\n')
        self.client = MongoClient("mongodb://mongodb:27017/") 

        database = os.getenv('DATABASE_SENSOR')
        collection = os.getenv('COLLECTION')
        cursor = self.client[database]
        self.collection = cursor[collection]
        self.data = data

    def read(self):
        log.info('Reading All Data')
        documents = self.collection.find()
        output = [{item: data[item] for item in data if item != '_id'} for data in documents]
        return output

    def write(self, data):
        log.info('Writing Data')
        new_document = data['Document']
        response = self.collection.insert_one(new_document)
        output = {'Status': 'Successfully Inserted',
                  'Document_ID': str(response.inserted_id)}
        return output

    def update(self):
        log.info('Updating Data')
        filt = self.data['Filter']
        updated_data = {"$set": self.data['DataToBeUpdated']}
        response = self.collection.update_one(filt, updated_data)
        output = {'Status': 'Successfully Updated' if response.modified_count > 0 else "Nothing was updated."}
        return output

    def delete(self, data):
        log.info('Deleting Data')
        filt = data['Filter']
        response = self.collection.delete_one(filt)
        output = {'Status': 'Successfully Deleted' if response.deleted_count > 0 else "Document not found."}
        return output


@app.route('/')
def base():
    return Response(response=json.dumps({"Status": "UP"}),
                    status=200,
                    mimetype='application/json')


@app.route('/sensordata', methods=['GET'])
def mongo_read():
    data = request.json
    if data is None or data == {}:
        return Response(response=json.dumps({"Error": "Please provide connection information"}),
                        status=400,
                        mimetype='application/json')
    obj1 = MongoAPI(data)
    response = obj1.read()
    return Response(response=json.dumps(response),
                    status=200,
                    mimetype='application/json')


@app.route('/sensordata', methods=['POST'])
def mongo_write():
    data = request.json
    if data is None or data == {} or 'Document' not in data:
        return Response(response=json.dumps({"Error": "Please provide connection information"}),
                        status=400,
                        mimetype='application/json')

    obj1 = MongoAPI(data)
    response = obj1.write(data)
    return Response(response=json.dumps(response),
                    status=200,
                    mimetype='application/json')

@app.route('/sensordata', methods=['PUT'])
def mongo_update():
    data = request.json
    if data is None or data == {} or 'Filter' not in data:
        return Response(response=json.dumps({"Error": "Please provide connection information"}),
                        status=400,
                        mimetype='application/json')
    obj1 = MongoAPI(data)
    response = obj1.update()
    return Response(response=json.dumps(response),
                    status=200,
                    mimetype='application/json')


@app.route('/sensordata', methods=['DELETE'])
def mongo_delete():
    data = request.json
    if data is None or data == {} or 'Filter' not in data:
        return Response(response=json.dumps({"Error": "Please provide connection information"}),
                        status=400,
                        mimetype='application/json')
    obj1 = MongoAPI(data)
    response = obj1.delete(data)
    return Response(response=json.dumps(response),
                    status=200,
                    mimetype='application/json')


if __name__ == '__main__':
    # app.run(debug=True)
    msgProducer = KafkaProducer(bootstrap_servers=['kafka-server:9092'], value_serializer = lambda x: x.encode('utf-8'))

    counter = 0
    avgTemp = 0
    avgHumid = 0
    minTVOC = 10000
    maxTVOC = -1
    avgCO2 = 0
    avgH2 = 0
    avgEth = 0
    avgPress = 0
    maxPM1 = -1
    maxNC1 = -1
    cntFireAl = 0
    
    while(1):
        counter += 1

        generatedData = generate_data() 
        mongo_obj = MongoAPI(generatedData)
        print(json.dumps(mongo_obj.write(data=generatedData), indent=4))

        avgTemp += generatedData['Document']['temperature']
        avgHumid += generatedData['Document']['humidity']
        if generatedData['Document']['TVOC'] < minTVOC:
            minTVOC = generatedData['Document']['TVOC']
        if generatedData['Document']['TVOC'] > maxTVOC:
            maxTVOC = generatedData['Document']['TVOC']
        avgCO2 += generatedData['Document']['eCO2']
        avgH2 += generatedData['Document']['raw H2']
        avgEth += generatedData['Document']['raw Ethanol']
        avgPress += generatedData['Document']['pressure']
        if generatedData['Document']['PM1.0'] > maxPM1:
            maxPM1 = generatedData['Document']['PM1.0']
        if generatedData['Document']['NC1.0'] > maxNC1:
            maxNC1 = generatedData['Document']['NC1.0']
        if generatedData['Document']['fire alarm'] == True:
            cntFireAl += 1

        if counter % 10 == 0:
            kafkaMessage = {
                "average temperature": avgTemp/10,
                "average humidity": avgHumid/10,
                "min TVOC": minTVOC,
                "max TVOC": maxTVOC,
                "average eCO2": avgCO2/10,
                "average raw H2": avgH2/10,
                "average raw ethanol": avgEth/10,
                "average pressure": avgPress/10,
                "max PM1.0": maxPM1,
                "max NC1.0": maxNC1,
                "count fire alarms": cntFireAl
            }
            msgProducer.send('smoke', json.dumps(kafkaMessage))
            msgProducer.flush()
            print('Message sent to Kafka topic with body: ' + json.dumps(kafkaMessage))

            avgTemp = 0
            avgHumid = 0
            minTVOC = 10000
            maxTVOC = -1
            avgCO2 = 0
            avgH2 = 0
            avgEth = 0
            avgPress = 0
            maxPM1 = -1
            maxNC1 = -1
            cntFireAl = 0

        time.sleep(0.5)
    