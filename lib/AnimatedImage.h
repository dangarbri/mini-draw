#pragma once

#include "SDL.h"
#include "Sprite.h"
#include "Image.h"
#include <vector>

/**
 * Animated image will loop through a set of sprites
 * to provide an animation. Behaves like an image, but with
 * extra functions for controlling the animation
 */
class AnimatedImage : public Sprite {
public:
    /**
     * Initialize animation with a row in the spritesheet
     * @note This assumes each sprite is the same size and they are placed in a row
     *       in the sprite sheet
     *
     * @param[in] filename Path to the sprite sheet to use
     * @param[in] first_frame Rect which wraps the first frame in the sprite sheet
     * @param[in] num_frames The number of frames in the sprite sheet.
     */
    AnimatedImage(const char* filename, SDL_Rect first_frame, int num_frames);

    /**
     * Frame update
     *
     * @param[in] dt milliseconds since last frame
     */
    void Update(Uint32 dt);

    /**
     * Draws the aniamtions
     */
    void Draw();

    /**
     * Delay between each frame. Use this to control animation speed
     *
     * @param[in] delay_ms Milliseconds to wait before moving to
     *                     the next frame
     */
    void SetFrameDelay(int delay_ms);

    /**
     * Get the frame delay
     *
     * @returns milliseconds between each frame
     */
    int GetFrameDelay();

private:
    /**
     * Stores all images associated with this animation
     */
    std::vector<Image> _frames;

    /**
     * The total number of frames in this animation
     */
    int _num_frames = 0;

    /**
     * The current frame in the animation
     */
    int _current_frame = 0;

    /**
     * Milliseconds to wait between each frame
     */
    int _frame_delay = 250;

    /**
     * Update Image Sprite Info with sprite info applied to this
     * instance
     * 
     * @param[in] image The image to update
     */
    void _UpdateImageSpriteInfo(Image* image);

    /**
     * Gets the frame of the animation to render
     */
    int _GetTargetFrame();
};

