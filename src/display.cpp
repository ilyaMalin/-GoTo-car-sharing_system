#include "display.hpp"
#include "referenceSwitch.hpp"

void display::addReference(const sf::Font &font, const std::string &text, unsigned int characterSize, sf::Vector2f position, STATEWIN target)
{
    this->_references.emplace_back(font, text, characterSize);

    this->_references.back().setPosition(position);
    this->_references.back().setFillColor(_defaultColor);

    this->_referenceTargets.push_back(target);
}

void display::drawReferences(sf::RenderWindow &window) const
{
    for (const auto &reference : _references)
    {
        window.draw(reference);
    }
}

bool display::handleReferencesEvent(const sf::Event &event, const sf::RenderWindow &window)
{
    if (const auto *mouse = event.getIf<sf::Event::MouseMoved>())
    {
        const auto mousePosition = window.mapPixelToCoords(mouse->position);

        for (auto &reference : _references)
        {
            if (reference.getGlobalBounds().contains(mousePosition))
            {
                reference.setFillColor(this->_hoverColor);
            }
            else
            {
                reference.setFillColor(this->_defaultColor);
            }
        }
    }
    else if (const auto *mouse = event.getIf<sf::Event::MouseButtonPressed>())
    {
        const auto mousePosition = window.mapPixelToCoords(mouse->position);

        for (size_t i = 0; i < this->_references.size(); ++i)
        {
            if (this->_references[i].getGlobalBounds().contains(mousePosition))
            {
                this->_referenceSwitch.setStateWin(_referenceTargets[i]);
                return true;
            }
        }
    }

    return false;
}

void display::addButton(const sf::Font &font, const std::string &text, unsigned int characterSize, sf::Vector2f position, sf::Vector2f size, STATEWIN target)
{
    this->_buttons.emplace_back(size);
    this->_buttons.back().setPosition(position);
    this->_buttons.back().setFillColor(this->_buttonColor);

    this->_buttonTexts.emplace_back(font, text, characterSize);

    const auto bounds = this->_buttonTexts.back().getLocalBounds();

    this->_buttonTexts.back().setPosition({position.x + (size.x - bounds.size.x) / 2.f - bounds.position.x,
                                           position.y + (size.y - bounds.size.y) / 2.f - bounds.position.y});

    this->_buttonTexts.back().setFillColor(this->_buttonTextColor);

    this->_buttonTargets.push_back(target);
}

void display::drawButtons(sf::RenderWindow &window) const
{
    for (size_t i = 0; i < this->_buttons.size(); ++i)
    {
        window.draw(this->_buttons[i]);
        window.draw(this->_buttonTexts[i]);
    }
}

bool display::handleButtonsEvent(const sf::Event &event, const sf::RenderWindow &window)
{
    if (const auto *mouse = event.getIf<sf::Event::MouseMoved>())
    {
        const auto mousePosition = window.mapPixelToCoords(mouse->position);

        for (auto &button : this->_buttons)
        {
            if (button.getGlobalBounds().contains(mousePosition))
            {
                button.setFillColor(this->_buttonHoverColor);
            }
            else
            {
                button.setFillColor(this->_buttonColor);
            }
        }
    }
    else if (const auto *mouse = event.getIf<sf::Event::MouseButtonPressed>())
    {
        const auto mousePosition = window.mapPixelToCoords(mouse->position);

        for (size_t i = 0; i < this->_buttons.size(); ++i)
        {
            if (this->_buttons[i].getGlobalBounds().contains(mousePosition))
            {
                this->_referenceSwitch.setStateWin(this->_buttonTargets[i]);
                return true;
            }
        }
    }

    return false;
}
