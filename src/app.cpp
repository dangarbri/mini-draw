#include "app.h"
#include "Image.h"

struct App::impl {
    /** Define your app data here */
    Image* test;
};

void App::OnStartup() {
    /** Put your initialization code here */
    _impl->test = new Image("assets/0x72_DungeonTilesetII_v1.4.png");
}

void App::OnUpdate(float dt) {
    /** Put your frame update code here */
    _impl->test->Draw(0, 0);
}

void App::OnShutdown() {
    /** Put your cleanup code here */
    delete _impl->test;
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

