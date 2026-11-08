#ifndef BOX_HPP
#define BOX_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#define CHARSCALEINTOBOX 0.75f

class box
{
protected:
    sf::RectangleShape _box;
    sf::Text _text;

public:
    box(sf::Vector2f size, sf::Vector2f position, const sf::Font &font);
    virtual void draw(sf::RenderWindow &window) const = 0;
    virtual const sf::FloatRect getBoxBorder() const = 0;
    virtual ~box() = default;
};

#endif