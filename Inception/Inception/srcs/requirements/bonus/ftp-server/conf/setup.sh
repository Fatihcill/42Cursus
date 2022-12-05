if [ ! -f "/etc/vsftpd.userlist" ]; then
	#ftp yoksa oluşturuluyor
	mkdir -p /var/run/vsftpd/empty
	mkdir -p /home/fcil

	mv /var/www/vsftpd.conf /etc/vsftpd.conf

	useradd -m -s /bin/bash $FTP_USER
	echo $FTP_USER > /etc/vsftpd.userlist
	echo "$FTP_USER:$FTP_PASSWORD" | /usr/sbin/chpasswd &> /dev/null
	#kullanıcının şifresi güncelleniyor/oluşturuluyor
	chown -R $FTP_USER:$FTP_USER /home/fcil
	#home/fcil klasörü kullanıcıya veriliyor
fi

/usr/sbin/vsftpd /etc/vsftpd.conf
#http://vsftpd.beasts.org/vsftpd_conf.html
#config çalıştırılıyor