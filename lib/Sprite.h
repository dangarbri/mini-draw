#pragma once

#include "SDL.h"

/**
 * @page Sprites
 *
 * Sprites are any object in the scene. They all have positions and sizes.
 * These positions and sizes are stored in the Sprite class. Anything
 * that is going to be drawn to the screen should inherit the sprite
 * class so that it gets the common x, y, width, and height parameters
 * along with the GetTargetRect function which will point to a section
 * in the window for the sprite to be rendered to.
 */

/**
 * This interface is used to add certain fields to classes
 * that can be drawn to the screen. Things like scale,
 * position, and transforms that should be applied.
 */
class Sprite {
public:
    /**
     * Width of the sprite's target render box
     */
    int width = 0;

    /**
     * Height of the sprite's target render box
     */
    int height = 0;

    /**
     * The sprite's top left corner X position
     */
    int x = 0;

    /**
     * The sprite's top left corner Y position
     */
    int y = 0;

    /**
     * Scale of the image to make it larger or smaller
     */
    int scale = 1;

    /**
     * Returns the target rectangle to render this sprite to.
     */
    SDL_Rect GetTargetRect();
};
