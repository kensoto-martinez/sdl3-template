#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//sdl-specific functions
SDL_FRect render_rect(SDL_Renderer *renderer, int x, int y, int width, int height, SDL_Color color, bool filled);
SDL_FRect render_text(SDL_Renderer *renderer, TTF_Font *font, char *text, int x, int y, SDL_Color color);
SDL_FRect render_texture(SDL_Renderer *renderer, char *file_path, int x, int y, int width, int height);
bool mouse_in_rect(int mouse_x, int mouse_y, SDL_FRect rect);

#endif