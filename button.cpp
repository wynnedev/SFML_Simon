#include "button.hpp"

Button::Button(int sideSize, sf::Color color, int top, int left) : _sideSize(sideSize),
    _color(color),
    _buttonState(BUTTON_STATE::NORMAL),
    _top(top),
    _left(left)
    {
        _background.setPosition(top, left);
        _background.setSize(sf::Vector2f(_sideSize, _sideSize));
        _background.setFillColor(color);
};

sf::RectangleShape& Button::GetButton(){
    return _background;
}

void Button::ButtonPressed(bool isPressed){
    if(isPressed){
        _buttonState = BUTTON_STATE::PRESSED;
        std::cout << "Button Clicked" << std::endl;
    }

    else{
        _buttonState = BUTTON_STATE::NORMAL;
    }
}

void Button::Illuminate(){
    _background.setFillColor(sf::Color::White);
    std::cout << "Button Illuminated" << std::endl;
}

void Button::ProcessState(){
    
    switch(_buttonState){
        case BUTTON_STATE::NORMAL:
            _background.setFillColor(_color);
        break;

        case BUTTON_STATE::PRESSED:
            this->Illuminate();            
        break;

        default:
        std::cerr << "Button Error" << std::endl;
        break;

    }
}