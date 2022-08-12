#include "Sprite.h"

Coordinates Sprite::GetPosition() {
    return Coordinates {x, y};
}

SDL_Rect Sprite::GetTargetRect() {
    float scaled_width = width * scale;
    float scaled_height = height * scale;
    int new_width = static_cast<int>(SDL_roundf(scaled_width));
    int new_height = static_cast<int>(SDL_roundf(scaled_height));
    int int_x = static_cast<int>(x);
    int int_y = static_cast<int>(y);
    return SDL_Rect {int_x, int_y, new_width, new_height};
}

void Sprite::SetPosition(float x, float y) {
    this->x = x;
    this->y = y;
}

void Sprite::SetPosition(Coordinates coords) {
    SetPosition(coords.x, coords.y);
}

int Sprite::GetWidth() {
    return width;
}

void Sprite::SetWidth(int width) {
    this->width = width;
}

int Sprite::GetHeight() {
    return height;
}

void Sprite::SetHeight(int height) {
    this->height = height;
}

float Sprite::GetScale() {
    return scale;
}

void Sprite::SetScale(float scale) {
    this->scale = scale;
}

void Sprite::SetRotation(float rotation) {
    this->rotation = rotation;
}

float Sprite::GetRotation() {
    return rotation;
}

