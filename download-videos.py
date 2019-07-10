import urllib2
import os
import json
from pytube import YouTube

folder = 'library'
for filename in os.listdir(folder):
    filepath = folder + '/' + filename
    print(filepath)
    with open(filepath, 'r') as file:
        string = file.read()
        data = json.loads(string)
        for album in data["albums"]:
            for track in album["tracks"]:
                if track.get("video_url", None) is not None:
                    name_tuple = (album["artist"],
                                  album["title"], track["title"])
                    print("Dowloading %s - %s - %s" % name_tuple)
                    try:
                        yt = YouTube(track["video_url"])
                        yt.streams.filter(only_audio=True).first().download(
                            output_path="library",
                            filename="%s_%s_%s.mp4" % name_tuple)
                        track["audio_file"] = "%s_%s_%s.mp4" % name_tuple
                        with open(filepath, 'w') as file:
                            file.write(json.dumps(data))
                    except urllib2.HTTPError:
                        print("download failed.")
