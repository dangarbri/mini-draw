#pragma once

/**
 * @page Images
 *
 * You can load images using the Image class.
 * Images are easily loaded by simply constructing the image class
 * with the path to the image that you want to open.
 *
 * When the Image is constructed, it opens the given filename into
 * a texture and stores the width and height of the image.
 *
 * @section Sprite Sheets
 *
 * It's common to have many sprites stored in a single image as
 * a sprite sheet to save memory. This framework supports using
 * sprite sheets as an image source by using the Image class and
 * passing in an SDL_Rect to target a specific rectangle in the
 * sprite sheet.
 *
 * All images are cached, so you can use this method to select
 * multiple images from the sprite sheet and the sprite sheet
 * will only be stored in a single texture in memory.
 */

#include "SDL.h"

/**
 * Represents an image that can be drawn to the screen
 */
class Image {
public:
    /**
     * Creates an image from filename
     */
    Image(const char* filename);

    /**
     * Creates an image from the given file using the given
     * subsection. This can be used to target a specific sprite
     * in a sprite sheet.
     */
    Image(const char* filename, SDL_Rect subsection);

    /**
     * Draws the Image to the screen
     */
    void Draw();

    /**
     * SDL Texture initialized via the constructor
     */
    SDL_Texture *texture = nullptr;

    /**
     * Image width
     */
    int width = 0;

    /**
     * Image height
     */
    int height = 0;

    /**
     * X Position in the window
     */
    int x = 0;

    /**
     * Y Position in the window
     */
    int y = 0;

private:
    /**
     * Targets a specific rectangle in the texture to render.
     * This is used for targeting a single sprite in a sprite sheet.
     */
    SDL_Rect _textureSubMap {0, 0, 1, 1};

    /**
     * Returns an SDL_Rect for the given image.
     *
     * This selects the portion of the image that gets drawn.
     */
    SDL_Rect _GetRect();
};
