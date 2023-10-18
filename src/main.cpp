#include "App.hpp"

int main(int argc, char *argv[])
{
    auto app = std::make_unique<App>();
    return app->OnExecute();
}

