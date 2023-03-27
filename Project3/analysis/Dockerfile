FROM python:3.8-slim-buster

ENV DATABASE_ANALYSIS=Analysis
ENV COLLECTION_ANALYSIS=IoTSmoke

WORKDIR /python-docker

COPY requirements.txt requirements.txt
RUN pip install -r requirements.txt

COPY . .

EXPOSE 5002

CMD [ "python", "app.py" ]

# CMD [ "python", "-m" , "flask", "run", "--host=0.0.0.0", "--port=5002" ]