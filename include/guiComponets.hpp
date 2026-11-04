#ifndef GUICOMPONENTS_HPP

#define GUICOMPONENTS_HPP
#include "loadFont.hpp"
#include "caret.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#define FIRSTINVALIDCHAR 32
#define LASTINVALIDCHAR 127
#define SIZECHARACTER 22.5f

class box
{
protected:
    sf::RectangleShape _box;
    sf::Text _text;

public:
    box(sf::Vector2f, sf::Vector2f, const sf::Font &);
    virtual void draw(sf::RenderWindow &) const = 0;
    virtual const sf::FloatRect getBoxBorder() const = 0;
    virtual ~box() = default;
};

class inputBox : public box
{
private:
    caret _caret;

    std::string _inputText;
    bool _isFocused = false;

    void handleKeyPressed(const sf::Keyboard::Key &);
    void handleTextEntered(const sf::Event::TextEntered &);

    void moveCaret();

    void removeLastCharacter();
    void inputCharacter(char32_t &);

public:
    inputBox(sf::Vector2f, sf::Vector2f, const sf::Font &);
    void draw(sf::RenderWindow &) const override;
    void handleEvent(const sf::Event &);
    void setColor();
    void setFocus(bool);
    const sf::FloatRect getBoxBorder() const override;
    const std::string &getText() const;
};

class outBox : public box
{
private:
    bool _isVisible = false;

public:
    outBox(sf::Vector2f, sf::Vector2f, const sf::Font &);
    void draw(sf::RenderWindow &) const override;
    void setOutText(const std::string &);
    void setVisible(bool);
};

class textBox
{
private:
    sf::Text _text;

public:
    textBox(const sf::Font &, sf::String, float &, sf::Vector2f);
    void draw(sf::RenderWindow &) const;
};

#endif