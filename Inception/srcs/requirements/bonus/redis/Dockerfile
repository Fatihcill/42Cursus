FROM alpine:3.14.2

RUN apk --update add redis; \
    sed -i "s/bind 127.0.0.1/#bind 127.0.0.1/g" /etc/redis.conf; \ 
    #tüm ağlara açmamızı sağlıyor
    sed -i "s/maxmemory <bytes>/maxmemory 256mb/g" /etc/redis.conf; \
    sed -i "s/maxmemory-policy noeviction/maxmemory-policy allkeys-lfu/g" /etc/redis.conf; \
    # https://redis.io/docs/reference/eviction/
    sed -i "s/protected-mode yes/protected-mode no/g" /etc/redis.conf; \
    # sadece loopback adresinden networkten data almak için. protected-mode kapatılıyor
    rm -rf /var/cache/apk/*

EXPOSE 6379
#redis portu
CMD [ "/usr/bin/redis-server", "/etc/redis.conf"]
#redis sunucusu çalıştırılıyor