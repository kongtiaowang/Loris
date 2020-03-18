FROM php:7.3-apache



# Enable mod_rewrite
RUN a2enmod rewrite

expose 80
expose 443

CMD ["apache2-foreground"]

