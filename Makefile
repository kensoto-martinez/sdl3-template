SRC=src/main.c src/game_functions.c src/config.c
OUTPUT=build/template

all:
	rm -f $(OUTPUT)
	gcc $(SRC) -o $(OUTPUT) -Iinclude -Iinclude/SDL3 -Llib -lSDL3 -lSDL3_ttf -lSDL3_image
	./$(OUTPUT)