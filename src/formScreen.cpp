#include "formScreen.hpp"

formScreen::formScreen(const sf::Font &font, const std::string &titleText, sf::Vector2f titlePos)
    : _title(font, titleText, 50.f, titlePos) {}

void formScreen::addField(sf::Vector2f size, sf::Vector2f position, const sf::Font &font, const std::string &labelText)
{
    _inputFields.push_back(std::make_unique<inputBox>(size, position, font));

    float textSize = size.y * CHARSCALEINTOBOX;
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
}

void formScreen::update()
{
    for (auto &box : _inputFields)
    {
        box->setColor();
    }
}

void formScreen::handleEvent(const sf::Event &event)
{
    if (event.is<sf::Event::MouseButtonPressed>())
    {
        sf::Vector2i mousePosition = event.getIf<sf::Event::MouseButtonPressed>()->position;

        int clickedIndex = -1;
        for (size_t i = 0; i < _inputFields.size(); ++i)
        {
            if (_inputFields[i]->getBoxBorder().contains(static_cast<sf::Vector2f>(mousePosition)))
            {
                clickedIndex = static_cast<int>(i);
                break;
            }
        }

        for (size_t i = 0; i < _inputFields.size(); ++i)
        {
            _inputFields[i]->setFocus(static_cast<int>(i) == clickedIndex);
        }
    }

    for (auto &box : _inputFields)
    {
        box->handleEvent(event);
    }
}