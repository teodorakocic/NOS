FROM python:3.8-slim-buster

ENV DATABASE_SENSOR=IoT
ENV COLLECTION=SmokeDetection

WORKDIR /python-docker

COPY requirements.txt requirements.txt
RUN pip install -r requirements.txt

COPY . .

EXPOSE 5001

CMD [ "python", "app.py" ]

# CMD [ "python", "-m" , "flask", "run", "--host=smokedetection", "--port=5001" ]