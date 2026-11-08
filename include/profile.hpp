#ifndef PROFILE_HPP

#define PROFILE_HPP
#include "formScreen.hpp"

class profile : public display
{
private:
    sf::Text _title;

public:
    profile(referenceSwitch &, const sf::Font &);
    void draw(sf::RenderWindow &) const override;
    void update() override;
    void handleEvent(const sf::Event &, const sf::RenderWindow &) override;
};

#endif