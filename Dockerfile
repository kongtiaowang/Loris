FROM php:8.1-apache


WORKDIR /var/www/html


# Install Git
RUN apt-get update && apt-get install -y git

# copy source code into /var/www/html/loris
COPY . /var/www/html/loris

# Copy Apache configuration
COPY ./docs/config/apache2-site /etc/apache2/sites-available/000-default.conf


# Replace placeholders in the Apache configuration
RUN sed -ri -e 's#%LORISROOT%#/var/www/html/loris#g' /etc/apache2/sites-available/000-default.conf
RUN sed -ri -e 's#%LOGDIRECTORY%#./#g' /etc/apache2/sites-available/000-default.conf

WORKDIR /var/www/html/loris

# Create the smarty/templates_c directory if it doesn't exist
RUN if [ ! -d "smarty/templates_c" ]; then mkdir -p smarty/templates_c; fi

# Set permissions for the smarty/templates_c directory
RUN chown -R www-data:www-data smarty/templates_c
RUN chmod 777 smarty/templates_c


# Create the log directory and touch the error log file
RUN touch /var/www/html/loris/loris-error.log

# Install required packages
RUN apt-get install -y mariadb-client libzip-dev && \
    docker-php-ext-install pdo_mysql zip

# Install Node.js and npm
RUN curl -fsSL https://deb.nodesource.com/setup_18.x | bash - && \
    apt-get install -y nodejs


# Run npm install and npm run compile
RUN npm install
RUN npm run compile

# Install Composer and run composer install --no-dev
RUN curl -sS https://getcomposer.org/installer | php -- --install-dir=/usr/local/bin --filename=composer
RUN composer install --no-dev

# Enable Apache modules and restart Apache
RUN a2enmod rewrite && \
    service apache2 restart

# Expose port 80 for Apache
EXPOSE 80

