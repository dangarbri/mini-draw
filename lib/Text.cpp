#include "Text.h"
#include "FontCache.h"
#include "TextureCache.h"
#include "ProgramState.h"

Text::Text(const char* fontfile, int size, std::string text) {
    // Store the fontfile
    _fontfile = fontfile;
    // Store initial text
    _text = text;
    // Create the ttf font fron the size and fontfile
    _font = FontCache::getInstance()->GetFont(fontfile, size);
    // Build the texture out of these details
    _ConstructTexture();
}

// Update does nothing for the Text instance
void Text::Update(Uint32 _) {}

void Text::Draw() {
    if (_text != "") {
        SDL_Rect target = GetTargetRect();
        SDL_RenderCopy(ProgramState::GetRenderer(), _texture, NULL, &target);
    }
}

void Text::_ConstructTexture() {
    // Free the current texture before constructing the new one
    _FreeTexture();

    // Render the text into a surface
    SDL_Surface* surface = TTF_RenderText_Blended(_font, _text.c_str(), _color);
    // Set rect from generated surface
    width = surface->w;
    height = surface->h;
    // Create a texture from the surface
    _texture = SDL_CreateTextureFromSurface(ProgramState::GetRenderer(), surface);
    // Free the surface
    SDL_FreeSurface(surface);
}

Text::~Text() {
    _FreeTexture();
}

void Text::_FreeTexture() {
    if (_texture != nullptr) {
        SDL_DestroyTexture(_texture);
        _texture = nullptr;
    }
}

void Text::SetText(std::string text) {
    _text = text;
    _ConstructTexture();
}

/**
 * To change the font size we need to open a new TTF Font and then
 * rebuild the texture
 */
void Text::SetFontSize(int size) {
    _font = FontCache::getInstance()->GetFont(_fontfile, size);
    _ConstructTexture();
}

void Text::SetColor(SDL_Color color) {
    _color = color;
    _ConstructTexture();
}

