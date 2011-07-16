#include "ui/Component.hpp"
#include <iostream>

using namespace ui;

Component::Component(int x, int y, int width, int height):
X(x),
Y(y),
Width(width),
Height(height)
{
	Surface.Create(Width, Height);
	Repaint();
}

Component::~Component()
{
	Children.~vector();
}

void Component::Repaint()
{
	Surface.Draw(sf::Text("You should not see this"));
	Surface.Display();
	if(Parent)
	{
		Parent->ChildUpdate(this);
	}
}

void Component::ChildUpdate(Component *child)
{
}

void Component::Tick(float dt)
{
}

void Component::OnKeyPress(int key, bool shift, bool ctrl, bool alt)
{
}

void Component::OnKeyUnpress(int key, bool shift, bool ctrl, bool alt)
{
}

void Component::OnMouseEnter(int localx, int localy)
{
}

void Component::OnMouseLeave(int localx, int localy)
{
}

void Component::OnMouseDown(int x, int y, unsigned int button)
{
}

void Component::OnMouseMoved(int localx, int localy, int dx, int dy)
{
}

void Component::OnMouseUp(int x, int y, unsigned int button)
{
}

void Component::OnMouseWheel(int localx, int localy, int d)
{
}

void Component::SetSize(int width, int height)
{
	Width = width;
	Height = height;
	Surface.Create(Width, Height);
	Repaint();
}

void Component::SetPosition(int x, int y)
{
	X = x;
	Y = y;
	if(Parent)
	{
		Parent->ChildUpdate(this);
	}
}

void Component::Add(Component *child)
{
	/*Children.push_back(child);
	child->Parent = this;
	child->Repaint();*/
	//Basic component does not support children.
}

