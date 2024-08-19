## Part 1. Готовый докер
- скачиваем докер
![1.png](/src/screenshots/1.PNG)
![1_1.png](/src/screenshots/1_1.PNG)
- Взять официальный докер образ с **nginx** и выкачать его при помощи `docker pull`
![2.png](/src/screenshots/2.PNG)
- Проверить наличие докер образа через `docker images`
![3.png](/src/screenshots/3.PNG)
- Запустить докер образ через `docker run -d [image_id|repository]`
![4.png](/src/screenshots/4.PNG)
- Проверить, что образ запустился через `docker ps`
![5.png](/src/screenshots/5.PNG)
- Посмотреть информацию о контейнере через `docker inspect [container_id|container_name]`
![6.png](/src/screenshots/6.PNG)
- По выводу команды определить и поместить в отчёт размер контейнера, список замапленных портов и ip контейнера
`-` Размер контейнера

![size](/src/screenshots/size.png)

`-` Список замапленных портов

![port](/src/screenshots/ports.png)

`-` IP контейнера 

![ip](/src/screenshots/ip.png)
- Остановить докер образ через `docker stop [container_id|container_name]`
![stop.png](/src/screenshots/stop.PNG)
- Проверить, что образ остановился через `docker ps`
![stop_ps.png](/src/screenshots/stop_ps.PNG)
- Запустить докер с портами 80 и 443 в контейнере, замапленными на такие же порты на локальной машине, через команду *run*
![run.png](/src/screenshots/run.PNG)
- Проверить, что в браузере по адресу *localhost:80* доступна стартовая страница **nginx**
![local80.png](/src/screenshots/local80.PNG)
- Перезапустить докер контейнер через `docker restart [container_id|container_name]`
![restart.png](/src/screenshots/restart.PNG)
- Проверить любым способом, что контейнер запустился
![restartps.png](/src/screenshots/restartps.PNG)

## Part 2. Операции с контейнером

##### Прочитать конфигурационный файл nginx.conf внутри докер контейнера через команду exec

![exec](/src/screenshots/exec.png)

##### Создать на локальной машине файл nginx.conf. Настроить в нем по пути /status отдачу страницы статуса сервера nginx

![nginx](/src/screenshots/nginx.png)

##### Скопировать созданный файл nginx.conf внутрь докер образа через команду `docker cp`

![cp](/src/screenshots/cp.png)

##### Перезапустить nginx внутри докер образа через команду exec

![reload](/src/screenshots/reload.png)

##### Проверить, что по адресу `localhost:80/status` отдается страничка со статусом сервера nginx

![status](/src/screenshots/status.png)

##### Экспортировать контейнер в файл container.tar через команду export

![export](/src/screenshots/export.png)

(91d8e17fcf3b - container id)

##### Остановить контейнер

![stop_1](/src/screenshots/stop_1.png)

##### Удалить образ через `docker rmi [image_id|repository]`, не удаляя перед этим контейнеры

![rmi](/src/screenshots/rmi.png)

##### Удалить остановленный контейнер

![rm](/src/screenshots/rm.png)

##### Импортировать контейнер обратно через команду import

![import](/src/screenshots/import.png)

##### Запустить импортированный контейнер

![run_1](/src/screenshots/run_1.png)

##### Проверить, что по адресу localhost:80/status отдается страничка со статусом сервера nginx

![status_1](/src/screenshots/status_1.png)

## Part 3. Мини веб-сервер

##### Написать мини сервер на C и FastCgi, который будет возвращать простейшую страничку с надписью Hello World!

![server](/src/screenshots/server.png)

*Функция `FCGI_Accept()` дает доступ новому запросу из HTML сервиса и создает CGI-совместимую среду выполнения для запроса*

*Заголовок `Content-Type` используется для указания исходного media-type ресурса (до любого кодирования содержимого, применяемого для отправки).*
*`Content-Type = "Content-Type:" media-type NL`*

*`media-type` — это строка, отправляемая вместе с файлом, указывающая тип файла (описывающий формат содержимого, например, звуковой файл может быть помечен как audio/ogg, или файл изображения image/png)*

*`text/html` сообщает о том, что нам нужет медиа-тип текст*

*`\r` - перенос каретки в начало строки*

##### Написать свой nginx.conf, который будет проксировать все запросы с 81 порта на 127.0.0.1:8080

![nginx_1](/src/screenshots/nginx_1.png)

