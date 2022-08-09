#pragma once

#include "SDL.h"

/**
 * @page Program State
 * The program state is the way that some SDL specific details are abstracted
 * out of the primary source. It contains things like the SDL Renderer and
 * any other shared SDL object.
 *
 * Other classes will have the program state assigned to them through
 * static calls. This way application code may use the classes without
 * dealing with the underlying SDL objects directly.
 *
 * It is up to the bootstrapper (currently src/main.cpp) to assign a
 * ProgramState instance to the other classes in order for the application
 * to work.
 */

/**
 * Manages the program's state. Stores the app's shared state
 * that is shared among other library classes.
 */
class ProgramState {
public:
    /**
     * Sets the application's SDL_Renderer
     *
     * @param[in] renderer SDL_Renderer for the application's window
     */
    void SetRenderer(const SDL_Renderer* renderer);

    /**
     * Returns the application's SDL_Renderer
     *
     * @returns SDL_Renderer*
     */
    const SDL_Renderer* GetRenderer();

private:
    /**
     * Cached renderer from SetRenderer
     */
    const SDL_Renderer* _renderer;
};
