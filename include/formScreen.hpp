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

    sf::Text _switchText;
    sf::Color _defaultColor{80, 80, 80};
    sf::Color _hoverColor{30, 144, 255};

    void setSwitchText(const std::string &, sf::Vector2f, const float);

public:
    formScreen(referenceSwitch &, const sf::Font &, const std::string &, sf::Vector2f);
    void draw(sf::RenderWindow &) const override;
    void update() override;
    void handleEvent(const sf::Event &, const sf::RenderWindow &) override;
    virtual void setStateWin() override = 0;
    void addField(sf::Vector2f, sf::Vector2f, const sf::Font &, const std::string &);
};

#endif