import acoustid
import sys

apikey = "7C8vLuIYNq"

results = acoustid.match(apikey, sys.argv[1])
for score, rid, title, artist in results:
    print('%s - %s' % (artist, title))
    print('http://musicbrainz.org/recording/%s' % rid)
    print('Score: %i%%' % (int(score * 100)))
