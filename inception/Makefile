all:
	sudo mkdir -p /home/daypark/data/db
	sudo mkdir -p /home/daypark/data/wp
	sudo docker-compose --file ./srcs/docker-compose.yml up --build -d

clean:
	sudo docker-compose --file ./srcs/docker-compose.yml down
	sudo docker rmi -f $$(sudo docker images -q)
	sudo docker volume rm $$(sudo docker volume ls -q)
	sudo docker network rm $$(sudo docker network ls -q)
	sudo rm -rf /home/daypark/data
