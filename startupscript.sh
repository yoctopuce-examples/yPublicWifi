#!/bin/sh /etc/rc.common

YPUBLICWIFI_BIN=/usr/sbin/yPublicWiFi

# If the yPublicWifi is not there, then exit.
if [ ! -e $YPUBLICWIFI_BIN ]; then
  echo "yPublicWifi binary is invalid ($YPUBLICWIFI_BIN)"
  exit 5
fi

if [ ! -x $YPUBLICWIFI_BIN ]; then
  echo "yPublicWifi binary has not the executable flag set"
  exit 5
fi

START=50
STOP=50

start() {
        service_start $YPUBLICWIFI_BIN -d
}

stop() {
        service_stop $YPUBLICWIFI_BIN
}