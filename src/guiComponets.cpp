#include "guiComponets.hpp"

box::box(sf::Vector2f boxSize, sf::Vector2f boxPositions, const sf::Font &font)
    : _text(font, ""), _box(boxSize)
{
    this->_box.setPosition(boxPositions);
    this->_text.setFillColor(sf::Color::Black);

    float sizeCharacter = boxSize.y * CHARSCALEINTOBOX;
    this->_text.setCharacterSize(sizeCharacter);

    this->_text.setPosition({boxPositions.x + 10.f, boxPositions.y});
}

inputBox::inputBox(sf::Vector2f boxSize, sf::Vector2f boxPositions, const sf::Font &font)
    : box(boxSize, boxPositions, font) {}

void inputBox::setColor()
{
    if (this->_isFocused)
    {
        this->_box.setFillColor({210, 212, 211});
        return;
    }

    this->_box.setFillColor({171, 171, 171});
}

void inputBox::setFocus(bool focus)
{
    this->_isFocused = focus;
}

const sf::FloatRect inputBox::getBoxBorder() const
{
    return this->_box.getGlobalBounds();
}

const std::string &inputBox::getText() const
{
    return this->_inputText;
}

void inputBox::draw(sf::RenderWindow &window) const
{
    window.draw(this->_box);
    window.draw(this->_text);
}

void inputBox::handleEvent(const sf::Event &event)
{
    if (!this->_isFocused)
    {
        return;
    }

    if (event.is<sf::Event::KeyPressed>())
    {
        const auto &key = event.getIf<sf::Event::KeyPressed>()->code;
        if (key == sf::Keyboard::Key::Backspace)
        {
            if (!this->_inputText.empty())
            {
                this->_inputText.pop_back();
                this->_text.setString(this->_inputText);
            }

            return;
        }
    }
    else if (event.is<sf::Event::TextEntered>())
    {
        const auto &textEntered = event.getIf<sf::Event::TextEntered>();
        char32_t code = textEntered->unicode;

        if (code <= FIRSTINVALIDCHAR || code >= LASTINVALIDCHAR)
        {
            return;
        }

        sf::String futureTextString = this->_inputText + static_cast<char>(code);

        sf::Text futureText = this->_text;
        futureText.setString(futureTextString);

        const auto &boxBorder = this->getBoxBorder();
        float maxAllowedWidth = boxBorder.size.x - 10.f;

        float futureTextWidth = futureText.getLocalBounds().size.x;
        if (futureTextWidth < maxAllowedWidth)
        {
            this->_inputText += static_cast<char>(code);
            this->_text.setString(this->_inputText);
        }
    }
}

void outBox::setVisible(bool visible)
{
    this->_isVisible = visible;
}

void outBox::setOutText(const std::string &outText)
{
    this->_text.setString(outText);
}

void outBox::draw(sf::RenderWindow &window) const
{
    if (this->_isVisible)
    {
        window.draw(this->_box);
        window.draw(this->_text);
    }
}
