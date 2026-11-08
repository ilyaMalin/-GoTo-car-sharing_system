#include "outBox.hpp"

void outBox::setVisible(bool visible)
{
    this->_isVisible = visible;
}

void outBox::setOutText(const std::string &outText)
{
    this->_text.setString(outText);
}

void outBox::draw(sf::RenderWindow &window) const
{
    if (this->_isVisible)
    {
        window.draw(this->_box);
        window.draw(this->_text);
    }
}