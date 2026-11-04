#include "caret.hpp"

void caret::update() const
{
    if (_clock.getElapsedTime().asSeconds() >= .5f)
    {
        _clock.restart();
        this->_isVisible = !this->_isVisible;
    }
}

caret::caret(const sf::Vector2f &boxSize, const sf::Vector2f &position)
{
    this->_caret.setPosition({position.x + 10.f, position.y + boxSize.y / 10});
    this->_caret.setSize({WIDTHCARET, boxSize.y * CHARSCALEINTOBOX});
}

void caret::setVisible(bool visible)
{
    this->_isVisible = visible;
}

void caret::setPosition(const float &positionX)
{
    auto currentPositionY = this->_caret.getPosition().y;
    this->_caret.setPosition({positionX, currentPositionY});
}

void caret::draw(sf::RenderWindow &window) const
{
    this->update();

    if (this->_isVisible)
    {
        window.draw(this->_caret);
    }
}