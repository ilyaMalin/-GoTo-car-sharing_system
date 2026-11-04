#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "inputBox.hpp"
#include "textBox.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class display
{
public:
    virtual void draw(sf::RenderWindow &window) const = 0;
    virtual void update() = 0;
    virtual void handleEvent(const sf::Event &event) = 0;
    virtual ~display() = default;
};

#endif