*`fastcgi_pass` задаёт адрес FastCGI-сервера. Адрес может быть указан в виде доменного имени IP-адреса и порта*

##### Запустить написанный мини сервер через spawn-fcgi на порту 8080

Запускаем контейнер с портом 81:

![run_2](/src/screenshots/run_2.png)

Копируем новый nginx.conf в /etc/nginx и перезапускаем его

![cp_reload](/src/screenshots/cp_reload.png)

Скопируем программу для запуска сервера, чтобы запустить его из контейнера

`$ docker cp ../server/server.c dazzling_edison:/home`

Далее подключаемся к контейнеру с провами root и проделываем все необходимые манипуляции

`$ docker exec -it --user root dazzling_edison /bin/bash`

Обновляем систему

`apt-get update`

Для запуска server.c через apt-get нужно установить gcc, spawn-fcgi и libfcgi-dev

`$ apt-get install gcc`

`$ apt-get install spawn-fcgi`

`$ apt-get install libfcgi-dev`

Компиляция server.c

`$ gcc server.c -lfcgi`

Запуск fcgi сервера на порту 8080

![fcgi](/src/screenshots/fcgi.png)

*`spawn-fcgi` используется для запуска удаленных и локальных FastCGI процессов.*

##### Проверить, что в браузере по localhost:81 отдается написанная вами страничка

![HI](/src/screenshots/HI.png)

##### Положить файл nginx.conf по пути ./nginx/nginx.conf (это понадобится позже)

## Part 4. Свой докер

#### Написать свой докер образ, который:
##### 1) собирает исходники мини сервера на FastCgi из Части 3
##### 2) запускает его на 8080 порту
##### 3) копирует внутрь образа написанный ./nginx/nginx.conf
##### 4) запускает nginx.

##### Дописать в ./nginx/nginx.conf проксирование странички /status, по которой надо отдавать статус сервера nginx

![nginx_conf](/src/screenshots/nginx_conf.png)

nginx можно установить внутрь докера самостоятельно, а можно воспользоваться готовым образом с nginx'ом, как базовым.

##### Собрать написанный докер образ через docker build при этом указав имя и тег

![start](/src/screenshots/start.png)

##### Проверить через docker images, что все собралось корректно

![images](/src/screenshots/images.png)

##### Запустить собранный докер образ с маппингом 81 порта на 80 на локальной машине и маппингом папки ./nginx внутрь контейнера по адресу, где лежат конфигурационные файлы nginx'а (см. Часть 2). 

![run_3](/src/screenshots/run_3.png)

##### Проверить, что по localhost:80 доступна страничка написанного мини сервера

![local_2](/src/screenshots/local_2.png)

##### Перезапустить докер образ
Если всё сделано верно, то, после сохранения файла и перезапуска контейнера, конфигурационный файл внутри докер образа должен обновиться самостоятельно без лишних действий

##### Проверить, что теперь по localhost:80/status отдается страничка со статусом nginx

![local_3](/src/screenshots/local_3.png)

## Part 5. Dockle

Устанавливаем dockle с помощью следующей команды:

![dockle_install](/src/screenshots/dockle_install.png)

##### Просканировать образ из предыдущего задания через `dockle [image_id|repository]`

![before](/src/screenshots/before.png)

##### Исправить образ так, чтобы при проверке через dockle не было ошибок и предупреждений

![after](/src/screenshots/after.png)

Для того, чтобы все работало, понадобилось запушить образ в докер хаб, иначе dockle не мог его найти и выдавал ошибку

## Part 6. Базовый Docker Compose

##### Написать файл docker-compose.yml, с помощью которого

1) Поднять докер контейнер из Части 5 (он должен работать в локальной сети, т.е. не нужно использовать инструкцию EXPOSE и мапить порты на локальную машину)

2) Поднять докер контейнер с nginx, который будет проксировать все запросы с 8080 порта на 81 порт первого контейнера

##### Замапить 8080 порт второго контейнера на 80 порт локальной машины

Изменения в nginx.conf

![nginx_2](/src/screenshots/nginx_2.png)

##### Остановить все запущенные контейнеры

##### Собрать и запустить проект с помощью команд `docker-compose build` и `docker-compose up`

![build](/src/screenshots/build.png)

![up](/src/screenshots/up.png)

##### Проверить, что в браузере по localhost:80 отдается написанная вами страничка, как и ранее

![local_4](/src/screenshots/local_4.png)

