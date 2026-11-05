#include "referenceSwitch.hpp"
#include "signUp.hpp"
#include "signIn.hpp"

referenceSwitch::referenceSwitch(const sf::Font &font, sf::Vector2f boxSize, sf::Vector2f boxPosition)
{
    this->_signIn = std::make_unique<signIn>(*this, boxSize, boxPosition, font);
    this->_signUp = std::make_unique<signUp>(*this, boxSize, boxPosition, font);
}

referenceSwitch::~referenceSwitch() = default;

void referenceSwitch::setStateWin(STATEWIN stateWin)
{
    this->_state = stateWin;
}

void referenceSwitch::handleEvent(const sf::Event &event, const sf::RenderWindow &window)
{
    switch (this->_state)
    {
    case STATEWIN::SIGNIN:
        this->_signIn->handleEvent(event, window);
        break;

    case STATEWIN::SIGNUP:
        this->_signUp->handleEvent(event, window);
        break;

    default:
        break;
    }
}

void referenceSwitch::update()
{
    switch (this->_state)
    {
    case STATEWIN::SIGNIN:
        this->_signIn->update();
        break;

    case STATEWIN::SIGNUP:
        this->_signUp->update();
        break;

    default:
        break;
    }
}

void referenceSwitch::draw(sf::RenderWindow &window) const
{
    switch (this->_state)
    {
    case STATEWIN::SIGNIN:
        this->_signIn->draw(window);
        break;

    case STATEWIN::SIGNUP:
        this->_signUp->draw(window);
        break;

    default:
        break;
    }
}