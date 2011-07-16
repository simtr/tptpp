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

	Surface.Draw(sf::Shape::Rectangle(1, 1, Width-2, Height-2, sf::Color::Black, 1.0f, sf::Color::White));
	Surface.Draw(textGraphic);//Doesn't work? It seems the rectangle is always drawn on top...

	Surface.Display();
	//Tell the parent that we've changed
	if(Parent)
	{
		Parent->ChildUpdate(this);
	}
}

void Button::OnMouseUp(int x, int y, unsigned int button)
{
	if(Component* child = GetChildAtPosition(x, y))
	{
		child->OnMouseUp(x-child->X, y-child->Y, button);
	}
	Repaint();
}

void Button::SetAction()
{
	//Set the action of the button
}
