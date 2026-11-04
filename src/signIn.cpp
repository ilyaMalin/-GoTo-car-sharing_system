#include "signIn.hpp"

signIn::signIn(sf::Vector2f boxSize, sf::Vector2f boxPosition, const sf::Font &font)
    : formScreen(font, "Sign In", {110.f, 125.f})
{
    addField(boxSize, boxPosition, font, "Login");
    addField(boxSize, {boxPosition.x, boxPosition.y + 100.f}, font, "Password");
}