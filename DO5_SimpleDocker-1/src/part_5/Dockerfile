FROM nginx:stable
USER root
WORKDIR /home/

COPY ./nginx/nginx.conf /etc/nginx/
COPY ./start_server.sh /home/
COPY server.c /home/

RUN apt-get update; \
    apt-get install -y gcc spawn-fcgi libfcgi-dev; \
    rm -rf /var/lib/apt/lists/*; \
    chmod u-s /bin/su; \
    chmod u-s /usr/bin/newgrp; \
    chmod u-s /usr/bin/passwd; \
    chmod u-s /usr/bin/gpasswd; \
    chmod u-s /bin/umount; \
    chmod u-s /usr/bin/chfn; \
    chmod u-s /usr/bin/chsh; \
    chmod u-s /bin/mount; \
    chmod g-s /usr/bin/expiry; \
    chmod g-s /usr/bin/chage; \
    chmod g-s /usr/bin/wall; \
    chmod g-s /sbin/unix_chkpwd; \
    chown -R nginx:nginx /etc/nginx/nginx.conf; \
    chown -R nginx:nginx /home/; \
    chown -R nginx:nginx /var/cache/nginx; \
    touch /var/run/nginx.pid; \
    chown nginx:nginx /var/run/nginx.pid

RUN gcc server.c -lfcgi

USER nginx

HEALTHCHECK --interval=5m --timeout=3s \
 CMD curl -f http://localhost/ || exit 1

CMD ["sh", "./start_server.sh"]