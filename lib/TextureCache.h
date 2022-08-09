#pragma once

#include "SDL.h"
#include <map>

/**
 * The texture cache is used to map filenames to textures
 * so that attempting to load the same file multiple times
 * will result in only building one texture.
 */
class TextureCache {
private:
    /**
     * Singleton instance of the TextureCache class
     */
    static TextureCache* instance;

    /**
     * Private constructor so attempting to construct an instance
     * results in a compiler error.
     */
    TextureCache();

    /**
     * The stored mapping of files to textures
     */
    std::map<const char*, SDL_Texture*> _cache;

    /**
     * Loads a texture
     *
     * @param[in] filename Path to image file to load.
     * @returns ptr to SDL_Texture on success, nullptr on failure.
     */
    SDL_Texture* _LoadTexture(const char* filename);

public:
    /**
     * Returns the only instance of the TextureCache
     */
    static TextureCache* getInstance();

    /**
     * Returns a texture created from filename
     *
     * If the file has already been made into a texture, this will
     * be returned from cache. Otherwise, the texture will be created
     * and added to the cache.
     *
     * @param[in] filename The file to create a texture from
     * @returns SDL_Texture* created from the given file.
     */
    SDL_Texture* getTexture(const char* filename);


    /**
     * Frees all the textures stored in the cache. Use this on cleanup.
     */
    void Destroy();
};

