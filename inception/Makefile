NAME : inception

all : 
	make -p /home/soo/data/mariadb /home/soo/data/wordpress
	cd ./srcs
	docker compose up --build -d
	cd ..

up:
	cd ./srcs
	docker compose up --build -d
	cd ..

down :
	cd ./srcs
	docker compose down
	cd ..

clean :
	cd ./srcs
	docker compose down
	docker system prune -a
	cd ..

fclean : clean
	rm -rf /home/soo/data/mariadb /home/soo/data/wordpress

re : fclean all

.PHONY : all clean fclean re 