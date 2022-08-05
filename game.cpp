#include "game.hpp"

void Game::Initialize(){
    _gameData.level = 0;
    _gameData.score = 0;
    _gameData.gameState = GAME_STATE::INITIALIZED;
}

void Game::Run(){

    while(GAME_STATE::EXIT != _gameData.gameState){
        switch(_gameData.gameState){
            case GAME_STATE::INITIALIZED:
                _gameGraphics.yellowButton = new Button(100, sf::Color::Yellow, 10, 10);
                _gameGraphics.blueButton = new Button(100, sf::Color::Blue, 10, 110);
                _gameGraphics.greenButton = new Button(100, sf::Color::Green, 110, 10);
                _gameGraphics.redButton = new Button(100, sf::Color::Red, 110, 110);
                _gameData._activeButton = _gameGraphics.yellowButton;
                _renderWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML works!");
                _gameData.gameState = GAME_STATE::RUNNING;
            break;

            case GAME_STATE::RUNNING:
                std::cout << "Game Running" << std::endl;
                while (GAME_STATE::RUNNING == _gameData.gameState)
                {
                    sf::Event event;
                    
                    while (_renderWindow->pollEvent(event))
                    {
                        bool illuminate_button = false;

                        if (event.type == sf::Event::Closed)
                            _gameData.gameState = GAME_STATE::EXIT;

                        if (event.type == sf::Event::MouseButtonPressed){
                            auto mousePosition = sf::Mouse::getPosition(*_renderWindow);
                            std::cout << "Mouse Clicked " << mousePosition.x << " " << mousePosition.y << std::endl;

                            ///TODO fix so that you don't need to subtract 100
                            if(_gameGraphics.yellowButton->GetButton().getGlobalBounds().contains(mousePosition.x - 100, mousePosition.y - 100)){
                                _gameData._activeButton = _gameGraphics.yellowButton;
                                illuminate_button = true;
                            }

                            if(_gameGraphics.blueButton->GetButton().getGlobalBounds().contains(mousePosition.x - 100, mousePosition.y - 100)){
                                _gameData._activeButton = _gameGraphics.blueButton;
                                illuminate_button = true;
                            }

                            if(_gameGraphics.redButton->GetButton().getGlobalBounds().contains(mousePosition.x - 100, mousePosition.y - 100)){
                                _gameData._activeButton = _gameGraphics.redButton;
                                illuminate_button = true;
                            }

                            if(_gameGraphics.greenButton->GetButton().getGlobalBounds().contains(mousePosition.x - 100, mousePosition.y - 100)){
                                _gameData._activeButton = _gameGraphics.greenButton;
                                illuminate_button = true;
                            } 
                        }

                        _gameData._activeButton->ButtonPressed(illuminate_button);
                        _gameData._activeButton->ProcessState();
                    

                        _renderWindow->clear();
                        _renderWindow->draw(_gameGraphics.yellowButton->GetButton());
                        _renderWindow->draw(_gameGraphics.blueButton->GetButton());
                        _renderWindow->draw(_gameGraphics.redButton->GetButton());
                        _renderWindow->draw(_gameGraphics.greenButton->GetButton());
                        _renderWindow->display();
                    }
                }
        break;

        case GAME_STATE::EXIT:
            _renderWindow->close();
        break;
        }
    }
}