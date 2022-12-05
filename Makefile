debug:
	g++ -O3 -g -Wextra -Wall -Isrc/ src/*.cpp -o bin/app -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio
