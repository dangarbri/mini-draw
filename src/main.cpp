/**
 * @mainpage Another Game Attempt
 *
 * @section intro Welcome!
 *
 * This is another one of Daniel's attempts to make a game,
 * but he spent most of his time creating this web page out
 * of code comments
 */

#include "SDL.h"
#include "constants.h"

/**
 * @brief Main event loop
 *
 * Polls and responds to SDL events
 *
 * @param[in] renderer The SDL_Renderer for the window
 * @param[out] done Boolean flag, set to true to signal the program to exit.
 */
void tickFrame(const SDL_Renderer* renderer, SDL_bool* done) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                *done = SDL_TRUE;
                break;
        }
    }
}

/**
 * @brief Program entry point. Initializes SDL and begins the main loop
 *
 * This will initialize SDL, Create the window, and get the window renderer.
 * Then it begins the main event polling loop.
 * Once the exit event occurs, then this destroys the renderer, window, and
 * quits SDL and exits the program.
 */
int main() {
    /* Enable standard application logging */
    SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO);

    SDL_Delay(2000);

    // Initialize SDL
    if(SDL_VideoInit(NULL) == -1) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not initialize SDL video.");
        exit(-2);
    } 
    
    //
    SDL_Window *window = SDL_CreateWindow(GAME_TITLE,
        50, 50,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        0);
    if (window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window: %s\n", SDL_GetError());
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s\n", SDL_GetError());
    }


    SDL_bool done = SDL_FALSE;
    while (!done) {
        tickFrame(renderer, &done);
    }

    if (renderer != NULL) {
        SDL_DestroyRenderer(renderer);
    }
    if (window != NULL) {
        SDL_DestroyWindow(window);
    }
    /* Call SDL_VideoQuit() before quitting. */
    SDL_VideoQuit();
}
