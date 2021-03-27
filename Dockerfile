From debian:buster

RUN apt-get update

RUN apt-get upgrade -y

RUN apt-get -y install wget nginx vim mariadb-server php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring

COPY ./srcs/nginx.conf /etc/nginx/sites-available/nginx.conf
RUN ln -s /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled

WORKDIR /var/www/root

RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz

RUN tar -xf phpMyAdmin-5.0.1-english.tar.gz

RUN rm -rf phpMyAdmin-5.0.1-english.tar.gz

RUN mv phpMyAdmin-5.0.1-english phpmyadmin

COPY ./srcs/config.inc.php phpmyadmin

RUN wget https://wordpress.org/latest.tar.gz

RUN tar -xvzf latest.tar.gz

RUN rm -rf latest.tar.g
COPY ./srcs/wp-config.php /var/www/root/wordpress

RUN openssl req -x509 -nodes -days 365 -subj "/C=RU/L=KAZAN/OU=21school/" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt;

RUN chown -R www-data:www-data *

RUN chmod -R 755 /var/www/*

COPY ./srcs/init.sh ./

COPY ./srcs/autoindex.sh ./

CMD bash init.sh