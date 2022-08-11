#include "Sprite.h"

SDL_Rect Sprite::GetTargetRect() {
    return SDL_Rect {x, y, width * scale, height * scale};
}
