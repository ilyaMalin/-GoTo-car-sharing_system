#ifndef FORMSCREEN_HPP
#define FORMSCREEN_HPP

#include "display.hpp"
#include "stateWin.hpp"
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
    formScreen(referenceSwitch &, const sf::Font &, const std::string &, sf::Vector2f);
    void draw(sf::RenderWindow &) const override;
    void update() override;
    void handleEvent(const sf::Event &, const sf::RenderWindow &) override;
    void addField(sf::Vector2f, sf::Vector2f, const sf::Font &, const std::string &);
};

#endif