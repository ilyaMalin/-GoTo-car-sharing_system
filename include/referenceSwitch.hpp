#ifndef REFERENCESWITCH_HPP

#define REFERENCESWITCH_HPP
#include <SFML/Graphics/Font.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "stateWin.hpp"
#include <memory>

class signUp;
class signIn;
class profile;

class referenceSwitch
{
private:
    STATEWIN _state = STATEWIN::SIGNIN;

    std::unique_ptr<signUp> _signUp;
    std::unique_ptr<signIn> _signIn;
    std::unique_ptr<profile> _profile;

public:
    referenceSwitch(const sf::Font &, sf::Vector2f, sf::Vector2f);
    ~referenceSwitch();
    void setStateWin(STATEWIN);
    void handleEvent(const sf::Event &, const sf::RenderWindow &);
    void update();
    void draw(sf::RenderWindow &) const;
};

#endif