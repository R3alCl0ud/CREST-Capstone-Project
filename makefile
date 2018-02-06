CC=gcc
LN=g++ **.o -o game -lsfml-graphics -lsfml-window -lsfml-system
CFLAGS=-std=c++11 -stdlib=libc++ -c

all:
	#SRC_FILES := $(wildcard src/*.cpp)
	#SRC_FILES := $(filter-out src/test.cpp, $(SRC_FILES))
	${CC} ${CFLAGS} src/*.cpp
	${LN}
	rm **.o
#objects:
	#${CC} ${CFLAGS} src/**.cpp
	#${LN}
#debug:
#	$(info Compiling to debug target)
#	SRC_FILES := $(wildcard src/*.cpp)
	#SRC_FILES := $(filter-out src/main.cpp, $(SRC_FILES))
	#${CC} ${CFLAGS} ${SRC_FILES}
	#${LN}
