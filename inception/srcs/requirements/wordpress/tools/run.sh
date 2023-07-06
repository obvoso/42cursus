wp core download
wp config create --dbhost=3306 --dbname=$DBNAME --dbuser=$DBUSER --dbpass=$DBUSERPW
wp config get
wp core install --admin_user=$WP_ADMIN  \
                --admin_pass=$WP_PASSWORD \
                --admin_email=$WP_EMAIL \
                --url=$DOMAIN_NAME \
                --title='SOO WORLD'
wp super-admin add $WP_ADMIN
wp user create $WP_USER $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PASSWORD

php-fpm81 -F