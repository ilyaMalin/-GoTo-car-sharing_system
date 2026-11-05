#include "signIn.hpp"
#include "referenceSwitch.hpp"

signIn::signIn(referenceSwitch &refSwitch, sf::Vector2f boxSize, sf::Vector2f boxPosition, const sf::Font &font)
    : formScreen(refSwitch, font, "Sign In", {110.f, 125.f})
{
    const float fieldStep = boxSize.y * (1.f + CHARSCALEINTOBOX) + 45.f;

    addField(boxSize, boxPosition, font, "Login");
    addField(boxSize, {boxPosition.x, boxPosition.y + fieldStep}, font, "Password");
    setSwitchText("Don't have an account? Sign Up", {boxPosition.x, boxPosition.y + 1.5f * fieldStep}, boxSize.y * CHARSCALEINTOBOX * 0.6);
}

void signIn::setStateWin()
{
    _referenceSwitch.setStateWin(STATEWIN::SIGNUP);
}