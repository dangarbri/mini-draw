#pragma once
#include "SDL.h"
#include "curve/CubicBezier.h"

/**
 * @addtogroup AppBuilder
 *
 * @section Transition
 *
 * A transition can be used to animate a Sprite property
 * (or any property) using a given curve.
 */

template <typename T>
class Transition {
public:
    /**
     * Create a transition instance
     *
     * @param[in] value Pointer to the value being modified
     * @param[in] curve The curve that specifies the value over time.
                        p0 should be the starting value, and p3 should be the ending value
     * @param[in] duration Length of the transition in milliseconds
     */
    Transition(T* value, CubicBezier curve, float duration): _property(value),
                                                             _curve(curve),
                                                             _duration(duration) {};

    /**
     * Update the field controlled by this transition
     *
     * @param[in] dt Milliseconds since last frame
     */
    void Update(Uint32 dt);
private:
    /**
     * The property to be controlled by this transition
     */
    T* _property;

    /**
     * The bezier curve for this animation
     */
    CubicBezier _curve;

    /**
     * The transition duration
     */
    float _duration;

    /**
     * The current time of the transition
     */
    Uint32 _current_time = 0;
};

template <typename T>
void Transition<T>::Update(Uint32 dt) {
    _current_time += dt;
    float percent_complete = _current_time / _duration;
    *_property = _curve.get(percent_complete);
}

