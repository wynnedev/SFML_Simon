#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

enum class BUTTON_STATE{
    NORMAL,
    PRESSED,
};

class Button{
public:
    Button() = default;
    Button(int sideSize, sf::Color color, int top, int left);
    sf::RectangleShape& GetButton();
    void ButtonPressed(bool isPressed);
    void ProcessState();

private:
    void Illuminate();
    sf::RectangleShape _background;
    int _sideSize;
    int _top;
    int _left;
    sf::Color _color;
    BUTTON_STATE _buttonState;
};
#endif