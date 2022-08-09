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
     * Image destructor, frees the stored texture.
     */
    ~Image();

    /**
     * Sets the Image Renderer to be used to load images
     */
    static void SetRenderer(SDL_Renderer* renderer);

    /**
     * Draws the Image to the given coordinates in the window
     */
    void Draw(int x, int y);

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

private:
    /**
     * The program's renderer retrieved from the window
     */
    static SDL_Renderer* renderer;

    /**
     * Returns an SDL_Rect for the given image.
     *
     * This selects the portion of the image that gets drawn.
     */
    SDL_Rect _GetRect();
};
