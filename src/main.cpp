#include "Flags.h"

#include "Game.h"

#include <iostream>

int main(int argc, char** argv)
{ 
    Game game({800, 600});
    game.run();

    return 0;
}
