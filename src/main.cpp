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
#include "SDL_ttf.h"
#include "constants.h"
#include "ProgramState.h"
#include "Image.h"
#include "TextureCache.h"
#include "Keyboard.h"
#include "app.h"

/**
 * Handles SDL Keyboard events to update the keyboard state
 * for the running application. 
 */
void handleKeyboardEvent(SDL_Event event) {
    Keyboard* keyboard = Keyboard::getInstance();
    switch (event.type) {
        case SDL_KEYDOWN:
            keyboard->PressKey(event.key.keysym.sym);
            break;
        case SDL_KEYUP:
            keyboard->ReleaseKey(event.key.keysym.sym);
            break;
    }
}

/**
 * Process incoming SDL_Events such as keyboard input
 *
 * @param[out] done Flag is set to true if SDL_QUIT is received
 */
void processEvents(SDL_bool* done) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                *done = SDL_TRUE;
                break;
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                handleKeyboardEvent(event);
                break;
        }
    }
}

/**
 * @brief Main event loop
 *
 * Polls and responds to SDL events
 *
 * @param[in] renderer The SDL_Renderer for the window
 * @param[in] app The core app logic handle
 * @param[out] done Boolean flag, set to true to signal the program to exit.
 */
void tickFrame(SDL_Renderer* renderer, App* app, Uint32 dt, SDL_bool* done) {
    processEvents(done);

    SDL_RenderClear(renderer);
    app->OnUpdate(dt);
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
    SDL_bool init_success = SDL_TRUE;
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
        init_success = SDL_FALSE;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s\n", SDL_GetError());
        init_success = SDL_FALSE;
    } else {
        SDL_RenderSetLogicalSize(renderer, APP_RESOLUTION_WIDTH, APP_RESOLUTION_HEIGHT);
    }

    if (TTF_Init() < 0) {
        SDL_Log("Couldn't initialize TTF: %s\n",SDL_GetError());
        init_success = SDL_FALSE;
    }

    if (init_success) {
        // Initialize library classes with shared SDL data.
        initializeProgramState(renderer);

        // Now that libraries have been initialized, begin the app startup code.
        App app;
        app.OnStartup();

        SDL_bool done = SDL_FALSE;
        Uint32 last_tick = SDL_GetTicks();
        while (!done) {
            // Calculate delta time for each frame
            Uint32 now = SDL_GetTicks();
            Uint32 dt = now - last_tick;
            // Call the frame tick
            tickFrame(renderer, &app, dt, &done);
            // Update last tick time for dt calculation
            last_tick = now;
        }

        // Shutdown the application code before shutting down SDL.
        app.OnShutdown();

        // Cleanup all cached textures
        TextureCache::getInstance()->Destroy();
    }

    // Close font library
    TTF_Quit();

    if (renderer != NULL) {
        SDL_DestroyRenderer(renderer);
    }
    if (window != NULL) {
        SDL_DestroyWindow(window);
    }
    /* Call SDL_VideoQuit() before quitting. */
    SDL_VideoQuit();
}
