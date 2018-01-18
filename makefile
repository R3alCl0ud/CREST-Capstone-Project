all:
	g++ -std=c++11 -stdlib=libc++ -c src/**.cpp 
	g++ **.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -v
	rm **.o
