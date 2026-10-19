#include "ui.hpp"
#include <iostream>

signUp::signUp(sf::Vector2f boxSize, sf::Vector2f boxPosition, const sf::Font &font)
{
    this->_loginBox = new inputBox(boxSize, boxPosition, font);
    this->_passwordBox = new inputBox(boxSize, {boxPosition.x, boxPosition.y + 100.f}, font);
}

signUp::~signUp()
{
    delete this->_loginBox;
    delete this->_passwordBox;
}

void signUp::draw(sf::RenderWindow &window) const
{
    this->_loginBox->draw(window);
    this->_passwordBox->draw(window);
}

void signUp::update()
{
    this->_loginBox->setColor();
    this->_passwordBox->setColor();
}

void signUp::handleEvent(const sf::Event &event)
{
    if (event.is<sf::Event::MouseButtonPressed>())
    {
        bool loginFocus = false;
        bool passwordFocus = false;

        sf::Vector2i mousePosition = event.getIf<sf::Event::MouseButtonPressed>()->position;
        const auto &loginBoxBorder = this->_loginBox->getBoxBorder();
        const auto &passwordBoxBorder = this->_passwordBox->getBoxBorder();

        if (loginBoxBorder.contains(static_cast<sf::Vector2f>(mousePosition)))
        {
            loginFocus = true;
        }
        else if (passwordBoxBorder.contains(static_cast<sf::Vector2f>(mousePosition)))
        {
            passwordFocus = true;
        }

        this->_loginBox->setFocus(loginFocus);
        this->_passwordBox->setFocus(passwordFocus);
    }

    this->_loginBox->handleEvent(event);
    this->_passwordBox->handleEvent(event);
}
