FROM	debian:buster

RUN	apt-get update && \
	apt-get -y install nginx openssl vim

RUN	openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=daypark/CN=localhost" \
	-keyout localhost.dev.key \
	-out localhost.dev.crt
# keyout /etc/ssl/certs/public.key
# -out /etc/ssl/certs/certificate.crt

RUN	chmod 600 localhost.dev.key localhost.dev.crt && \
	mv localhost.dev.crt /etc/ssl/certs/ && \
	mv localhost.dev.key /etc/ssl/private/

COPY	./conf/default.conf /etc/nginx/conf.d/

RUN	mkdir -p /run/nginx && \
	chown -R www-data /var/www/* && \
	chmod -R 755 /var/www/*

EXPOSE	443

CMD	["nginx", "-g", "daemon off;"]
