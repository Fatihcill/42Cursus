#!/bin/bash

docker-compose -f srcs/docker-compose.yml down
docker stop $(docker ps -qa) 2>/dev/null
docker rm $(docker ps -qa) 2>/dev/null
docker rmi -f $(docker images -qa) 2>/dev/null
docker volume rm $(docker volume ls -q) 2>/dev/null
docker network rm $(docker network ls -q) 2>/dev/null
docker system prune -a --volume 2>/dev/null
docker system prune -a --force 2>/dev/null
sudo rm -rf /home/fcil/data 2>/dev/null
