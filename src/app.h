/**
 * @page Application
 *
 * The app is the core of your application.
 * While main will bootstrap SDL, App will be called by main to
 * bootstrap your application. It must perform the initialization
 * of your assets and define the update function for your app.
 *
 * The App class uses the pimpl (pointer to implementation) design
 * principle so that the App class's header can remain standard for
 * any Application a user wishes to implement. All core logic including
 * Application variables are defined in the Application's own app.cpp file
 * and can remain separate from the template header.
 *
 * This also allows the main bootstrap library to also remain standard, as
 * it doesn't need to know your application's specific class name. It will
 * always create an instance of App, which will load your defined implementation
 * of it.
 *
 * This design is loosely based on cocos2d-x. In that framework, you implement
 * scenes which follow a similar structure of this App class. Though this framework
 * is not as sophisticated as cocos2d-x, so this App actually represents your entire
 * program. Any scene definitions should be created by you by controlling what happens
 * in your update function.
 *
 * One thing you may do is create several smaller "apps" of your own design, then
 * maintain a state in the App core. When the state changes, you may run one of your own
 * sub apps, thus creating different rooms/scenes/screens etc.
 */

/**
 * App that defines initialization and update commands
 */
class App {
public:
    App();
    ~App();
    /**
     * Executed after SDL is initialized, before anything else
     * has been done.
     */
    void OnStartup();

    /**
     * Update function called every frame.
     *
     * @param[in] dt delta time since last frame (TODO)
     */
    void OnUpdate(Uint32 dt);

    /**
     * Executed before SDL has been shutdown, but the program is closing.
     */
    void OnShutdown();

private:
    struct impl;
    struct impl* _impl;
};

