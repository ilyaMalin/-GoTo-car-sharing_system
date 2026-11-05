#include "updateView.hpp"

void updateView(sf::RenderWindow &window, sf::View &view)
{
    const sf::Vector2u windowSize = window.getSize();

    if (windowSize.x == 0 || windowSize.y == 0)
    {
        return;
    }

    constexpr float VIEWWIDTH = 800.f;
    constexpr float VIEWHEIGHT = 1200.f;

    const float windowRatio = static_cast<float>(windowSize.x) / static_cast<float>(windowSize.y);

    const float viewRatio = VIEWWIDTH / VIEWHEIGHT;

    sf::FloatRect viewport({0.f, 0.f}, {1.f, 1.f});

    if (windowRatio > viewRatio)
    {
        const float width = viewRatio / windowRatio;

        viewport.position.x = (1.f - width) / 2.f;
        viewport.size.x = width;
    }
    else
    {
        const float height = windowRatio / viewRatio;

        viewport.position.y = (1.f - height) / 2.f;
        viewport.size.y = height;
    }

    view.setViewport(viewport);
    window.setView(view);
}