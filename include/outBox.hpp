#ifndef OUTBOX_HPP
#define OUTBOX_HPP

#include "box.hpp"
#include <string>

class outBox : public box
{
private:
    bool _isVisible = false;

public:
    outBox(sf::Vector2f size, sf::Vector2f position, const sf::Font &font);
    void draw(sf::RenderWindow &window) const override;
    void setOutText(const std::string &text);
    void setVisible(bool visible);
};

#endif