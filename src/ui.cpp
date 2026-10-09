#include "ui.hpp"

Display::Display(const sf::Vector2u windowSize)
    : windowSize(windowSize), window(sf::VideoMode(windowSize), "GoTo", sf::Style::Close | sf::Style::Titlebar) {}

bool Display::isOpen() const
{
    return this->window.isOpen();
}

std::optional<sf::Event> Display::pollEvent()
{
    return this->window.pollEvent();
}

void Display::clear()
{
    this->window.clear();
}

void Display::display()
{
    this->window.display();
}

void Display::close()
{
    this->window.close();
}

int main()
{
    Display win;

    while (win.isOpen())
    {
        while (const std::optional event = win.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                win.close();
            }
        }

        win.clear();
        win.display();
    }
}