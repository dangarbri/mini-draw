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
#include "ProgramState.h"
#include "Image.h"
#include "TextureCache.h"
#include "app.h"

/**
 * @brief Main event loop
 *
 * Polls and responds to SDL events
 *
 * @param[in] renderer The SDL_Renderer for the window
 * @param[in] app The core app logic handle
 * @param[out] done Boolean flag, set to true to signal the program to exit.
 */
void tickFrame(SDL_Renderer* renderer, App* app, SDL_bool* done) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                *done = SDL_TRUE;
                break;
        }
    }

    SDL_RenderClear(renderer);
    app->OnUpdate(1);
    SDL_RenderPresent(renderer);
}

/**
 * Initializes the program state to be shared among other
 * library classes.
 *
 * @param[in] renderer SDL_Renderer to be used by other classes
 */
void initializeProgramState(SDL_Renderer* renderer) {
    ProgramState::SetRenderer(renderer);
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
    } else {
        SDL_RenderSetLogicalSize(renderer, APP_RESOLUTION_WIDTH, APP_RESOLUTION_HEIGHT);
    }

    // Initialize library classes with shared SDL data.
    initializeProgramState(renderer);

    // Now that libraries have been initialized, begin the app startup code.
    App app;
    app.OnStartup();

    SDL_bool done = SDL_FALSE;
    while (!done) {
        tickFrame(renderer, &app, &done);
    }

    // Shutdown the application code before shutting down SDL.
    app.OnShutdown();

    // Cleanup all cached textures
    TextureCache::getInstance()->Destroy();

    if (renderer != NULL) {
        SDL_DestroyRenderer(renderer);
    }
    if (window != NULL) {
        SDL_DestroyWindow(window);
    }
    /* Call SDL_VideoQuit() before quitting. */
    SDL_VideoQuit();
}
