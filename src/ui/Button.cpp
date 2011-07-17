#include <SFML/Graphics.hpp>
#include <ui/Button.hpp>
#include <iostream>
#include <string>

using namespace ui;

Button::Button(int x, int y, int width, int height, const std::string& buttonText) : Component(x, y, width, height),
Toggleable(false),
ButtonText(buttonText),
isMouseInside(false),
isButtonDown(false),
state(false)
{
}

void Button::Draw(void* userdata)
{
    sf::RenderWindow* rw = reinterpret_cast<sf::RenderWindow*>(userdata); //it better be a RenderWindow or so help your god

	//Draw component here
	sf::Text textGraphic(ButtonText);
	textGraphic.SetCharacterSize(11);
	textGraphic.SetColor(sf::Color::White);
    textGraphic.SetPosition(X + 4, X + 4);

	if(isMouseInside)
	{
	    if(isButtonDown)
            rw->Draw(sf::Shape::Rectangle(X+1, Y+1, Width-2, Width-2, sf::Color::Black, 1.f, sf::Color::Cyan));
        else
            rw->Draw(sf::Shape::Rectangle(X+1, Y+1, Width-2, Width-2, sf::Color::Black, 2.f, sf::Color::White));
	}
	else
	{
	    if(isButtonDown)
            rw->Draw(sf::Shape::Rectangle(X+2, Y+2, Width-4, Width-4, sf::Color::Black, 1.f, sf::Color::Cyan));
        else
            rw->Draw(sf::Shape::Rectangle(X+2, Y+2, Width-4, Width-4, sf::Color::Black, 2.f, sf::Color::White));
	}

	rw->Draw(textGraphic);
}

void Button::OnMouseUnclick(int x, int y, unsigned int button)
{
    if(button != 1) return; //left click only!

	if(isButtonDown)
	{
	    if(state)
        {
            state = false;
        }
        else
        {
            if(Toggleable)
            {
                state = true;
            }
            DoAction();
        }
	}

	isButtonDown = false;
}

void Button::OnMouseUp(int x, int y, unsigned int button) //mouse unclick is called before this
{
    if(button != 1) return; //left click only!

	isButtonDown = false;
}

void Button::OnMouseClick(int x, int y, unsigned int button)
{
    if(button != 1) return; //left click only!

	isButtonDown = true;
}

void Button::OnMouseEnter(int x, int y, int dx, int dy)
{
    isMouseInside = true;
}

void Button::OnMouseLeave(int x, int y, int dx, int dy)
{
	isMouseInside = false;
}

void Button::DoAction()
{
    std::cout << "\nDo action!";
}
