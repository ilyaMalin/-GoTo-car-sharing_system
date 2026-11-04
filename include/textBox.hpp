#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>

#define SIZECHARACTER 22.5f

class textBox
{
private:
    sf::Text _text;

public:
    textBox(const sf::Font &font, sf::String string, float size, sf::Vector2f position);
    void draw(sf::RenderWindow &window) const;
};

#endif