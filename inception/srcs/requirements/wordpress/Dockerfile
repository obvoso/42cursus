FROM alpine:3.17

WORKDIR /var/www/wordpress
# php == php81
RUN apk update \
    && apk add --no-cache \
    php \
    curl \
    php-fpm \
    php-phar \
    php-curl \
    php-iconv \
    php-mysqli \
    php-openssl \
    mariadb-client \
    dumb-init

#php : 동적인 웹페이지를 만들어주는 서버사이드 스크립트 언어
#php-fpm : php를 실행시켜주는 프로그램, fastCGI processs manager
#fastCGI : 클라이언트 - 웹서버 - php프로그램 으로 요청 전달,
#          클라이언트의 요청마다 새로운 프로세스를 생성하는 것이 아니라
#          기존에 생성된 프로세스를 재활용

# https://make.wordpress.org/cli/handbook/guides/installing/
# wp-cli 설치

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    # 아래 cmd를 수행하면 php wp-cli.phar ~ 로 실행하는 대신 wp ~ 로 실행할 수 있게 된다.
    # /usr/local/bin/wp-cli.phar을 /usr/local/bin/wp로 실행 가능한 경로 연결
    && chmod +x wp-cli.phar \
    # 관례적으로 사용자가 설치한 프로그램은 /usr/local/bin에 설치
    && mv wp-cli.phar /usr/local/bin/ \
    # wp를 wp-cli.phar로 심볼릭 링크를 걸어 wp로 실행 가능하게 함
    && ln -sf /usr/local/bin/wp-cli.phar /usr/local/bin/wp

COPY ./tools/run.sh /tmp/wordpress_run.sh
RUN chmod +x /tmp/wordpress_run.sh

EXPOSE 9000

ENTRYPOINT [ "/usr/bin/dumb-init", "--" ]
CMD ["sh", "/tmp/wordpress_run.sh"]
