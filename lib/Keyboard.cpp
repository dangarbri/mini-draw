#include "Keyboard.h"

Keyboard* Keyboard::instance = 0;

Keyboard::Keyboard() {}

Keyboard* Keyboard::getInstance() {
    if (instance == 0) {
        instance = new Keyboard();
    }
    return instance;
}

Keyboard::~Keyboard() {
    // Does this destructor get called for a static field?
    // And would it be a problem since it's deleting itself...?
    if (instance) {
        delete instance;
    }
}

SDL_bool Keyboard::IsPressed(SDL_Keycode key) {
    // First check if the key exists in the map
    auto key_in_mapping = _keys.find(key);
    if (key_in_mapping == _keys.end()) {
        // If the key doesn't exist, then it hasn't been pressed.
        return SDL_FALSE;
    } else {
        // Otherwise, it has, and it will have a value in the map
        return key_in_mapping->second;
    }
}

void Keyboard::PressKey(SDL_Keycode key) {
    _keys[key] = SDL_TRUE;
}

void Keyboard::ReleaseKey(SDL_Keycode key) {
    _keys[key] = SDL_FALSE;
}

