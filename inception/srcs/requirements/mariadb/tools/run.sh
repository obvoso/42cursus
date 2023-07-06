#! /bin/sh

if [ ! -e /var/lib/mysql/$DBNAME ]; then
    /usr/bin/mysql_install_db "--user=mysql" "--datadir=/var/lib/mysql"
    mysqld --user=mysql --console &
    sleep 1
    echo "stlqkf"
    # mysql
    mysql -e "create database $DBNAME;"
    mysql -e "create user '$DBADMIN'@'%' identified by '$DBADMINPW';"
    mysql -e "create user '$DBUSER'@'%' identified by '$DBUSERPW';"
    mysql -e "grant all privileges on $DBNAME.* to '$DBADMIN'@'%';"
    mysql -e "flush privileges;"
    mysql -e "grant all privileges on $DBNAME.* to '$DBUSER'@'%';"
    mysql -e "flush privileges;"
    # exit
    mysql -e "show databases;"

    mysqladmin -u root shutdown
fi

mysqld --user=mysql
