FROM debian:latest
USER root
WORKDIR /root
RUN apt-get update && apt-get install  openssh-server sudo nano curl wget netcat apache2 php php-sqlite3 libapache2-mod-php supervisor subversion -y \
&& groupadd scott \
&& useradd --create-home --home /home/scott --shell /bin/bash --gid scott --groups scott scott \
&& echo 'scott:BIQzG4ay5md4A49egwrMQumaHvQPedr8pIZqVgHf' | chpasswd \
&& echo 'root:HU6M5tDOt2BIQzG4ay5mmaHvQPedr8pIZqVgHf' | chpasswd \
&& mkdir /var/run/sshd \
&& mkdir /app && mkdir /home/scott/.ssh \
&& sed -i.bak s/#Port\ 22/Port\ 3222/g  /etc/ssh/sshd_config \
&& sed -i.bak s/#PasswordAuthentication\ yes/PasswordAuthentication\ no/g  /etc/ssh/sshd_config \
&& touch /home/scott/.ssh/authorized_keys \
&& chown scott:scott /home/scott/.ssh && chown scott:scott /home/scott/.ssh/authorized_keys \
&& mkdir /data \
&& echo "scott ALL=(ALL) NOPASSWD: /bin/nc -lvnp 4444 -e /data/rop" >> /etc/sudoers

COPY /app/apache/000-default.conf /etc/apache2/sites-available/000-default.conf
COPY /app/rop/rop /data/rop
COPY /app/flags/Lettre_Ricky_crypted.txt /root/Lettre_Ricky_crypted.txt
COPY /app/supervisord/supervisord.conf /etc/supervisor/conf.d/supervisord.conf
COPY /app/docker/docker_start.sh /app/docker_start.sh
COPY /app/web/ /var/www/fornum
COPY /app/flags/web.txt /var/www/web.txt
COPY /app/flags/user.txt /home/scott/user.txt
COPY /app/flags/root.txt /root/root.txt
RUN chmod +x /app/docker_start.sh \
&& chmod 555 /data/rop \
&& chown scott:scott /home/scott/user.txt \
&& chmod 400 /home/scott/user.txt

CMD ["/usr/bin/supervisord"]
ENTRYPOINT [ "/app/docker_start.sh" ]