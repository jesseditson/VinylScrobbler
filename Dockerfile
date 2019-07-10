FROM python:2.7

RUN apt-get update
RUN apt-get install -y ffmpeg
RUN apt-get install -y libasound-dev portaudio19-dev libportaudio2 libportaudiocpp0
WORKDIR /src/app
COPY requirements.txt requirements.txt
RUN pip install -r requirements.txt
COPY . .
CMD [ "gunicorn", "server:app" ]