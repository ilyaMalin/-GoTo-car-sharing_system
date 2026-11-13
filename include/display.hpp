
#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "stateWin.hpp"
#include "inputBox.hpp"
#include "textBox.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class referenceSwitch;

class display
{
protected:
    referenceSwitch &_referenceSwitch;

    std::vector<sf::Text> _references;
    std::vector<STATEWIN> _referenceTargets;

    std::vector<sf::RectangleShape> _buttons;
    std::vector<sf::Text> _buttonTexts;
    std::vector<STATEWIN> _buttonTargets;

    sf::Color _defaultColor{80, 80, 80};
    sf::Color _hoverColor{30, 144, 255};
    sf::Color _buttonColor{210, 212, 211};
    sf::Color _buttonHoverColor{171, 171, 171};
    sf::Color _buttonTextColor{40, 40, 40};

    void drawReferences(sf::RenderWindow &) const;
    bool handleReferencesEvent(const sf::Event &, const sf::RenderWindow &);
    void drawButtons(sf::RenderWindow &) const;
    bool handleButtonsEvent(const sf::Event &, const sf::RenderWindow &);

public:
    explicit display(referenceSwitch &refSwitch) : _referenceSwitch(refSwitch) {}
    virtual void draw(sf::RenderWindow &window) const = 0;
    virtual void update() = 0;
    virtual void handleEvent(const sf::Event &event, const sf::RenderWindow &) = 0;
    virtual ~display() = default;

    void addReference(const sf::Font &, const std::string &, unsigned int, sf::Vector2f, STATEWIN);
    void addButton(const sf::Font &, const std::string &, unsigned int, sf::Vector2f, sf::Vector2f, STATEWIN);
    virtual void handleButtonAction(STATEWIN target);
};

#endif
