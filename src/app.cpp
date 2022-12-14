#include "SDL.h"
#include "app.h"
#include "AnimatedImage.h"
#include "Text.h"
#include "AppBuilder/WASDMovement.h"

struct App::impl {
    /** Define your app data here */
    AnimatedImage* test;
    WASDMovement* controller;
    Text* text;
};

void App::OnStartup() {
    /** Put your initialization code here */
    _impl->test = new AnimatedImage("assets/0x72_DungeonTilesetII_v1.4.png", SDL_Rect{128, 100, 16, 28}, 4);
    _impl->test->SetFrameDelay(150);
    _impl->test->SetPosition(120, 114);
    _impl->test->SetRotation(270);
    _impl->controller = new WASDMovement(_impl->test);
    _impl->controller->Disable();
    _impl->text = new Text("assets/fonts/BLKCHCRY.TTF", 24, "Hello World!");
    Coordinates text_position = _impl->text->GetPosition();
    text_position.x = 128 - (_impl->text->GetWidth() / 2);
    _impl->text->SetPosition(text_position);
}

void App::OnUpdate(Uint32 dt) {
    /** Put your frame update code here */
    _impl->controller->Update(dt);
    _impl->test->Update(dt);
    _impl->test->Draw();
    _impl->text->Draw();
}

void App::OnShutdown() {
    /** Put your cleanup code here */
    delete _impl->controller;
    delete _impl->test;
    delete _impl->text;
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

