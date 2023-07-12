FROM alpine:3.17

# RUN을 여러번 사용하면 각 명령어는 별도의 레이어에서 독립적으로 실행된다.
# 이전 레이어의 변경사항이 이후 레이어에 반영된다.

# RUN을 단일 명령어로 작성하면 이들은 단일 레이어에서 실행된다. 
RUN apk update \
    && apk add --no-cache nginx openssl


RUN openssl req -x509 \
    -newkey rsa:2048 \
    -nodes \
    -days 365 \
    -keyout /etc/ssl/private/soo.key \
    -out /etc/ssl/certs/soo.crt \
    -subj "/C=KR/ST=Seoul/L=Gangnam/O=42Seoul/OU=Student/CN=localhost"

COPY ./conf/nginx.conf /etc/nginx/http.d/

CMD ["nginx", "-g", "daemon off;"]

EXPOSE 443
