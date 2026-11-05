#include "referenceSwitch.hpp"
#include "updateView.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({600, 800}), "GoTo", sf::Style::Default);

    sf::Font font;

    try
    {
        font.openFromFile("assets/fonts/times.ttf");
    }
    catch (std::exception &)
    {
    }

    sf::Vector2f boxSize{400.f, 60.f};
    sf::Vector2f boxPosition{200.f, 400.f};

    referenceSwitch screenManager(font, boxSize, boxPosition);

    sf::View uiView(sf::FloatRect({0.f, 0.f}, {800.f, 1200.f}));
    updateView(window, uiView);

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (event->is<sf::Event::Resized>())
            {
                updateView(window, uiView);
            }
            else
            {
                screenManager.handleEvent(*event, window);
            }
        }

        screenManager.update();
        window.clear(sf::Color::White);
        screenManager.draw(window);
        window.display();
    }

    return 0;
}