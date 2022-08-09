#include "Image.h"
#include "SDL_image.h"

SDL_Renderer* Image::renderer = nullptr;

Image::Image(const char* filename) {
    /* Open the image file */
    texture = IMG_LoadTexture(Image::renderer, filename);
    if (!texture) {
        SDL_Log("Couldn't load %s: %s\n", filename, SDL_GetError());
    } else {
        SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    }
}

Image::~Image() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
}

void Image::SetRenderer(SDL_Renderer* renderer) {
    Image::renderer = renderer;
}

void Image::Draw(int x, int y) {
    SDL_Rect srcRect = _GetRect();
    SDL_Rect targetRect = _GetRect();
    targetRect.x = x;
    targetRect.y = y;
    int result = SDL_RenderCopy(Image::renderer, texture, &srcRect, &targetRect);
    if (result < 0) {
        SDL_Log("Failed to render image: %s\n", SDL_GetError());
    }
}

SDL_Rect Image::_GetRect() {
    return SDL_Rect{0, 0, width, height};
}

