# DOCKER NOTLARI:


> - `docker info:`
	<p>Docker üzerinde Mevcut işletim sistemi hakkında bilgiler verir.</p>

> - `docker search [image_name]`
	<p>verilen isimdeki tüm image leri sıralar</p>

> - `docker pull [image_name]`
	<p>verilen isimdeki image indirilir</p>

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

> - `docker container port [container_id]`
	<p>verilen id deki portu gösterir</p>

## DOCKER FILE:
Docker Image lar işletim sisteminde var olan tüm bilgiler bulunur ve Dockerfile Image oluşturmak için oluşturduğumuz bir dosyadır.
> - `DOCKER FILE KOMUTLARI`
	<p> 
	FROM -> base image mizi göstermek için oluşturuluşmuş komuttur.
		<pre>FROM centos:7</pre>
	LABEL -> isimlendirme yapmaya yarar
		<pre>LABEL key value</pre>
	EXPOSE -> containerımızın hangi port üzerinden yayın yapacağını belirtmemize yarar
		<pre>- EXPOSE 80/TCP </pre>
	RUN -> base image kurulduktan sonra çalıştırılacak komutlar.
		<pre>
		- RUN yum -y update
		- RUN yum -y install nano
		</pre>
	CMD -> docker container ayağa kalktığında verilen komutu çalıştırır
		<pre>- CMD ping -c 10 127.0.0.1</pre>
	ENV	-> container ortam değişkeni tanımlamamıza yarar.<br><br>
	ADD -> local veya online dan veya env den containerımıza dosya kopyalamamıza yarar
		<pre>- ADD /bin/xyz /xyz</pre>
	VOLUME -> containerda ki datalarımın silinmesini istemiyorsak
		<pre>- VOLUME /MOUNT</pre>
	WORKDIR -> container çalışmaya başladığında nerede çalışmaya başlaması gerektiğini belirliyoruz.
		<pre>- WORKDIR /www/html</pre>
	MKDIR -> Klasör oluşturmamıza yarar<br><br>
	Örnek;
		<pre>`FROM ubuntu`
		`RUN apt-get -y update`
		`RUN apt-get -y upgrade`
		`RUN apt-get -y install python3 python3-pip`
		`COPY . /app`
		`WORKDIR /app`
		`EXPOSE 5000`
		</pre></p>


> - `docker images`
	<p>docker da varolan imagelerimizi gösterir</p>

> - `docker image build -t [name] .`
	<p>docker file ile name adında bir image oluşturur</p>
	
> - `docker container run -d -P [name]`
	<p>name adında ki image miz ile container kurar.<br>
	-P -> EXPOSE ile port belirttiğimizde bu portu alması için bu arguman kullanılır<br>
	-v -> Volume ataması yapmamıza yarar</p>

## DOCKER Multi-Stage:
- Dockerfile da ki verimsizlikleri ortadan kaldırır.
- Boyut açısından yüksek boyutlu imagelar ile çalışmak zorunda kalmayız.

## DOCKER PLUGIN:
docker enginenin özelliklerini genişletmek için kullanılır.
> - `docker plugin install [plugin_name]`
	<p>verilen isimde ki plugin yüklenir.</p>

> - `docker plugin ls`
	<p>yüklenilen pluginleri listeler</p>

> - `docker plugin disable/enable [plugin_name]`
	<p>verilen isimdeki plugini aktif veya deaktif eder.</p>

> - `docker plugin rm [plugin_name]`
	<p>verilen isimdeki plugini kaldırır.</p>

## DOCKER Repostories:

> - `docker login`
	<p>docker hub profilimiz ile docker arasında bağlantı kurmak için yapılır</p>

> - `docker push`
	<p>localde oluşturduğum imageleri repomuza göndermemize yarar</p>

> - `docker login`
	<p>docker hub profilimiz ile docker arasında bağlantı kurmak için yapılır</p>

> - `docker push`
	<p>localde oluşturduğum imageleri repomuza göndermemize yarar</p>

## DOCKER Volume:
- Container silinse dahi içerisindeki dataları tutmak için volume kullanırız.
- Docker volume içerisindeki datalar birden fazla container kullanabilir.
- Docker Image güncellemesi yapılsa dahi volume içerisindeki datalar değişmez
- Docker volume içerisindeki datalar taşınabilir ve yedeklenebilir.
- Docker volumes container boyutunu artırmaz.

bir volume oluşturulduğunda (Docker Root Dir) de gözükür (bknz. docker info)

> - `docker volume create --name test1`
	<p>test1 adında bir volume oluşturulur.

> - `docker container run -it -v test1:/www/website centos:7 bash`
	<p>örnek kullanım.<br>
	test1: volumemizin oluştulacağı path <br>
	test1:/www/website:ro <br>
	ro -> readonly şeklinde de oluşturabiliriz</p>
> - `docker volume inspect [name]`
	<p>verilen volume ismi hakkında bilgiler verir</p>
