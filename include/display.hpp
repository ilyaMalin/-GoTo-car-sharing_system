#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "inputBox.hpp"
#include "referenceSwitch.hpp"
#include "textBox.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class referenceSwitch;

class display
{
protected:
    referenceSwitch &_referenceSwitch;

public:
    display(referenceSwitch &refSwitch) : _referenceSwitch(refSwitch) {}
    virtual void draw(sf::RenderWindow &window) const = 0;
    virtual void update() = 0;
    virtual void handleEvent(const sf::Event &event, const sf::RenderWindow &) = 0;
    virtual void setStateWin() = 0;
    virtual ~display() = default;
};

#endif