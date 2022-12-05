CREATE DATABASE Base;
CREATE USER 'fcil'@'%' IDENTIFIED BY '123'; -- fcil adında 123 şifreli kullanıcı oluşturur
GRANT ALL PRIVILEGES ON Base.* TO 'fcil'@'%'; --tüm izinleri fcile verir
FLUSH PRIVILEGES; --izinler tablosunu günceller

ALTER USER 'root'@'localhost' IDENTIFIED BY '123123'; --User tablosunu düzenler root u ekler
