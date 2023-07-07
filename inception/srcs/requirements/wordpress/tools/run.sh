wp core download

# 동일한 네트워크에 있는 mariadb의 컨테이너네임:포트번호
# 사용할 db config 파일 생성, mariadb 컨테이너에서 만든 db로 연결
wp config create --dbhost=mariadb:3306 --dbname=$DB_NAME --dbuser=$DB_ADMIN --dbpass=$DB_ADMINPW
# config파일 출력
wp config get
wp core install --url=$DOMAIN_NAME \
                --admin_user=$WP_ADMIN \
                --admin_password=$WP_PASSWORD \
                --admin_email=$WP_EMAIL \
                --title='SOO WORLD'
wp super-admin add $WP_ADMIN
wp user create $WP_USER $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PASSWORD

php-fpm81 -F