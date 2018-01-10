all:
	gcc -c src/**.cpp
	gcc **.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	rm *.o
