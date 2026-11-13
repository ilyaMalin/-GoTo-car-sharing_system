#include "signIn.hpp"
#include "referenceSwitch.hpp"
#include "database.hpp"

signIn::signIn(referenceSwitch &refSwitch, sf::Vector2f boxSize, sf::Vector2f boxPosition, const sf::Font &font)
    : formScreen(refSwitch, font, "Sign In", {110.f, 125.f})
{
    const float fieldStep = boxSize.y * (1.f + CHARSCALEINTOBOX) + 45.f;

    this->addField(boxSize, boxPosition, font, "Login");
    this->addField(boxSize, {boxPosition.x, boxPosition.y + fieldStep}, font, "Password");
    this->addReference(font, "Don't have an account? Sign Up", boxSize.y * CHARSCALEINTOBOX * 0.6, {boxPosition.x, boxPosition.y + fieldStep + boxSize.y + 25.f}, STATEWIN::SIGNUP);
    addButton(font, "Entered", 24, {boxPosition.x, boxPosition.y + fieldStep * 2.f}, {boxSize.x, 60.f}, STATEWIN::PROFILE);
}

void signIn::handleButtonAction(STATEWIN target)
{
    if (target == STATEWIN::PROFILE)
    {
        if (!loginUser(getFieldText(0), getFieldText(1)))
            return;
    }

    display::handleButtonAction(target);
}
