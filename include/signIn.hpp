#ifndef SIGNIN_HPP
#define SIGNIN_HPP

#include "formScreen.hpp"

class signIn : public formScreen
{
public:
    signIn(referenceSwitch &, sf::Vector2f, sf::Vector2f, const sf::Font &);
};

#endif