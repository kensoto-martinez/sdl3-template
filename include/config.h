#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_ttf.h>
#include <SDL3/SDL_image.h>

#define NAME "Template"
#define BACKGROUND_COLOR (SDL_Color){10, 10, 10, 255}
#define WIDTH 450 //pixels
#define HEIGHT 600 //pixels
#define FPS 30
#define FRAME_DURATION (Uint32)1000 / FPS

typedef struct {
    SDL_Color WHITE;
    SDL_Color BLACK;
    SDL_Color YELLOW;
    SDL_Color RED;
    SDL_Color GREEN;
    SDL_Color DARK_GRAY;
    SDL_Color GRAY;
    SDL_Color LIGHT_GRAY;
} SDL_Colors;
extern SDL_Colors COLORS;

#endif