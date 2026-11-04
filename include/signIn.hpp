#ifndef SIGNIN_HPP
#define SIGNIN_HPP

#include "formScreen.hpp"

class signIn : public formScreen
{
public:
    signIn(sf::Vector2f boxSize, sf::Vector2f boxPosition, const sf::Font &font);
};

#endif