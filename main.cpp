#include <SFML/Graphics.hpp>

#include <iostream>
#include "button.hpp"
#include "game.hpp"
int main(int argc, char **argv){

    std::cout << "SFML_Simon Started..." << std::endl;

    Game* game = new Game();
    game->Initialize();
    game->Run();

    std::cout << "SFML_Simon Terminated!" << std::endl;
    return 0;
}