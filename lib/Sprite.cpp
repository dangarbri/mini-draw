#include "Sprite.h"

Coordinates Sprite::GetPosition() {
    return Coordinates {x, y};
}

SDL_Rect Sprite::GetTargetRect() {
    return SDL_Rect {x, y, width * scale, height * scale};
}

void Sprite::SetPosition(int x, int y) {
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

int Sprite::GetScale() {
    return scale;
}

void Sprite::SetScale(int scale) {
    this->scale = scale;
}

