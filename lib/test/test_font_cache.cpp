#include "FontCache.h"
#include "SDL_ttf.h"
#include <cassert>

int main() {
    TTF_Init();
    FontCache* cache = FontCache::getInstance();
    // Load a font
    TTF_Font* font = cache->GetFont("assets/test_font.ttf", 12);
    assert(font != NULL);
    // Free the font
    cache->Destroy();
    TTF_Quit();
}

