#ifndef GAME_HPP
#define GAME_HPP

#include "button.hpp"

#include <SFML/Graphics.hpp>
#include <stack>

enum class GAME_STATE{
    INITIALIZED,
    RUNNING,
    EXIT
};

enum class BUTTON_COLOR{
    RED,
    YELLOW,
    BLUE,
    GREE
};

struct GameData{
    std::stack<BUTTON_COLOR> cpu_sequence;
    GAME_STATE gameState;
    Button* _activeButton;
    int score;
    int level;
 };

struct GameGraphics{
    Button* yellowButton;
    Button* blueButton;
    Button* greenButton;
    Button* redButton;
};

class Game{
public:
    Game() = default;
    void Initialize();
    void Run();

private:
    GameData _gameData;
    GameGraphics _gameGraphics;
    sf::RenderWindow* _renderWindow;
};


#endif