#ifndef GUICOMPONENTS_HPP

#define GUICOMPONENTS_HPP
#include "loadFont.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#define CHARSCALEINTOBOX 0.75
#define FIRSTINVALIDCHAR 32
#define LASTINVALIDCHAR 127

class box
{
protected:
    sf::RectangleShape _box;
    sf::Text _text;

public:
    box(sf::Vector2f, sf::Vector2f, const sf::Font &);
    virtual void draw(sf::RenderWindow &) const = 0;
    const sf::FloatRect &getBoxBorder() const;
    virtual ~box() = default;
};

class inputBox : public box
{
private:
    std::string _inputText;
    bool _isFocused = false;

public:
    inputBox(sf::Vector2f, sf::Vector2f, const sf::Font &);
    void draw(sf::RenderWindow &) const override;
    void handleEvent(const sf::Event &);
    void setColor();
    void setFocus(bool);
    const sf::FloatRect getBoxBorder() const;
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

#endif