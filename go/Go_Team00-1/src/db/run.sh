#!/bin/bash

if docker-compose -v >/dev/null 2>&1; then
    docker-compose up -d
    sudo docker exec -ti postgres su - postgres -c 'psql -d anomaly -f /docker-entrypoint-initdb.d/init.sql'
else
    echo "docker-compose does not exist"
fi


