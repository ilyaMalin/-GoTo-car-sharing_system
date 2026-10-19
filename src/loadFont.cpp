#include "loadFont.hpp"

void loadFont(sf::Font &font, const char *pathToFont)
{
    std::string path = pathToFont;

    if (!font.openFromFile(pathToFont))
    {
        throw std::runtime_error("Font to " + path + " is not found!");
    }
}