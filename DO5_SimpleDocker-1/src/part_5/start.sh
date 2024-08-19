#!/bin/bash

export DOCKER_CONTENT_TRUST=1
docker build -t sobchakr/image:0.1 .
#docker run -d -p 80:81 --name part_5 -v /$(pwd)/nginx/nginx.conf:/etc/nginx/nginx.conf isrealpe/image:0.0.1
#docker restart part_5
