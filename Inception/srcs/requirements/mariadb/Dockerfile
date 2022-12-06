FROM debian:buster

RUN apt update; \
    apt install -y mariadb-server

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./conf/createdb.sql /
#https://exampleconfig.com/view/mariadb-debian10-etc-mysql-mariadb-conf-d-50-server-cnf
#sadece port açılıyor ve bind ip kapatılıyor
RUN service mysql start && mysql < createdb.sql && rm -f createdb.sql
#mysql i çalıştırır

EXPOSE 3306
#mysql portu
CMD /usr/bin/mysqld_safe
