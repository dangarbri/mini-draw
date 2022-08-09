all:
	@mkdir -p bin
	g++ src/main.cpp `sdl2-config --cflags --libs` -o bin/another_game_attempt
