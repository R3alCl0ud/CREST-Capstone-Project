all:
	gcc -c src/**.cpp
	g++ **.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -v
	rm **.o

something:
