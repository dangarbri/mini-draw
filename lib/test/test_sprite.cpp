#include <cassert>
#include <cstdio>
#include "Sprite.h"

class TestSprite : public Sprite {
    void Draw() {}
};

int main() {
    TestSprite test;
    test.x = 77;
    test.y = 55;

    Coordinates position = test.GetPosition();
    assert(position.x == test.x);
    assert(position.y == test.y);
}

