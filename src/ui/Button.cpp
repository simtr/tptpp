#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include <iostream>
#include <string>

using namespace ui;

Button::Button(int x, int y, int width, int height, const std::string& buttonText):
Component(x, y, width, height),
ButtonText(buttonText)
{
	Repaint();
}

void Button::Repaint()
{
	//Draw component here
	sf::Text textGraphic(ButtonText);
	textGraphic.SetCharacterSize(11);
	textGraphic.SetColor(sf::Color::White);

	if(mouseOver)
	{
		Surface.Draw(sf::Shape::Rectangle(2.0f, 2.0f, (float)(Width-4), (float)(Height-4), sf::Color::Black, 2.0f, sf::Color::White));
	} else {
		Surface.Draw(sf::Shape::Rectangle(1.0f, 1.0f, (float)(Width-2), (float)(Height-2), sf::Color::Black, 1.0f, sf::Color::White));
	}
	Surface.Draw(textGraphic);//Doesn't work? It seems the rectangle is always drawn on top...

	Surface.Display();
	//Tell the parent that we've changed
	if(Parent)
	{
		Parent->OnChildUpdate(this);
	}
}

void Button::OnMouseUp(int x, int y, unsigned int button)
{
	mousePressed = false;
	//Do action
	Repaint();
}

void Button::OnMouseDown(int x, int y, unsigned int button)
{
	mousePressed = true;
	Repaint();
}

void Button::OnMouseEnter(int x, int y)
{
	mouseOver = true;
	Repaint();
}

void Button::OnMouseLeave(int x, int y)
{
	mouseOver = false;
	Repaint();
}


void Button::SetAction()
{
	//Set the action of the button
}
