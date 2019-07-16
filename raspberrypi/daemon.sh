#!/bin/bash

### BEGIN INIT INFO
# Provides:          vinyl-scrobbler
# Required-Start:    autofs $all
# Required-Stop:     $remote_fs
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: Auto scrobbles audio
# Description:       Listens to USB inputs and tries to identify songs using acoustid, then sends them to last.fm
### END INIT INFO

# PATH=/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin
DAEMON="python /home/pi/checkouts/VinylScrobbler/master/raspberrypi/capture-audio.py > /tmp/vinyl-scrobbler-$(date +\"%Y%m%d-%k%M\").log 2>&1"
NAME=vinyl-scrobbler
DESC="Vinyl Scrobbler"

test -x $DAEMON || exit 0

. /lib/lsb/init-functions

set -e

case "$1" in
  start)
    echo -n "Starting $DESC: "
    start-stop-daemon --start --quiet --pidfile /var/run/$NAME.pid --background --make-pidfile --exec $DAEMON
    echo "$NAME."
    ;;
  stop)
    echo -n "Stopping $DESC: "
    start-stop-daemon --stop --oknodo --quiet --pidfile /var/run/$NAME.pid
    echo "$NAME."
    ;;
  restart)
    $0 stop
    sleep 1
    $0 start
    ;;
  *)
    echo "Usage: $0 {start|stop|restart}" >&2
    exit 1
    ;;

esac

exit 0