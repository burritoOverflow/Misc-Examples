#!/bin/bash

# given a zipcode, identifies the city and state

if [ $# -eq 0 ]; then
	echo "Usage $0 <ZipCode>" >&2
	exit 1
fi

baseURL="http://www.city-data.com/zips"

echo -n "Zip Code $1 is in: "

curl -s -dump "$baseURL/$1.html" | \
	grep -i '<title>' | \
	cut -d\( -f2 | cut -d\) -f1

exit 0
