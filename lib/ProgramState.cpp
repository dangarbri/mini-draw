#include "ProgramState.h"

SDL_Renderer* ProgramState::_renderer = nullptr;

void ProgramState::SetRenderer(SDL_Renderer* renderer) {
    _renderer = renderer;
}

SDL_Renderer* ProgramState::GetRenderer() {
    return _renderer;
}

