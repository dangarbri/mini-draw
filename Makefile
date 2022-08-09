SOURCES:=src/main.cpp src/app.cpp lib/Image.cpp lib/ProgramState.cpp
CFLAGS:=$(shell sdl2-config --cflags --libs) $(shell pkg-config SDL2_image --cflags --libs) -Ilib -Isrc
all:
	@mkdir -p bin
	g++ -g $(SOURCES) $(CFLAGS) -o bin/another_game_attempt
