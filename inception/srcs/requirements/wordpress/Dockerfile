FROM alpine:3.17

# php == php81
RUN apk update && \
    apk add --no-cache php \
    --no-cache php-fpm \
    && mkdir -p /usr/share/webapps/ \
    && cd /usr/share/webapps/ \
    && wget https://wordpress.org/latest.tar.gz \
    && tar -xzvf latest.tar.gz \
    && rm -rf latest.tar.gz \
    && apk add --no-cache php-mysqli \
    
