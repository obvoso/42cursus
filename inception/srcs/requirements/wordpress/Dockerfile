FROM alpine:3.17

# php == php81
RUN apk update \
    && apk add --no-cache \
    php \
    curl \
    php-fpm \
    php-phar \
    php-curl \
    php-openssl \
    mariadb-client \
    dumb-init \

# https://make.wordpress.org/cli/handbook/guides/installing/
# wp-cli 설치
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    # 아래 cmd를 수행하면 php wp-cli ~ 로 실행하는 대신 wp ~ 로 실행할 수 있게 된다.
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp \

    
