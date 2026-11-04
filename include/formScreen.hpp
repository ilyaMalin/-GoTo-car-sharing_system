#ifndef FORMSCREEN_HPP
#define FORMSCREEN_HPP

#include "display.hpp"
#include <vector>
#include <memory>
#include <string>

class formScreen : public display
{
protected:
    textBox _title;
    std::vector<std::unique_ptr<inputBox>> _inputFields;
    std::vector<textBox> _labels;

public:
    formScreen(const sf::Font &font, const std::string &titleText, sf::Vector2f titlePos);

    void draw(sf::RenderWindow &window) const override;
    void update() override;
    void handleEvent(const sf::Event &event) override;

    void addField(sf::Vector2f size, sf::Vector2f position, const sf::Font &font, const std::string &labelText);
};

#endif