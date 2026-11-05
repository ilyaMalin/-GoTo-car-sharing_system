#include "profile.hpp"

profile::profile(referenceSwitch &referenceSwitch, const sf::Font &font)
    : display(referenceSwitch), _title(font, "GoTo", 65)
{
    this->_title.setPosition({110.f, 125.f});

    this->addReference(font, "Rent a car", 24, {200.f, 350.f}, STATEWIN::MAP);
    this->addReference(font, "Log Out", 24, {200.f, 450.f}, STATEWIN::SIGNIN);
}

void profile::draw(sf::RenderWindow &window) const
{
    window.draw(_title);

    this->drawReferences(window);
}

void profile::update()
{
}

void profile::handleEvent(const sf::Event &event, const sf::RenderWindow &window)
{
    this->handleReferencesEvent(event, window);
}
