#include "formScreen.hpp"

formScreen::formScreen(referenceSwitch &referenceSwitch, const sf::Font &font, const std::string &titleText, sf::Vector2f titlePos)
    : _title(font, titleText, 65.f, titlePos), display(referenceSwitch), _switchText(font, "", 16) {}

void formScreen::addField(sf::Vector2f size, sf::Vector2f position, const sf::Font &font, const std::string &labelText)
{
    _inputFields.push_back(std::make_unique<inputBox>(size, position, font));

    float textSize = size.y * CHARSCALEINTOBOX - 15.f;
    sf::Vector2f labelPos = {position.x, position.y - textSize - 25.f};
    _labels.emplace_back(font, labelText, textSize, labelPos);
}

void formScreen::draw(sf::RenderWindow &window) const
{
    _title.draw(window);

    for (const auto &box : _inputFields)
    {
        box->draw(window);
    }

    for (const auto &lbl : _labels)
    {
        lbl.draw(window);
    }

    window.draw(_switchText);
}

void formScreen::update()
{
    for (auto &box : _inputFields)
    {
        box->setColor();
    }
}

void formScreen::setStateWin()
{
}

void formScreen::setSwitchText(const std::string &text, sf::Vector2f position, const float boxSizeY)
{
    _switchText.setString(text);
    _switchText.setCharacterSize(boxSizeY);
    _switchText.setPosition(position);
    _switchText.setFillColor(_defaultColor);
}

void formScreen::handleEvent(const sf::Event &event, const sf::RenderWindow &window)
{
    if (const auto *mouse = event.getIf<sf::Event::MouseMoved>())
    {
        const sf::Vector2f mousePosition = window.mapPixelToCoords(mouse->position);

        if (_switchText.getGlobalBounds().contains(mousePosition))
        {
            _switchText.setFillColor(_hoverColor);
        }
        else
        {
            _switchText.setFillColor(_defaultColor);
        }
    }
    else if (const auto *mouse = event.getIf<sf::Event::MouseButtonPressed>())
    {
        const sf::Vector2f mousePosition = window.mapPixelToCoords(mouse->position);

        if (_switchText.getGlobalBounds().contains(mousePosition))
        {
            setStateWin();
            return;
        }

        int clickedIndex = -1;

        for (size_t i = 0; i < _inputFields.size(); i++)
        {
            if (_inputFields[i]->getBoxBorder().contains(mousePosition))
            {
                clickedIndex = static_cast<int>(i);
                break;
            }
        }

        for (size_t i = 0; i < _inputFields.size(); i++)
        {
            _inputFields[i]->setFocus(static_cast<int>(i) == clickedIndex);
        }
    }

    for (auto &box : _inputFields)
    {
        box->handleEvent(event);
    }
}