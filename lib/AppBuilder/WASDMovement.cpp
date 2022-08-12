#include "WASDMovement.h"
#include <cassert>

/**
 * When moving diagonally, you can't simply add the speed to x & y
 * because that would move you further in the diagonal direction
 * than the actual speed. To keep speed consistent when moving
 * diagonally, we need to multiply the diagonal distance by sin(45deg)
 * to get the x & y speeds. Note this assumes the user is only moving
 * at 45 degree diagonals and doesn't work if you need other angles.
 */
#define DIAGONAL_MULTIPLIER 0.7071f

WASDMovement::WASDMovement(Sprite* target) {
    assert(target != nullptr);
    _sprite = target;
    _keyboard = Keyboard::getInstance();
}

WASDMovement::WASDMovement(Sprite* target, float speed) {
    assert(target != nullptr);
    _sprite = target;
    _keyboard = Keyboard::getInstance();
    this->speed = speed;
}


void WASDMovement::Disable() {
    _enabled = SDL_FALSE;
}

void WASDMovement::Enable() {
    _enabled = SDL_TRUE;
}

SDL_bool WASDMovement::IsEnabled() {
    return _enabled;
}

void WASDMovement::Update(Uint32 dt) {
    if (_enabled) {
        _ProcessUpdate(dt);
    }
}

enum Direction {
    UP,
    LEFT,
    DOWN,
    RIGHT,
    UP_LEFT,
    UP_RIGHT,
    DOWN_LEFT,
    DOWN_RIGHT,
    NONE
};

/**
 * Returns the desired direction based on keys that are being pressed
 *
 * @param[in] keyboard Keyboard instance to use for checking keys
 * @returns Direction that the user is moving
 */
static Direction _GetDirection(Keyboard* keyboard) {
    SDL_bool up = keyboard->IsPressed(SDLK_w);
    SDL_bool down = keyboard->IsPressed(SDLK_s);
    SDL_bool left = keyboard->IsPressed(SDLK_a);
    SDL_bool right = keyboard->IsPressed(SDLK_d);
    // For performance, if nothing is pressed don't bother checking anything
    if (!up && !down && !left && !right)
        return NONE;

    // Cancel out double presses
    if (up && down) {
        up = SDL_FALSE;
        down = SDL_FALSE;
    }
    if (left && right) {
        left = SDL_FALSE;
        right = SDL_FALSE;
    }
    // After canceling movements, check again if we should stop here.
    if (!up && !down && !left && !right)
        return NONE;

    // First check for single presses
    if (up && !down && !left && !right)
        return UP;
    if (!up && down && !left && !right)
        return DOWN;
    if (!up && !down && left && !right)
        return LEFT;
    if (!up && !down && !left && right)
        return RIGHT;
    // Next check for two key presses
    if (up && right)
        return UP_RIGHT;
    if (up && left)
        return UP_LEFT;
    if (down && right)
        return DOWN_RIGHT;
    if (down && left)
        return DOWN_LEFT;

    // If nothing was returned, then the above checks are incomplete
    assert(0);
}

/**
 * Returns the distance that the sprite needs to move in a given direction
 *
 * @param[in] dt Milliseconds since last frame
 * @param[in] speed Pixels per second movement speed
 * @param[in] direction Direction to move the sprite
 *
 * @returns Coordinates structure containing the x and y distance that the
 *          sprite must move
 */
Coordinates _GetDistance(Uint32 dt, float speed, Direction direction) {
    Coordinates distance {0, 0};
    // number of pixels to move each millisecond
    float movement = speed / 1000;
    float diagonal_movement = movement * DIAGONAL_MULTIPLIER;
    switch (direction) {
        case UP:
            distance.y = -movement;
            break;
        case DOWN:
            distance.y = movement;
            break;
        case LEFT:
            distance.x = -movement;
            break;
        case RIGHT:
            distance.x = movement;
            break;
        case UP_RIGHT:
            distance.x = diagonal_movement;
            distance.y = -diagonal_movement;
            break;
        case UP_LEFT:
            distance.x = -diagonal_movement;
            distance.y = -diagonal_movement;
            break;
        case DOWN_RIGHT:
            distance.x = diagonal_movement;
            distance.y = diagonal_movement;
            break;
        case DOWN_LEFT:
            distance.x = -diagonal_movement;
            distance.y = diagonal_movement;
            break;
    }
    return distance;
}

void WASDMovement::_ProcessUpdate(Uint32 dt) {
    // Get the direction the sprite needs to move from the keyboard
    Direction direction = _GetDirection(_keyboard);
    // Get distance to move according to direction
    Coordinates distance = _GetDistance(dt, speed, direction);
    // Move the sprite
    Coordinates position = _sprite->GetPosition();
    position.x += distance.x;
    position.y += distance.y;
    _sprite->SetPosition(position);
}

