#ifndef UI_HPP

#define UI_HPP
#include "guiComponets.hpp"

class display
{
public:
    virtual void draw(sf::RenderWindow &) const = 0;
    virtual void update() = 0;
    virtual void handleEvent(const sf::Event &) = 0;
    virtual ~display() = default;
};

class signUp : public display
{
private:
    inputBox *_loginBox;
    inputBox *_passwordBox;

public:
    signUp(sf::Vector2f, sf::Vector2f, const sf::Font &);
    void draw(sf::RenderWindow &) const override;
    void update() override;
    void handleEvent(const sf::Event &) override;
    ~signUp();
};

#endif