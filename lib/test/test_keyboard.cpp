#include <cassert>
#include "Keyboard.h"

/**
 * This tests the case that no keys have been pressed, and
 * we're checking that the keyboard returns false for
 * any key
 */
void test_keys_not_pressed() {
    Keyboard* keyboard = Keyboard::getInstance();
    assert(keyboard->IsPressed(SDLK_w) == SDL_FALSE);
    assert(keyboard->IsPressed(SDLK_a) == SDL_FALSE);
    assert(keyboard->IsPressed(SDLK_s) == SDL_FALSE);
    assert(keyboard->IsPressed(SDLK_d) == SDL_FALSE);
    assert(keyboard->IsPressed(SDLK_1) == SDL_FALSE);
}

void test_key_pressed() {
    Keyboard* keyboard = Keyboard::getInstance();
    // Assert the key is not pressed before it's been pressed
    assert(keyboard->IsPressed(SDLK_a) == SDL_FALSE);
    // Press the key
    keyboard->PressKey(SDLK_a);
    // Assert that the key is pressed
    assert(keyboard->IsPressed(SDLK_a) == SDL_TRUE);
    // Release the key
    keyboard->ReleaseKey(SDLK_a);
    // Assert that the key is released
    assert(keyboard->IsPressed(SDLK_a) == SDL_FALSE);
}

int main() {
    test_keys_not_pressed();
    test_key_pressed();
}

