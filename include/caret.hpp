#ifndef CARET_HPP

#define CARET_HPP
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

#define CHARSCALEINTOBOX 0.75f
#define WIDTHCARET 1.25f

class caret
{
private:
    mutable bool _isVisible = false;

    sf::RectangleShape _caret;
    mutable sf::Clock _clock;

    void update() const;

public:
    caret(const sf::Vector2f &, const sf::Vector2f &);
    void setVisible(bool);
    void setPosition(const float &);
    void draw(sf::RenderWindow &) const;
};

#endif
