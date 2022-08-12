#include "Image.h"
#include "TextureCache.h"
#include "ProgramState.h"

Image::Image(const char* filename) {
    /* Open the image file */
    texture = TextureCache::getInstance()->getTexture(filename);
    if (texture) {
        SDL_QueryTexture(texture, NULL, NULL, &width, &height);
        _textureSubMap = SDL_Rect {0, 0, width, height};
    }
}

Image::Image(const char* filename, SDL_Rect subsection) {
    /* Open the image file */
    texture = TextureCache::getInstance()->getTexture(filename);
    _textureSubMap = subsection;
    width = subsection.w;
    height = subsection.h;
}

void Image::Draw() {
    SDL_Rect srcRect = _GetRect();
    SDL_Rect targetRect = GetTargetRect();
    int result = SDL_RenderCopy(ProgramState::GetRenderer(), texture, &srcRect, &targetRect);
    if (result < 0) {
        SDL_Log("Failed to render image: %s\n", SDL_GetError());
    }
}

SDL_Rect Image::_GetRect() {
    return _textureSubMap;
}

void Image::Update(Uint32 dt) {}

