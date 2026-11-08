#ifndef INPUTBOX_HPP
#define INPUTBOX_HPP

#include "box.hpp"
#include "caret.hpp"
#include <SFML/Window/Event.hpp>
#include <string>

#define FIRSTINVALIDCHAR 32
#define LASTINVALIDCHAR 127

class inputBox : public box
{
private:
    caret _caret;
    std::string _inputText;
    bool _isFocused = false;

    void handleKeyPressed(const sf::Keyboard::Key &key);
    void handleTextEntered(const sf::Event::TextEntered &textEvent);
    void moveCaret();
    void removeLastCharacter();
    void inputCharacter(char32_t &codeCharacter);

public:
    inputBox(sf::Vector2f size, sf::Vector2f position, const sf::Font &font);
    void draw(sf::RenderWindow &window) const override;
    void handleEvent(const sf::Event &event);
    void setColor();
    void setFocus(bool focus);
    const sf::FloatRect getBoxBorder() const override;
    const std::string &getText() const;
};

#endif