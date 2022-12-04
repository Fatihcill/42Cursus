# Temel Komutlar:


> - `docker info:`
	<p>Docker üzerinde Mevcut işletim sistemi hakkında bilgiler verir.</p>


> - `docker ps -a | docker container ls -a`
	<p>ortamımızda çalışan tüm containerları gösterir.<br>
	-a -> exit mode daki containerları da gösterir.<br>
	--no-trunc -> detaylı olarak container_id lerimizi görmemize yarar<br>
	-q -> sadece kısa id'leri verir</p>

> - `docker run op:v`
	<p>op -> seçeceğimiz linux image dosyası <br>
	v -> versiyon<br>
	example : docker run centos:7 <br></p>

> - `docker container run -it op:v bash`
	<p>container a direkt olarak bağlanıp üzerinde işlemler yapmamızı sağlar.<br>
	-it -> interactive connection<br>
	bash -> bash ile bağlanacağımızı söylüyoruz<br>
	container içerisinde;<br>
			> exit ile çıktığımızda container ımız exit mode düşer bu yüzden ctrl+alt+q gibi kombinasyonlar ile çıkmamız gerekir. <br></p>

> - `docker container start [container_id]`
	<p>verdiğimiz id deki containerı exit modedan çıkarır<br>
	-a -> direkt attach mode da çalıştırır<br></p>

> - `docker container exec -it [container_id] bash`
	<p>verdiğimiz id ye bash ve -it mode da yeniden bağlanıyoruz</p>

> - `docker container logs [container_id]`
	<p>ilgili id deki yapılan process hakkında logları görüntülememizi sağlar<br>
	-f -> canlı olarak logları izler<br></p>

> - `docker container attach [container_id]`
	<p>id deki kontainera direkt bağlantı yapmamızı sağlar</p>

> - `docker container stop [container_id]`
	<p>ilgili container id yi durdurmamıza yarar (exit mode alır)</p>

> - `docker container kill [container_id]`
	<p>ilgili id yi kill eder direkt kapatır </p>

> - `docker container inspect [container_id]`
	<p>container hakkında tüm detayları verir, özellikle config kısmında temel yapılandırma ayarlarının tümü gözükür.</p>

> - `docker container rm [container_id]`
	<p>verilen container silinir.</p>

## PORT:
> - `docker run -d -p 5000:80`
	<p>-p -> port mapping yapmamızı sağlar (5000 host portu) (80 tcp portu)</p>

> - `docker container port [id]`
	<p>id deki portu gösterir</p>

## DOCKER FILE:
bizim image oluşturmak için oluşturduğumuz bir dosyadır.
> - `docker image build -t [name] .`
	<p>docker file ile name adında bir image oluşturur</p>
> - `docker container run -d -P [name]`
	<p>name adında ki image miz ile container kurar.<br>
	-P -> EXPOSE ile port belirttiğimizde bu portu alması için bu arguman kullanılır</p>

## DOCKER PLUGIN:
docker enginenin özelliklerini genişletmek için kullanılır.
> - `docker plugin install [plugin name]`
	<p>verilen isimde ki plugin yüklenir.</p>

> - `docker plugin ls`
	<p>yüklenilen pluginleri listeler</p>

> - `docker plugin disable/enable [name]`
	<p>verilen isimdeki plugini aktif veya deaktif eder.</p>

> - `docker plugin rm [name]`
	<p>verilen isimdeki plugini kaldırır.</p>


