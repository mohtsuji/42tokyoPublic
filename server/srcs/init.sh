#!/bin/bash

AUTO_INDEX=$AUTOINDEX
sed -i -e "s!AUTOINDEX!$AUTO_INDEX!g" /etc/nginx/sites-available/default
service nginx start #nginxを起動する
service mysql start
service php7.3-fpm start

# Configure a wordpress database
echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password #wordpressという名のスキーマを作った
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password # スキーマにアクセスするアカウントを作成した
echo "FLUSH PRIVILEGES;"| mysql -u root --skip-password #権限を更新している
echo "update mysql.user set plugin='' where user='root';"| mysql -u root --skip-password #plugin の認証(ユーザー認証？）をオフにしている（パスワードが必要なくなる）

bash
