#include "curve/CubicBezier.h"
#include "AppBuilder/Transition.h"
#include <iostream>
#include <cassert>

int main () {
    float target = 10;
    // Define a curve that modified target over 1 second.
    Transition<float> transition {&target, CubicBezier{target, target + 33, target + 66, target + 100} ,1000};
    // Loop to simulate frames passing every 100ms
    for (Uint32 i = 0; i < 1000; i += 100) {
        transition.Update(100);
        // Log the value of target
        std::cout << "Target: " << target << std::endl;
    }
    assert(target == 110);
}

