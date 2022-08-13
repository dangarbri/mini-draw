#pragma once

/**
 * Implementation of a cubic bezier curve to help
 * with animation. I am not a mathemetician, so here
 * is my best explanation of the curve.
 *
 * The curve is created by 4 control points p0, p1, p2, p3.
 * The curve starts at p0 and ends at p3.
 * Points p1, and p2 are used to "bend" the curve towards them,
 * but they are not crossed in the curve.
 *
 * To use the bezier, first create it with the 4 control points, then
 * you can get the value of the curve by specifying a position between
 * 0 and 1, this maps to the % complete of the curve.
 *
 * At 0, the result will be p0
 * At 1, the result will be p3
 * In between, the result will be a function of the curve.
 *
 * The curves can be used to control animation speed.
 * See the test on this class for a usage example.
 *
 * @section Transitions
 *
 * The Transition class provides a way of using CubicBezier
 * curves to animate properties. Since you know p0 and p3 of a Bezier curve
 * are the start and end positions, use the Transition class to
 * add a duration and you can animate a property that follows
 * the Bezier curve
 */
class CubicBezier {
public:
    /**
     * Constructs a cubic bezier curve with the given control points
     *
     * @param[in] p0 Starting position
     * @param[in] p1 First control point
     * @param[in] p2 Second control point
     * @param[in] p3 Ending position
     */
    CubicBezier(float p0, float p1, float p2, float p3);

    /**
     * Returns the value of the curve at the given position
     *
     * @param[in] position Value between 0 and 1 to get the status of the curve.
     */
    double get(double position);
private:
    /** Starting position */
    float _p0 = 0;
    /** Control point 1 */
    float _p1 = 0;
    /** Control point 2 */
    float _p2 = 0;
    /** Ending position */
    float _p3 = 0;
};

