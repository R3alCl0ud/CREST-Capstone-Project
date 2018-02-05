all:
	gcc -std=c++11 -stdlib=libc++ -c src/**.cpp
	g++ **.o -o game -lsfml-graphics -lsfml-window -lsfml-system
	rm **.o
objects:
	gcc -std=c++11 -stdlib=libc++ -c src/**.cpp
	g++ **.o -o game -lsfml-graphics -lsfml-window -lsfml-system
