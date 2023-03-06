#!/bin/bash

sed -i "s/bind-ad/\#bind-ad/g" /etc/mysql/mariadb.conf.d/50-server.cnf
sed -i "s/#port/port/g" /etc/mysql/mariadb.conf.d/50-server.cnf

service mysql start

mysql -e "CREATE DATABASE $MYSQL_DATABASE;"
mysql -e "CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
mysql -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' WITH GRANT OPTION;"
mysql -e "FLUSH PRIVILEGES;"

service mysql stop

mysqld
