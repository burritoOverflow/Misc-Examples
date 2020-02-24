#!/bin/bash
if [[ $# -ne 2 ]]
  then
    echo "Usage: ./mirrorSite.sh <url> <bucket-name>"
    exit 1
fi

wget -e robots=off --mirror --user-agent="Mozilla/4.0 (compatible; MSIE 7.0b; Windows NT 5.1; .NET CLR 1.1.4322; .NET CLR 2.0.40607)"  \
--convert-links --adjust-extension --page-requisites --no-parent $1

dirname=`echo $1 | awk -F[/:] '{print $4}'`

cd $dirname

aws s3 mb s3://$2
aws s3 website s3://$2/ --index-document index.html --error-document index.html
aws s3 cp . s3://$2 --recursive --acl public-read

echo "Removing $dirname"
cd ..
rm -rf $dirname
