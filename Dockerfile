FROM python:2.7

RUN apt-get update
RUN apt-get install -y ffmpeg
RUN apt-get install -y libasound-dev portaudio19-dev libportaudio2 libportaudiocpp0
COPY requirements.txt requirements.txt
RUN pip install -r requirements.txt
ENV FLASK_APP server.py
ENV FLASK_RUN_HOST 0.0.0.0
EXPOSE 5000
COPY . .
CMD [ "gunicorn", "server:app" ]