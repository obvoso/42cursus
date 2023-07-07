#! /bin/sh

if [ ! -e /var/lib/mysql/$DB_NAME ]; then
    /usr/bin/mysql_install_db "--user=mysql" "--datadir=/var/lib/mysql"
    mysqld --user=mysql --console &
    sleep 1

    mysql -e "create database $DB_NAME;"
    mysql -e "create user '$DB_ADMIN'@'%' identified by '$DB_ADMINPW';"
    mysql -e "create user '$DB_USER'@'%' identified by '$DB_USERPW';"
    mysql -e "grant all privileges on $DB_NAME.* to '$DB_ADMIN'@'%';"
    mysql -e "flush privileges;"
    mysql -e "grant all privileges on $DB_NAME.* to '$DB_USER'@'%';"
    mysql -e "flush privileges;"

    mysqladmin -u root shutdown
fi

mysqld --user=mysql
