#!/bin/bash

sudo docker build -t sobchakr/image:latest .
sudo docker run -d -p 80:81 --name part_4 -v /$(pwd)/nginx/nginx.conf:/etc/nginx/nginx.conf sobchakr/image:latest
#docker restart part_4
