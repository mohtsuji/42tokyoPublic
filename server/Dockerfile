FROM debian:buster

ENV AUTOINDEX="on"

#mariadb & phpadminはPHP言語で動くので、PHPとその拡張機能をあらかじめインストールする
RUN apt-get -y update \
		&& apt-get upgrade -y \
		&& apt-get -y install wget \
		&& apt-get -y install nginx \
		&& apt-get -y install mariadb-server \
		&& apt-get -y install \
		php7.3 \
		php-mysql \
		php-fpm \
		php-pdo \
		php-gd \
		php-cli \
		php-mbstring \
		&& rm /etc/nginx/sites-available/default
	
COPY ./srcs/nginx-conf /etc/nginx/sites-available/default
#コマンドを実行する場所を指定
#phpmyadminは初期設定でどこのディレクトリに入れるかは任意なので
WORKDIR /var/www/html/ 

RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz \
		&& tar -xf phpMyAdmin-5.0.1-english.tar.gz \
		&& rm -rf phpMyAdmin-5.0.1-english.tar.gz \
		&& mv phpMyAdmin-5.0.1-english phpmyadmin \
		&& wget https://wordpress.org/latest.tar.gz \
		&& tar -xvzf latest.tar.gz \
		&& rm -rf latest.tar.gz \
		&& openssl req -x509 -nodes -days 365 -subj "/C=JP/ST=japan/L=hokkaido/O=engaru/OU=42tokyo/CN=mohtsuji" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt;

COPY ./srcs/config.inc.php phpmyadmin
COPY ./srcs/wp-config.php /var/www/html
COPY ./srcs/init.sh /var/tmp/

#chown = user/group/otherがそれぞれ誰を示すのかを決めている（今回は、www-dateという所有者とwww-dateというグループを作成し、それらを全てのディレクトリに適用している）
#chmod = user/group/otherに対し、どこまで権限を与えるかを決めている（今回は、所有者には読み書き実行の権限を、groupとotherには読みと実行の権限を与えて、これをvar/www/*以下の全てのディレクトリに適用している）
#www-dateとはnginxのこと。userとgroupをwww-dataにして権限を与えてあげないと、nginxがデータを取れない
RUN chown -R www-data:www-data * \
		&& chmod -R 755 /var/www/*

CMD ["bash", "/var/tmp/init.sh"]
