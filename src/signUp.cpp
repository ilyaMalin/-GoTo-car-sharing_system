#include "signUp.hpp"
#include "referenceSwitch.hpp"

signUp::signUp(referenceSwitch &referenceSwitch, sf::Vector2f boxSize, sf::Vector2f boxPosition, const sf::Font &font)
    : formScreen(referenceSwitch, font, "Sign Up", {110.f, 125.f})
{
    const float fieldStep = boxSize.y * (1.f + CHARSCALEINTOBOX) + 45.f;

    this->addField(boxSize, boxPosition, font, "Login");
    this->addField(boxSize, {boxPosition.x, boxPosition.y + fieldStep}, font, "Password");
    this->addField(boxSize, {boxPosition.x, boxPosition.y + 2 * fieldStep}, font, "Phone Number");
    this->addReference(font, "Already have an account? Sign In", boxSize.y * CHARSCALEINTOBOX * 0.6, {boxPosition.x, boxPosition.y + fieldStep * 2.f + boxSize.y + 25.f}, STATEWIN::SIGNIN);
    addButton(font, "Registration", 24, {boxPosition.x, boxPosition.y + fieldStep * 3.f}, {boxSize.x, 60.f}, STATEWIN::PROFILE);
}