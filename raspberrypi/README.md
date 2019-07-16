- symlink `daemon.sh` to `/etc/init.d/`:

```
sudo ln -s /home/pi/checkouts/VinylScrobbler/master/raspberrypi/daemon.sh /etc/init.d/vinyl-scrobbler
```

- run `sudo update-rc.d vinyl-scrobbler defaults`
