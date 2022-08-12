#include "AnimatedImage.h"
#include <cassert>

AnimatedImage::AnimatedImage(const char* filename, SDL_Rect first_frame, int num_frames) {
    _num_frames = num_frames;

    for (int i = 0; i < num_frames; i++) {
        // Start at the first frame
        SDL_Rect frame_rect = first_frame;
        // Move x to the right for each frame
        frame_rect.x += frame_rect.w * i;
        _frames.push_back(Image{filename, frame_rect});
    }
}

void AnimatedImage::Draw() {
    // Get the current animation frame
    int frame = _GetTargetFrame();
    // Update the image's sprite info to render it at the right place.
    _UpdateImageSpriteInfo(&_frames[frame]);
    // Draw the frame to the screen
    _frames[frame].Draw();
}

void AnimatedImage::_UpdateImageSpriteInfo(Image* image) {
    // Width and height default to 0 which is unrealistic for
    // an image. So by default don't use them unless the user
    // has changed them to something specific
    if (width != 0) {
        image->SetWidth(GetWidth());
    }
    if (height != 0) {
        image->SetHeight(GetHeight());
    }
    image->SetPosition(GetPosition());
    image->SetScale(GetScale());
}

int AnimatedImage::_GetTargetFrame() {
    return _current_frame;
}

void AnimatedImage::SetFrameDelay(int delay) {
    assert(delay > 0);
    _frame_delay = delay;
}

int AnimatedImage::GetFrameDelay() {
    return _frame_delay;
}

void AnimatedImage::Update(Uint32 dt) {
    static Uint32 timePassed = 0;
    timePassed += dt;
    if (timePassed >= _frame_delay) {
        timePassed -= _frame_delay;
        _current_frame = (_current_frame + 1) % _num_frames;
    }
}

