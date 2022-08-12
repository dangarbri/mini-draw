#pragma once

/**
 * @defgroup AppBuilder App Builder
 *
 * The App Builder modules are a collection of source files that
 * can be "drag and dropped" into any application. It contains
 * utility functions that are common in many games, such as
 * keyboard movement.
 */

#include "Keyboard.h"
#include "Sprite.h"

/**
 * WASDMovement is an implementation for keyboard movement
 * that can be used as-is in any application. Simply attach
 * a Sprite for the instance to control and add a call to Update
 * in your App's OnUpdate function
 */
class WASDMovement {
public:
    /**
     * Constructs a movement controller to move the given sprite.
     *
     * @param[in] target The sprite to move
     */
    WASDMovement(Sprite* target);

    /**
     * Constructs a movement controller to move the given sprite.
     *
     * @param[in] target The sprite to move
     * @param[in] speed Movement speed in pixels/second
     */
    WASDMovement(Sprite* target, float speed);

    /**
     * Frame update function
     *
     * @param[in] dt Milliseconds since last frame
     */
    void Update(Uint32 dt);

    /**
     * Disable movement. Keys will be ignored when disabled
     */
    void Disable();

    /**
     * Enable movement, Movement will be handled when wasd keys are pressed
     */
    void Enable();

    /**
     * @returns SDL_bool The current enabled state
     */
    SDL_bool IsEnabled();

    /**
     * Movement speed in pixels/second
     */
    float speed = 80;

private:
    /**
     * The sprite that this controller will move
     */
    Sprite* _sprite = nullptr;

    /**
     * Current enabled state
     */
    SDL_bool _enabled = SDL_TRUE;

    /**
     * Keyboard instance for checking that keys are pressed.
     */
    Keyboard* _keyboard;

    /**
     * Handles the Update function when _enabled is true
     *
     * @param[in] dt Milliseconds since last frame
     */
    void _ProcessUpdate(Uint32 dt);
};

