#ifndef UI_HPP

#define UI_HPP
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Display
{
private:
    const sf::Vector2u windowSize;
    sf::RenderWindow window;

public:
    Display(const sf::Vector2u = {500, 800});
    bool isOpen() const;
    std::optional<sf::Event> pollEvent();
    void clear();
    void display();
    void close();
};

class SingIn : Display
{
};

class SingUp : Display
{
};

class Profile : Display
{
};

class Map : Display
{
};

class Rent : Display
{
};

#endif
