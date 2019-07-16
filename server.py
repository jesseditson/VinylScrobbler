import os
import json
from functools import wraps
from flask import Response, Flask, request, jsonify, url_for, session, redirect
from werkzeug.utils import secure_filename
from dejavu import Dejavu
from dejavu_config import CONFIG
from dejavu.recognize import FileRecognizer
import discogs_client

djv = Dejavu(CONFIG)
app = Flask(__name__)

discogs = discogs_client.Client(
    'LongPlay/0.1',
    consumer_key='ZcXhVSsbcMSIRqRFvwrV',
    consumer_secret='MKJEfqPdnGTQDgwwzAAgmULEnwTfYvIx'
)

ALLOWED_EXTENSIONS = set(["wav"])
UPLOAD_FOLDER = '/tmp'

app.secret_key = 'secret key'
app.config['SESSION_TYPE'] = 'filesystem'
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
        song = djv.recognize(FileRecognizer, file_path)
        return json.dumps(song)


# Discogs API

def discogs_authenticated(f):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        creds = session.get('discogs_token')
        if creds is None:
            return redirect(
                url_for(
                    'login',
                    next=request.args.get('next') or request.referer or None
                ))
        oauth_token, oauth_token_secret = creds
        discogs.set_token(oauth_token, oauth_token_secret)
        return f(*args, **kwargs)
    return decorated_function


@app.route('/login')
def login():
    callback_url = 'http://localhost:8000%s' % url_for(
        'oauth_callback',
        next=request.args.get('next') or request.referer or None)
    request_token, request_secret, authorize_url = discogs.get_authorize_url(
        callback_url=callback_url)
    return redirect(authorize_url)


@app.route('/discogs/callback')
def oauth_callback():
    next_url = request.args.get('next') or url_for('discogs_albums')
    verifier = request.args.get('oauth_verifier')
    if verifier is None:
        raise InvalidUsage(
            'You denied the request to sign in.', status_code=401)
    token, secret = discogs.get_access_token(verifier)
    session['discogs_token'] = (
        token,
        secret
    )
    return redirect(next_url)


def release_to_json(release):
    return {
        "title": release.title,
        "artist": release.artists[0].name,
        "tracks": [{"title": track.title} for track in release.tracklist],
    }


@app.route('/albums')
@discogs_authenticated
def discogs_albums():
    me = discogs.identity()
    list = me.collection_folders[0].releases
    page = int(request.args.get('page') or 1)
    list.per_page = 10
    list.sort = "added"
    res = json.dumps({"albums": [
        release_to_json(item.release) for item in
        list.page(page)
    ]})
    return Response(res,
                    mimetype="application/json",
                    headers={"Content-Disposition":
                             "attachment;filename=page-%i.json" % page})


if __name__ == '__main__':
    app.run()
