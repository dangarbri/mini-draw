#include <cassert>
#include <cstdio>
#include "Sprite.h"

class TestSprite : public Sprite {
public:
    void Update(Uint32) {}
    void Draw() {}
    // Getters and Setters for accessing protected methods for test purposes
    int getX() { return x; }
    void setX(int val) { x = val; }
    int getY() { return y; }
    void setY(int val) { y = val; }
};

void test_GetPosition() {
    TestSprite test;
    test.setX(77);
    test.setY(55);

    Coordinates position = test.GetPosition();
    assert(position.x == test.getX());
    assert(position.y == test.getY());
}

void test_GetTargetRect() {
    TestSprite test;
    test.SetWidth(45);
    test.SetHeight(99);
    test.setX(1);
    test.setY(2);

    SDL_Rect rect = test.GetTargetRect();
    assert(rect.w == test.GetWidth());
    assert(rect.h == test.GetHeight());
    assert(rect.x == test.getX());
    assert(rect.y == test.getY());
}

void test_SetPositionXY() {
    TestSprite test;
    test.SetPosition(10, 20);
    Coordinates pos = test.GetPosition();
    assert(pos.x == 10);
    assert(pos.y == 20);
}

void test_SetPositionCoords() {
    TestSprite test;
    Coordinates target{111, 222};
    test.SetPosition(target);

    Coordinates position = test.GetPosition();
    assert(position.x == 111);
    assert(position.y == 222);
}

int main() {
    test_GetPosition();
    test_GetTargetRect();
    test_SetPositionXY();
    test_SetPositionCoords();
}

