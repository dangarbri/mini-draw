#pragma once

#include "SDL.h"
#include <map>

/**
 * @page Input
 *
 * The most basic input method is via the keyboard. In this framework
 * the keyboard exists as a global singleton that you can access
 * to see which keys are pressed.
 */
class Keyboard {
private:
    /**
     * Singleton instance of the keyboard
     */
    static Keyboard* instance;

    /**
     * Private constructor so no one else can create instances
     */
    Keyboard();

    /**
     * Mapping of keys which stores whether or not they are pressed
     */
    std::map<SDL_KeyCode, SDL_bool> _keys;

public:
    /**
     * Free the keyboard instance
     */
    ~Keyboard();

    /**
     * Returns the keyboard instance
     *
     * @returns Pointer to keyboard instance
     */
    static Keyboard* getInstance();

    /**
     * Checks if a key is pressed
     *
     * @param[in] key Key code to check
     * @returns true if the key is pressed, else false
     */
    SDL_bool IsPressed(SDL_KeyCode key);

    /**
     * Signal that a key is pressed.
     *
     * @note This is used by the framework and should not be called directly
     *
     * @param[in] key Key that is being pressed
     */
    void PressKey(SDL_KeyCode key);

    /**
     * Signal that a key has been released
     *
     * @note This is used by the framework and should not be called directly
     *
     * @param[in] key Key that has been released
     */
    void ReleaseKey(SDL_KeyCode key);
};
