all:
		@sudo mkdir -p /home/fcil/data/db
		@sudo mkdir -p /home/fcil/data/wp
		@sudo mkdir -p /home/fcil/data/prt
		@docker-compose -f srcs/docker-compose.yml up --build -d
		@sudo make up
up:
		@sudo mkdir -p /home/fcil/data/db
		@sudo mkdir -p /home/fcil/data/wp
		@sudo mkdir -p /home/fcil/data/prt
		@docker-compose -f srcs/docker-compose.yml up -d

down:
		@docker-compose -f srcs/docker-compose.yml down

clean:
		@chmod 744 clean.sh
		@./clean.sh

info:
		@echo "=============================== IMAGES ==============================="
		@docker images
		@echo
		@echo "============================= CONTAINERS ============================="
		@docker ps -a
		@echo
		@echo "=============== NETWORKS ==============="
		@docker network ls
		@echo
		@echo "====== VOLUMES ======"
		@docker volume ls

.PHONY:	all up down clean info
