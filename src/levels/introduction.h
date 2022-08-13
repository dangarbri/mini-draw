#include "SDL.h"
#include "Text.h"
#include "AppBuilder/Transition.h"
#include <memory>

/**
 * Displays the splash screen when the game launches.
 */
class Introduction {
public:
    /**
     * Initializes the introduction
     */
    Introduction();

    /**
     * Frame update code
     *
     * @param[in] dt Milliseconds since last frame
     */
    void Update(Uint32 dt);

    /**
     * Returns true when the introduction animation is complete
     */
    SDL_bool IsComplete();
private:
    /** Splash screen text */
    std::unique_ptr<Text> _company_name;
    std::unique_ptr<Transition<float>> _slide_in;
    float _company_y_position;
};

