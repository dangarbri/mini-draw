#pragma once

#include "SDL.h"
#include "Coordinates.h"

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
     * Draws the sprite to the screen
     */
    virtual void Draw() = 0;

    /**
     * Returns the target rectangle to render this sprite to.
     */
    SDL_Rect GetTargetRect();

    /**
     * Gets the coordinates of where the sprite is being rendered
     */
    Coordinates GetPosition();

    /**
     * Sets the coordinates for where to render the sprite
     *
     * @param[in] x horizontal position
     * @param[in] y vertical position
     */
    void SetPosition(int x, int y);

    /**
     * Sets the coordinates for where to render the sprite
     *
     * @param[in] position Position coordinates
     */
    void SetPosition(Coordinates position);

    /**
     * Set the sprite width
     *
     * @param[in] width New sprite width
     */
    void SetWidth(int width);

    /**
     * Gets the sprite's width
     */
    int GetWidth();

    /**
     * Set the sprite height 
     *
     * @param[in] height New sprite height 
     */
    void SetHeight(int height);

    /**
     * Gets the sprite's height
     */
    int GetHeight();

    /**
     * Gets the sprite's scale
     */
    int GetScale();

    /**
     * Sets the sprite's scale
     *
     * @param[in] scale New sprite scale
     */
    void SetScale(int scale);

protected:
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
};
