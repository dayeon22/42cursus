FROM	debian:buster

RUN	apt-get update &&\
	apt-get install -y mariadb-server vim bash
	#apt-get install -y procps

RUN	mkdir -p /etc/mysql/mysql.conf.d
COPY	./conf/my.cnf /etc/mysql/

COPY	./tools/db.sh /
RUN	mkdir -m 700 /run/mysqld && chown mysql:mysql /run/mysqld && \
	chmod 777 /db.sh

EXPOSE	3306

CMD	/db.sh
