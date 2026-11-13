#ifndef SIGNUP_HPP
#define SIGNUP_HPP

#include "formScreen.hpp"

class signUp : public formScreen
{
public:
    signUp(referenceSwitch &, sf::Vector2f boxSize, sf::Vector2f boxPosition, const sf::Font &font);
    void handleButtonAction(STATEWIN target) override;
};

#endif
