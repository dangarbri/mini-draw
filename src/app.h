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
    void OnUpdate(float dt);

    /**
     * Executed before SDL has been shutdown, but the program is closing.
     */
    void OnShutdown();

private:
    struct impl;
    struct impl* _impl;
};

