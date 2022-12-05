FROM debian:buster

RUN apt update; \
    apt install -y nginx openssl

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx.key \
    -out /etc/ssl/certs/nginx.crt \
    -subj "/C=TR/ST=Istanbul/L=Istanbul/O=Ecole42/OU=fcil/CN=fcil"
#ssl sertifikası oluşturmaya yarıyor, -x509 -> imzalayıcı fonksiyon
# -nodes -> gizli anahtarı şifrelemez -days -> belli gün sayısı
#rsa:2048 -> oluşturan yeni anahtarı rsa 2048 algoritması ile şifreler
#-keyout -> gizli key konumu -out -> key konumu
#-subj sertifika imzası
COPY ./conf/default etc/nginx/sites-enabled/default
#https://www.coderrocketfuel.com/article/default-nginx-configuration-file-inside-sites-available-default
EXPOSE 443
#bknz pdf
CMD ["nginx", "-g", "daemon off;"]
#-g global değişkeni set eder, deamon off -> ana process haline getirir.