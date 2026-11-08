#include "textBox.hpp"

textBox::textBox(const sf::Font &font, sf::String text, float sizeChar, sf::Vector2f textPosition)
    : _text(font, text, sizeChar)
{
    this->_text.setPosition(textPosition);
    this->_text.setFillColor(sf::Color::Black);
}

void textBox::draw(sf::RenderWindow &window) const
{
    window.draw(this->_text);
}