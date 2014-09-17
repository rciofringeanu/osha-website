#!/bin/bash

tika_url='ftp://ftp.hostingromania.ro/mirrors/apache.org/tika/tika-app-1.6.jar'
tika_dest='./docroot/sites/default/files/tika-app-1.6.jar'

if [ ! -f ${tika_dest} ]; then
	echo "Downloading tika from ${tika_url}"
	curl -o ${tika_dest} ${tika_url}
else
	echo "Tika already found on ${tika_dest}"
fi

tika_dest_abs="`readlink -e ${tika_dest}`"

cd docroot/

drush vset apachesolr_attachments_tika_jar tika-app-1.6.jar
drush vset apachesolr_attachments_tika_path "`dirname $tika_dest_abs`"