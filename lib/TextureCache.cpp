#include "TextureCache.h"
#include "ProgramState.h"
#include "SDL_image.h"

TextureCache* TextureCache::instance = 0;

TextureCache::TextureCache() {}

TextureCache* TextureCache::getInstance() {
    if (TextureCache::instance == 0) {
        TextureCache::instance = new TextureCache();
    }
    return TextureCache::instance;
}

SDL_Texture* TextureCache::_LoadTexture(const char* filename) {
    SDL_Texture* texture = IMG_LoadTexture(ProgramState::GetRenderer(), filename);
    if (!texture) {
        SDL_Log("Couldn't load %s: %s\n", filename, SDL_GetError());
    }
    return texture;
}

SDL_Texture* TextureCache::getTexture(const char* filename) {
    auto pTexture = _cache.find(filename);
    if (pTexture != _cache.end()) {
        return pTexture->second;
    } else {
        SDL_Texture* texture = _LoadTexture(filename);
        if (texture) {
            _cache[filename] = texture;
        }
        return texture;
    }
}

void TextureCache::Destroy() {
    // Iterate over pairs in the cache and free the textures
    for (auto const& pair : _cache) {
        SDL_DestroyTexture(pair.second);
    }
}

