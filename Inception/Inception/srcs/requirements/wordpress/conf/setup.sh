#!/bin/bash

chown -R www-data /var/www/wordpress #izinler veriliyor
chmod -R 775 /var/www/wordpress 

mkdir -p /run/php/
touch /run/php/php7.3-fpm.pid

if [ ! -f /var/www/wordpress/wp-config.php ]; then
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
#wp-cli php archive for installing wp
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

cd /var/www/wordpress

wp core download --allow-root

mv /var/www/wp-config.php /var/www/wordpress/

wp core install --allow-root --url=${DOMAIN_NAME} --title=${WORDPRESS_NAME} --admin_user=${WORDPRESS_ROOT_LOGIN} --admin_password=${MYSQL_ROOT_PASSWORD} --admin_email=${WORDPRESS_ROOT_EMAIL}
wp user create ${MYSQL_USER} ${WORDPRESS_USER_EMAIL} --user_pass=${MYSQL_PASSWORD} --role=author --allow-root
wp theme install inspiro --activate --allow-root
wp plugin install redis-cache --activate --allow-root
wp plugin update --all --allow-root
wp plugin activate redis-cache --allow-root

fi

wp redis enable --force --allow-root
#wp redis cache service

/usr/sbin/php-fpm7.3 -F
#start php-fpm