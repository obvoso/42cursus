FROM alpine:3.17

RUN apk update \
    && apk add \
    mariadb \
    mariadb-client

RUN mkdir -p /run/mysqld \
    && mkdir -p /var/lib/mysql \
    && chmod 777 /run/mysqld

ENTRYPOINT ["/usr/bin/mysql_install_db", "--user=mysql", "--datadir=/var/lib/mysql"]
# /usr/bin/mysql_install_db "--user=mysql" "--datadir=/var/lib/mysql"
# mysqld --user=mysql --console &
# mysql
# create database wordpress
# create user 'soo'@'%' identified by '0000';
# grant all privileges on *.* to 'soo'@'%';
# flush privileges;

CMD ["mysqld", "--user=mysql", "--console"]

EXPOSE 3306
