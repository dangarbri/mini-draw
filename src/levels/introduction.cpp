#include "introduction.h"
#include "constants.h"

Introduction::Introduction() {
    // Set up the splash text
    _company_name = std::make_unique<Text>("assets/fonts/BLKCHCRY.TTF", 18, "A game by Daniel Garcia-Briseno");
    _company_name->SetPosition((APP_RESOLUTION_WIDTH / 2) - (_company_name->GetWidth() / 2), 0);

    // Set target position of the splash text and transition it into place
    // in the center of the screen
    float target = (APP_RESOLUTION_HEIGHT / 2) - (_company_name->GetHeight() / 2);
    _slide_in = std::make_unique<Transition<float>>(&_company_y_position, CubicBezier{target - 148, target - 148, target - 75, target}, 1500);
}

void Introduction::Update(Uint32 dt) {
    _slide_in->Update(dt);
    Coordinates pos = _company_name->GetPosition();
    pos.y = _company_y_position;
    _company_name->SetPosition(pos);
    _company_name->Draw();
}

SDL_bool Introduction::IsComplete() { return SDL_FALSE; }


