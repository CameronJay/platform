#include <iostream>
#include <memory>
#include <Application/Application.h>

int main()
{
    std::shared_ptr<App::Application> app(new App::Application);
    app->start();

    return 0;
}