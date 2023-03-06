sed -i -e "s/listen = \/run\/php\/php7.3-fpm.sock/listen = 0.0.0.0:9000/g" /etc/php/7.3/fpm/pool.d/www.conf

wp core download --allow-root \
		--path=/var/www/wordpress/

wp config create --allow-root \
		--path=/var/www/wordpress/ \
		--dbname=$MYSQL_DATABASE \
		--dbuser=$MYSQL_USER \
		--dbpass=$MYSQL_PASSWORD \
		--dbhost=mariadb:3306

wp core install --allow-root \
		--path=/var/www/wordpress/ \
		--url=$WP_URL \
		--title=$WP_TITLE \
		--admin_user=$WP_ADMIN_USER \
		--admin_password=$WP_ADMIN_PASSWORD \
		--admin_email=$WP_ADMIN_EMAIL

wp user create --allow-root \
		$WP_USER $WP_EMAIL \
		--path=/var/www/wordpress/ \
		--user_pass=$WP_PASSWORD \
		--role=author

/usr/sbin/php-fpm7.3 -F --nodaemonize
