FROM nginx:latest

USER root

WORKDIR /home

RUN apt-get update && \
    apt-get upgrade && \
    apt-get -y install gcc && \
    apt-get -y install spawn-fcgi && \
    apt-get -y install libfcgi-dev

COPY server.c /home
COPY start_server.sh /home
COPY /nginx/nginx.conf /etc/nginx/

RUN chmod +x start_server.sh
RUN gcc server.c -lfcgi

CMD [ "sh", "./start_server.sh" ]
