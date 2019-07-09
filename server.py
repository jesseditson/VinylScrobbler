import os
import json
from flask import Flask, request, jsonify
from werkzeug.utils import secure_filename
import dejavu_client
from dejavu.recognize import FileRecognizer
app = Flask(__name__)

ALLOWED_EXTENSIONS = set(["wav"])
UPLOAD_FOLDER = '/tmp'

app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER


class InvalidUsage(Exception):
    status_code = 400

    def __init__(self, message, status_code=None, payload=None):
        Exception.__init__(self)
        self.message = message
        if status_code is not None:
            self.status_code = status_code
        self.payload = payload

    def to_dict(self):
        rv = dict(self.payload or ())
        rv['message'] = self.message
        return rv


@app.errorhandler(InvalidUsage)
def handle_invalid_usage(error):
    response = jsonify(error.to_dict())
    response.status_code = error.status_code
    return response


def allowed_file(filename):
    return '.' in filename and \
           filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS


@app.route('/')
def hello():
    return 'Music Recognizer Ready'


@app.route('/', methods=['POST'])
def upload_file():  # check if the post request has the file part
    if 'file' not in request.files:
        raise InvalidUsage('Missing file', status_code=406)
    file = request.files['file']
    # if user does not select file, browser also
    # submit an empty part without filename
    if file.filename == '':
        raise InvalidUsage('Missing filename', status_code=406)
    if file and allowed_file(file.filename):
        filename = secure_filename(file.filename)
        file_path = os.path.join(app.config['UPLOAD_FOLDER'], filename)
        file.save(file_path)
        song = dejavu_client.recognize(FileRecognizer, file_path)
        return json.dumps(song)


if __name__ == '__main__':
    app.run()
