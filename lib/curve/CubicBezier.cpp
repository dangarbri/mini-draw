#include "CubicBezier.h"
#include <cmath>

CubicBezier::CubicBezier(float p0, float p1, float p2, float p3) {
    _p0 = p0;
    _p1 = p1;
    _p2 = p2;
    _p3 = p3;
}

double CubicBezier::get(double position) {
    // Cubic Bezier function from wikipedia:
    // a          + b              + c              + d
    // (1-t)^3*p0 + 3*(1-t)^2*t*p1 + 3*(1-t)*t^2*p2 + t^3*p3
    // where t = position
    double a = pow(1 - position, 3) * _p0;
    double b = 3 * pow(1 - position, 2) * position * _p1;
    double c = 3 * (1 - position) * pow(position, 2) * _p2;
    double d = pow(position, 3) * _p3;
    return a + b + c +d;
}

