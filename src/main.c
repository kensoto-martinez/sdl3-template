#include "config.h"
#include "game_functions.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));
 
    //initialize sdl library
    if (!SDL_Init(SDL_INIT_VIDEO)) {printf("SDL library failed to initialize\n"); return 1;}

    //initialize window
    SDL_Window *window = SDL_CreateWindow(NAME, WIDTH, HEIGHT, SDL_WINDOW_ALWAYS_ON_TOP);
    if (window == NULL) {printf("Window failed to initialize\n"); return 1;}

    //initialize renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL) {printf("Renderer failed to initialize\n"); return 1;}

    //set up window loop
    bool running = true;
    SDL_Event window_event;

    while (running) {
        Uint32 frame_start = SDL_GetTicks();

        //get mouse position
        float mouse_x, mouse_y;
        SDL_GetMouseState(&mouse_x, &mouse_y);

        //handle events
        if (SDL_PollEvent(&window_event)) {
            switch (window_event.type) {
                //user exits window
                case SDL_EVENT_QUIT:
                    running = false;
                    break;
                //keyboard input
                case SDL_EVENT_KEY_DOWN: {
                    switch (window_event.key.scancode) {
                        default:
                            printf("hello world!\n");
                            break;
                    }

                    break;
                }
                //left mouse click down
                case SDL_EVENT_MOUSE_BUTTON_DOWN:
                    printf("wassup world!\n");
                    break;
            }
        }

        //color background and clear it from renders
        SDL_SetRenderDrawColor(renderer, BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, BACKGROUND_COLOR.a);
        SDL_RenderClear(renderer);

        //RENDER HERE


        //RENDER HERE

        //renders present
        SDL_RenderPresent(renderer);

        //delay frame to achieve desired FPS
        Uint32 frame_time = SDL_GetTicks() - frame_start;
        if (frame_time < FRAME_DURATION) {
            SDL_Delay(FRAME_DURATION - frame_time);
        }
    }

    //destroys everything
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}