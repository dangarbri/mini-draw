#include "ProgramState.h"

void ProgramState::SetRenderer(const SDL_Renderer* renderer) {
    _renderer = renderer;
}

const SDL_Renderer* ProgramState::GetRenderer() {
    return _renderer;
}

