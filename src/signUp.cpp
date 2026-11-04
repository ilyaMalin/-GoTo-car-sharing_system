#include "signUp.hpp"

signUp::signUp(sf::Vector2f boxSize, sf::Vector2f boxPosition, const sf::Font &font)
    : formScreen(font, "Sign Up", {110.f, 125.f})
{
    addField(boxSize, boxPosition, font, "Login");
    addField(boxSize, {boxPosition.x, boxPosition.y + 100.f}, font, "Password");
    addField(boxSize, {boxPosition.x, boxPosition.y + 200.f}, font, "Phone Number");
}