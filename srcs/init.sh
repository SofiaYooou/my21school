service nginx start
service mysql start
service php7.3-fpm start


mysql -e "CREATE DATABASE wordpress;"
mysql -e "GRANT ALL PRIVILEGES ON wordpress.tablename TO 'root'@'localhost' WITH GRANT OPTION;"
mysql -e "FLUSH PRIVILEGES;"
mysql -e "UPDATE mysql.user set plugin='' where user='root';"

bash