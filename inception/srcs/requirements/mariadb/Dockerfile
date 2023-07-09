FROM alpine:3.17

RUN apk update \
    && apk add --no-cache \
    mariadb \
    mariadb-client \
    dumb-init

RUN mkdir -p /run/mysqld
RUN chmod 777 /run/mysqld
RUN mkdir -p /var/lib/mysql

COPY ./conf/mariadb-server.cnf /etc/my.cnf.d/mariadb-server.cnf
RUN chmod 755 /etc/my.cnf.d/mariadb-server.cnf

COPY ./tools/run.sh /tmp/run.sh
RUN chmod +x /tmp/run.sh

ENTRYPOINT [ "/usr/bin/dumb-init", "--"]
CMD ["sh", "/tmp/run.sh"]

EXPOSE 3306