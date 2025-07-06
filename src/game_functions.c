#include "config.h"
#include "game_functions.h"

SDL_FRect render_rect(SDL_Renderer *renderer, int x, int y, int width, int height, SDL_Color color, bool filled) { //put x or y as -1 to center text in that axis
    if (x == -1) {x = WIDTH / 2 - width / 2;}
    if (y == -1) {y = HEIGHT / 2 - height / 2;}

    SDL_FRect rect = {x, y, width, height};
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    //filled meaning the square will be colored in
    if (filled) { 
        SDL_RenderFillRect(renderer, &rect);
    }
    else {
        SDL_RenderRect(renderer, &rect);
    }

    return rect;
}

SDL_FRect render_text(SDL_Renderer *renderer, TTF_Font *font, char *text, int x, int y, SDL_Color color) { //put x or y as -1 to center text in that axis
    SDL_Surface *text_surface = TTF_RenderText_Blended(font, text, 0, color);
    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);

    //text texture dimensions
    float text_width = text_surface->w;
    float text_height = text_surface->h;

    if (x == -1) {x = WIDTH / 2 - text_width / 2;}
    if (y == -1) {y = HEIGHT / 2 - text_height / 2;}

    SDL_FRect destination_rect = {
        (float)x,
        (float)y,
        text_width,
        text_height
    };

    SDL_RenderTexture(renderer, text_texture, NULL, &destination_rect);
    SDL_DestroySurface(text_surface);
    SDL_DestroyTexture(text_texture);

    return destination_rect;
}

SDL_FRect render_texture(SDL_Renderer *renderer, char *file_path, int x, int y, int width, int height) {
    //create texture
    SDL_Texture *texture = IMG_LoadTexture(renderer, file_path);
    if (!texture) {printf("Failed to load texture: %s\n", SDL_GetError()); return (SDL_FRect){0, 0, 0, 0};}

    SDL_FRect destination_rect = {x, y, width, height};
    SDL_RenderTexture(renderer, texture, NULL, &destination_rect);
    SDL_DestroyTexture(texture);

    return destination_rect;
}

bool mouse_in_rect(int mouse_x, int mouse_y, SDL_FRect rect) {
    //if mouse is inside given shape, return true, else return false
    return (mouse_x >= rect.x && mouse_x <= rect.x + rect.w &&
            mouse_y >= rect.y && mouse_y <= rect.y + rect.h);
}