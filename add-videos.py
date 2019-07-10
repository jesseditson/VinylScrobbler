import os
import json
import urllib
from bs4 import BeautifulSoup


def find_video(name):
    print("Finding videos for %s" % name)
    query = urllib.quote(name)
    url = "https://www.youtube.com/results?search_query=" + query
    response = urllib.urlopen(url)
    html = response.read()
    soup = BeautifulSoup(html, 'html.parser')
    urls = [
        'https://www.youtube.com%s' % vid['href'] for
        vid in soup.findAll(attrs={'class': 'yt-uix-tile-link'}) if not
        vid['href'].startswith("https://googleads.g.doubleclick.net/")]
    idx = 0
    while True:
        if idx == len(urls):
            print("No more videos found.")
            return None
        print(urls[idx])
        val = raw_input("Is this the right video? [y|n|s|a] ")
        if val == 'y':
            return urls[idx]
        if val == 'n':
            idx += 1
        if val == 's':
            return -1
        if val == 'a':
            return -2


folder = 'library'
for filename in os.listdir(folder):
    filepath = folder + '/' + filename
    print(filepath)
    with open(filepath, 'r') as file:
        string = file.read()
        data = json.loads(string)
        for album in data["albums"]:
            for track in album["tracks"]:
                if track.get("video_url", None) is None:
                    val = find_video("%s - %s - %s" % (
                        album["artist"], album["title"], track["title"]))
                    if val == -1:
                        # s means skip song
                        continue
                    elif val == -2:
                        # a means skip album
                        break
                    track["video_url"] = val
                    with open(filepath, 'w') as file:
                        file.write(json.dumps(data))
