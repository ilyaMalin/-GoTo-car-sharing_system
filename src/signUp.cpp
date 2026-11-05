#include "signUp.hpp"
#include "referenceSwitch.hpp"

signUp::signUp(referenceSwitch &referenceSwitch, sf::Vector2f boxSize, sf::Vector2f boxPosition, const sf::Font &font)
    : formScreen(referenceSwitch, font, "Sign Up", {110.f, 125.f})
{
    const float fieldStep = boxSize.y * (1.f + CHARSCALEINTOBOX) + 45.f;

    addField(boxSize, boxPosition, font, "Login");
    addField(boxSize, {boxPosition.x, boxPosition.y + fieldStep}, font, "Password");
    addField(boxSize, {boxPosition.x, boxPosition.y + 2 * fieldStep}, font, "Phone Number");
    setSwitchText("Already have an account? Sign In", {boxPosition.x, boxPosition.y + 2.5f * fieldStep}, boxSize.y * CHARSCALEINTOBOX * 0.6);
}

void signUp::setStateWin()
{
    _referenceSwitch.setStateWin(STATEWIN::SIGNIN);
}