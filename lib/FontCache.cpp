#include "FontCache.h"

FontCache* FontCache::instance = 0;

FontCache::FontCache() {}

FontCache* FontCache::getInstance() {
    if (FontCache::instance == 0) {
        FontCache::instance = new FontCache();
    }
    return FontCache::instance;
}

TTF_Font* FontCache::_LoadFont(const char* filename, int size) {
    TTF_Font* font = TTF_OpenFont(filename, size);
    if (font == NULL) {
        SDL_Log("Couldn't load %s: %s\n", filename, SDL_GetError());
    }
    return font;
}

TTF_Font* FontCache::GetFont(const char* filename, int size) {
    auto pFontSizes = _cache.find(filename);
    if (pFontSizes != _cache.end()) {
        auto size_cache = pFontSizes->second;
        auto pFont = size_cache.find(size);
        if (pFont != size_cache.end()) {
            return pFont->second;
        }
    } 
    // If font wasn't found above, load it here.
    TTF_Font* font = _LoadFont(filename, size);
    if (font) {
        _cache[filename][size] = font;
    }
    return font;
}

void FontCache::Destroy() {
    // Iterate over pairs in the cache and free the textures
    for (auto const& fonts : _cache) {
        for (auto const& size : fonts.second) {
            TTF_CloseFont(size.second);
        }
    }
}

