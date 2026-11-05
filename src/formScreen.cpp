#include "formScreen.hpp"

formScreen::formScreen(referenceSwitch &referenceSwitch, const sf::Font &font, const std::string &titleText, sf::Vector2f titlePos)
    : _title(font, titleText, 65.f, titlePos), display(referenceSwitch) {}

void formScreen::addField(sf::Vector2f size, sf::Vector2f position, const sf::Font &font, const std::string &labelText)
{
    this->_inputFields.push_back(std::make_unique<inputBox>(size, position, font));

    float textSize = size.y * CHARSCALEINTOBOX - 15.f;
    sf::Vector2f labelPos = {position.x, position.y - textSize - 25.f};
    this->_labels.emplace_back(font, labelText, textSize, labelPos);
}

void formScreen::draw(sf::RenderWindow &window) const
{
    this->_title.draw(window);

    for (const auto &box : this->_inputFields)
    {
        box->draw(window);
    }

    for (const auto &lbl : this->_labels)
    {
        lbl.draw(window);
    }

    this->drawReferences(window);
    this->drawButtons(window);
}

void formScreen::update()
{
    for (auto &box : this->_inputFields)
    {
        box->setColor();
    }
}

void formScreen::handleEvent(const sf::Event &event, const sf::RenderWindow &window)
{
    if (this->handleReferencesEvent(event, window) || this->handleButtonsEvent(event, window))
    {
        return;
    }

    if (const auto *mouse = event.getIf<sf::Event::MouseButtonPressed>())
    {
        const sf::Vector2f mousePosition = window.mapPixelToCoords(mouse->position);

        int clickedIndex = -1;
        for (size_t i = 0; i < this->_inputFields.size(); ++i)
        {
            if (this->_inputFields[i]->getBoxBorder().contains(mousePosition))
            {
                clickedIndex = static_cast<int>(i);
                break;
            }
        }

        for (size_t i = 0; i < this->_inputFields.size(); ++i)
        {
            this->_inputFields[i]->setFocus(static_cast<int>(i) == clickedIndex);
        }
    }

    for (auto &box : this->_inputFields)
    {
        box->handleEvent(event);
    }
}
