#include "SDL.h"
#include "app.h"
#include "levels/introduction.h"

enum GameState {
    INTRODUCTION,
    DONE
};

struct App::impl {
    /** Define your app data and functions here */
    Introduction* intro = nullptr;
    enum GameState state = INTRODUCTION;

    void UpdateIntro(Uint32 dt);
};

void App::OnStartup() {
    /** Put your initialization code here */
    _impl->intro = new Introduction();
}

void App::OnUpdate(Uint32 dt) {
    /** Put your frame update code here */
    switch (_impl->state) {
        case INTRODUCTION:
            _impl->UpdateIntro(dt);
            break;
        case DONE:
            break;
    }
}

void App::OnShutdown() {
    /** Put your cleanup code here */
    if (_impl->intro != nullptr) {
        delete _impl->intro;
    }
}

void App::impl::UpdateIntro(Uint32 dt) {
    // Run the intro's update function
    intro->Update(dt);
    // Check if it's complete
    if (intro->IsComplete()) {
        // When it's complete, update the state and free
        // resources from the intro
        state = DONE;
        delete intro;
        intro = nullptr;
    }
}

/**
 * Template code, do not touch. If you need code to run in a constructor
 * then write it into App::impl's constructor.
 */
App::App() {
    _impl = new App::impl();
}

/**
 * Template code, do not touch. If you need code to run in a destructor 
 * then write it into App::impl's destructor.
 */
App::~App() {
    delete _impl;
}

