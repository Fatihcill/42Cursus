FROM debian:buster

RUN apt update; \
    apt install -y php7.3 php-mysqli php-fpm mariadb-client curl sendmail

COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d
#web server phpfpm config https://www.php.net/manual/en/install.fpm.configuration.php
COPY ./conf /var/www/

EXPOSE 9000
#containerımızın hangi port üzerinden yayın yapacağını belirtmemize yarar
#9000 çünkü php-fpm daha hızlı xd

CMD ["bash", "/var/www/setup.sh"]
