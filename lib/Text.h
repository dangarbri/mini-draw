#pragma once

#include <string>
#include "Sprite.h"
#include "SDL_ttf.h"

/**
 * Creates text that can be drawn to the screen
 */
class Text : public Sprite {
public:
    /**
     * Constructs a text instance
     *
     * @param[in] fontfile Path to the font to use
     * @param[in] size Font size in points
     * @param[in] text Text to render
     */
    Text(const char* fontfile, int size, std::string text);

    /**
     * Destructor which free's the latest texture
     */
    ~Text();

    /**
     * Ignore this function
     */
    void Update(Uint32 _);

    /**
     * Draws the text to the screen
     */
    void Draw();

    /**
     * Text to render to the screen
     *
     * @param[in] text String to render to the screen
     */
    void SetText(std::string text);

    /**
     * Set the font size of this text
     *
     * @param[in] size Font size in points
     */
    void SetFontSize(int size);

    /**
     * Sets the font's color
     *
     * @param[in] color New color for the text
     */
    void SetColor(SDL_Color color);
private:
    /**
     * The path to the font file
     */
    const char* _fontfile = nullptr;

    /**
     * Loaded font file to use. Does not need to be free'd since it
     * is managed by the FontCache
     */
    TTF_Font* _font = nullptr;

    /**
     * Text as a texture that can be drawn to the screen.
     * Must be free'd in destructor
     */
    SDL_Texture* _texture = nullptr;

    /**
     * The text to be displayed
     */
    std::string _text = "";

    /**
     * The text color, defaults to white
     */
    SDL_Color _color {0xFF, 0xFF, 0xFF, 0xFF};

    /**
     * Builds a texture out of the current state
     */
    void _ConstructTexture();

    /**
     * Frees the last texture
     */
    void _FreeTexture();
};

