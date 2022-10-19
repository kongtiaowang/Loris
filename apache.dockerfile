FROM php:8.0.1-apache


COPY ./docs/config/docker-apache2-site /etc/apache2/sites-available/000-default.conf
RUN apt-get update && \
    apt-get install -y mariadb-client libzip-dev
RUN docker-php-ext-install pdo_mysql && \
    docker-php-ext-install zip

RUN  a2enmod rewrite
RUN  service apache2 restart
#RUN chown -R www-data:www-data /var/www/html &&  service apache2 restart
