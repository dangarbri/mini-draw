#include "curve/CubicBezier.h"
#include <iostream>
#include <cassert>
#include <ctime>

/**
 * This is an example of how you can use a cubic bezier
 * curve to smooth out animation
 */
void animation_example() {
    // Let the animation run for 5 seconds
    float animation_time = 5;
    // Specify a bezier curve
    CubicBezier bezier(0, 50, 50, 100);
    // You will use a more exact timer like SDL provides
    int dt = 0;
    while(dt <= animation_time) {
        float percent_complete = dt / animation_time;
        // Track number of seconds that passed
        dt += 1;
        std::cout << "Animation Position: " << bezier.get(percent_complete) << std::endl;
    }
}

void test_linear_curve() {
    // A curve where p1 = 33% progress and p2 = 66% progress
    // will result in a linear curve.
    CubicBezier bezier(0, 33.333, 66.666, 100);
    std::cout << "Linear position (0): " << bezier.get(0) << std::endl;
    std::cout << "Linear position (0.25): " << bezier.get(0.25) << std::endl;
    std::cout << "Linear position (0.50): " << bezier.get(0.50) << std::endl;
    std::cout << "Linear position (0.75): " << bezier.get(0.75) << std::endl;
    std::cout << "Linear position (1): " << bezier.get(1) << std::endl;
}

void test_cubic_bezier() {
    CubicBezier bezier {0, 25, 25, 100};
    assert(bezier.get(0) == 0);
    assert(bezier.get(1) == 100);
}

int main() {
    test_cubic_bezier();
    animation_example();
    test_linear_curve();
}

