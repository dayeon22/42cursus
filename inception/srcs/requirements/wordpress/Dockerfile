FROM	debian:buster

RUN	apt-get update && \
	apt-get install -y php7.3 php7.3-fpm php7.3-common php7.3-iconv \
			php7.3-json php7.3-xml php7.3-mysqli \
			php7.3-cgi php7.3-mbstring \
			wget sudo vim mariadb-client curl sendmail

COPY	./tools/wp.sh /

RUN	mkdir -p /var/www/wordpress && \
	mkdir -p /run/php && \
	chmod 777 /run/ && \
	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp && \
	chmod 777 /usr/local/bin/wp && \
	chmod 777 /wp.sh

EXPOSE	9000

CMD	./wp.sh
