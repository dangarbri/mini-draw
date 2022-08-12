#pragma once

#include "SDL.h"
#include "SDL_ttf.h"
#include <map>

/**
 * The font cache is used to cache open fonts
 * so that attempting to load the same font
 * will result in sharing the font asset to save memory.
 *
 * @note All operations assume you have already called TTF_Init
 */
class FontCache {
private:
    /**
     * Singleton instance of the TextureCache class
     */
    static FontCache* instance;

    /**
     * Private constructor so attempting to construct an instance
     * results in a compiler error.
     */
    FontCache();

    /**
     * The stored mapping of files to size to texture
     * Fonts are cached based on their file and font size
     */
    std::map<const char*, std::map<int, TTF_Font*>> _cache;

    /**
     * Loads a Font
     *
     * @param[in] filename Path to image file to load.
     * @returns ptr to SDL_Texture on success, nullptr on failure.
     */
    TTF_Font* _LoadFont(const char* filename, int size);

public:
    /**
     * Returns the only instance of the TextureCache
     */
    static FontCache* getInstance();

    /**
     * Returns a font created from filename and font size
     *
     * If the font has already been cached, this will
     * be returned from cache. Otherwise, the font will be created
     * and added to the cache.
     *
     * @param[in] filename The TTF font file
     * @param[in] size Font size to use in points
     * @returns TTF_Font* created as specified.
     */
    TTF_Font* GetFont(const char* filename, int size);


    /**
     * Frees all the fonts stored in the cache. Use this on cleanup.
     */
    void Destroy();
};