> - `docker volume ls`
	<p>docker volume ları listeler</p>

Docker Volume da External Stroge kurabilmek için ilk olarak nfs alanlar kullanabiliriz. 
> - `docker volume create --opt type=nfs --opt o=addr=192.168.1.10,rw,nfsserver4 --opt device=:/home/nfsshare nfs-volume`
	<p>opt -> özellik belirlemeye yarar
		<pre>type -> dosya sistemimizi nfs olarak ayarlıyoruz
		o=addr -> dışarıdan erişmek için bir adres veriyoruz
		,rw -> read write 
		,nfsserver4 -> verilen adresin nfsserver4 kullanmasını istiyoruz
		device -> fileshare'nin konumu neresi bunu belirliyoruz</pre></p>

> - `docker rm [name]`
	<p>volume silmek için öncelikle o volumeyi kullanan containerları silemeliyiz.
	verilen isimdeki volume silinir.</p>

## DOCKER Network:
### CNM(Container Network Model)
- Aynı ağ üzerindeki containerların birbiri ile iletişim kurmasını sağlar.
- Çoklu network trafiğinin bölümlere ayrılmasını sağlar.
- Containerların birden fazla ağa eklenmesini sağlar

![plot](Container-Networking-Model.png)
- Network Sandbox -> Container yönetim arayüzü, ip, mac adresleri ayarlamaları yapılır.
- Endpoint -> Sandbox'ın dış networke bağlanmasını sağlar. ikinci bir network'e bağlanmak için ikinci bir endpoint oluşturulabilinir
- Network -> birbiri ile iletişim kuran endpointler temsil edilir.
- Driver -> ağın sahibidir, çeşitli kullanım durumlarında dağıtım sürümünü karşılamak için burayı kullanırız, ağın yöneticisi diyebiliriz.

> - `docker network ls`
	<p>bütün networkleri görüntülememizi sağlar.</p>
> - `docker network inspect [name]`
	<p>verilen isimdeki network hakkında detayları görüntülememizi sağlar</p>
> - `docker run centos /usr/sbin/ip route`
	<p>verilen isimdeki network hakkında detayları görüntülememizi sağlar</p>
> - `docker network create test1network`
	<p>test1network adında bir network oluşturur</p>
> - `docker container run -it --net test1network centos bash`
	<p>oluşturulan container test1network üne eklenir</p>
> - `docker network create --subnet 192.168.100.0/24 --gateway 192.168.100.1 --driver [bridge/host/null] test2network`
	<p>--subnet -> belli bir subnet verir<br>
	--gateway -> gateway belirlememize yarar<br>
	--driver -> nasıl bir türde driver belirleyeceğimize yarar bridge/host/null</p>
> - `docker network rm test1`
	<p>test1 networkünü silir, silinmesi için networkün kullanılmaması gerekir</p>
> - `docker network create -d macvlan --subnet=192.168.0.0/24 --gateway 192.168.0.1 -o parent=eth0 macvlan-mynet`
	<p>--subnet -> belli bir subnet verir<br>
	--gateway -> gateway belirlememize yarar<br>
	fiziksel ağa bu şekilde ağımızı bağlayabiliriz.</p>

## Docker Compose

- Docker compose çok container lı yapıları çalıştırmak ve hızlı şekilde publish etmek için kullanılan bir docker özelliğidir. Kompleks uygulamalar geliştirirken comtainerların bağımsız şekilde ilerlemesini istediğimizde bu özelliği kullanabiliriz. 
- .yml dosyaları ile tüm hizmetleri başlatabiliriz, dockerfile gibidir ancak docker compose versiyonuna göre bir containerımda hangi özellikleri başlatacağımı hızlı bir şekilde hazırlamamıza yarar.

> - `docker compose --version`
<p> mevcut docker compose'un versiyonunu gösterir</p>

> - `docker-compose build\up`
<p>build veya up aynı işlevdedir, up komutu verildiğinde build edilmediyse ilk olarak build edilmiş olunur ve servisi ayağa kaldırır.</p>

> - `docker-compose down`
<p>compose tarafından yaratılan containerları sistemden kaldırır. parametreler ile volume vs. kaldırılabilinir.</p>

> - `docker-compose ps`
<p>servislerin çıktısını gösterir. </p>

> - `docker-compose run`
<p>compose tarafından oluşturulan bir servis için ilgili aksiyonu almamıza yarar.</p>

> - `docker-compose exec [command]`
<p>çalışmakta olan containerda bir execute çalıştırır</p>

> - `DOCKER COMPOSE KOMUTLARI`
	<p> 
	version -> ilk stepde versiyon bilgisi verilmeli. 
		<pre> version "2.6"</pre>
	services: -> servis yapılandırılmasını sağlar
		<pre>
		services:
				<pre>nginx-service:
				build: ./Website
				depends_on:
				- ruby-service
				</pre>
		</pre>
		depends_on: servisleri birbirine bağlar.<br>
		build: docker file pathini veririz</p>


