#include "box.hpp"

box::box(sf::Vector2f boxSize, sf::Vector2f boxPositions, const sf::Font &font)
    : _text(font, ""), _box(boxSize)
{
    this->_box.setPosition(boxPositions);
    this->_text.setFillColor(sf::Color::Black);

    float sizeCharacter = boxSize.y * CHARSCALEINTOBOX;
    this->_text.setCharacterSize(sizeCharacter);

    this->_text.setPosition({boxPositions.x + 10.f, boxPositions.y});
}