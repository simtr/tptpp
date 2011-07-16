#include <SFML/Graphics.hpp>
#include "Panel.hpp"
#include <iostream>

using namespace ui;

Panel::Panel(int x, int y, int width, int height):
Component(x, y, width, height)
{
	Repaint();
}

void Panel::Repaint()
{
	//Draw component here
	Surface.Draw(sf::Shape::Rectangle(0, 0, Width, Height, sf::Color::Blue));
	Surface.Display();
	//Tell the parent that we've changed
	if(Parent)
	{
		Parent->ChildUpdate(this);
	}
}

void Panel::Add(Component *child)
{
	Children.push_back(child);
	child->Parent = this;
	child->Repaint();
}

