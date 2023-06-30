FROM alpine:3.17

RUN apk update
RUN apk add mariadb mariadb-client
RUN apk add dumb-init

ENTRYPOINT ["/usr/bin/dumb-init", "--"]
CMD ["sh", "/"] ..........

EXPOSE 3306
