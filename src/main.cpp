#include "Flags.h"

#include "Game.h"

#include "Event.h"
#include "EventManager.h"

#include <iostream>

int main(int argc, char** argv)
{ 
    EventManager manager;
    auto c = manager.register_event_handler("say_hi", [](const EventArgs& a) {std::cout << "hi" << std::endl;});

    auto fn2 = [](const std::string& a)
    {
        std::cout << a << std::endl;
    };

    auto c2 = manager.register_event_handler("say", std::function<void (const std::string&a)>(fn2));
    manager.trigger("say_hi");
    NullEventArgs args;
    manager.trigger("say_hi", args);
    manager.trigger("say", std::string("woah"));
    //Game game({800, 600});
    //game.run();

    return 0;
}
