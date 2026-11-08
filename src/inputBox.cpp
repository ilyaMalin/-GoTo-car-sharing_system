#include "inputBox.hpp"

inputBox::inputBox(sf::Vector2f boxSize, sf::Vector2f boxPositions, const sf::Font &font)
    : box(boxSize, boxPositions, font), _caret(boxSize, boxPositions) {}

void inputBox::setColor()
{
    if (this->_isFocused)
    {
        this->_box.setFillColor({171, 171, 171});
        return;
    }

    this->_box.setFillColor({210, 212, 211});
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

    if (this->_isFocused)
    {
        this->_caret.draw(window);
    }
}

void inputBox::moveCaret()
{
    const float positionLastCharacter = this->_text.getPosition().x + this->_text.getLocalBounds().size.x;
    this->_caret.setPosition(positionLastCharacter);
}

void inputBox::removeLastCharacter()
{
    if (!this->_inputText.empty())
    {
        this->_inputText.pop_back();
        this->_text.setString(this->_inputText);
    }
}

void inputBox::handleKeyPressed(const sf::Keyboard::Key &key)
{
    switch (key)
    {
    case sf::Keyboard::Key::Backspace:
    {
        this->removeLastCharacter();
        this->moveCaret();
        break;
    }
    }
}

void inputBox::inputCharacter(char32_t &codeCharacter)
{
    if (codeCharacter <= FIRSTINVALIDCHAR || codeCharacter >= LASTINVALIDCHAR)
    {
        return;
    }

    sf::String futureTextString = this->_inputText + static_cast<char>(codeCharacter);

    sf::Text futureText = this->_text;
    futureText.setString(futureTextString);

    const auto &boxBorder = this->getBoxBorder();
    float maxAllowedWidth = boxBorder.size.x - 10.f;

    float futureTextWidth = futureText.getLocalBounds().size.x;
    if (futureTextWidth < maxAllowedWidth)
    {
        this->_inputText += static_cast<char>(codeCharacter);
        this->_text.setString(this->_inputText);
    }
}

void inputBox::handleTextEntered(const sf::Event::TextEntered &textEntered)
{
    char32_t codeCharacter = textEntered.unicode;
    this->inputCharacter(codeCharacter);

    this->moveCaret();
}

void inputBox::handleEvent(const sf::Event &event)
{
    if (!this->_isFocused)
    {
        return;
    }

    if (event.is<sf::Event::KeyPressed>())
    {
        const auto code = event.getIf<sf::Event::KeyPressed>()->code;
        this->handleKeyPressed(code);
    }
    else if (event.is<sf::Event::TextEntered>())
    {
        const auto &textEntered = event.getIf<sf::Event::TextEntered>();
        this->handleTextEntered(*textEntered);
    }
}