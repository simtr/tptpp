#include "Component.hpp"
#include <iostream>

using namespace ui;

Component::Component(int x, int y, int width, int height):
X(x),
Y(y),
Width(width),
Height(height),
Parent(NULL),
focusedChild(NULL)
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
	sf::Sprite tempSprite(child->Surface.GetImage());
	tempSprite.SetPosition((float)child->X, (float)child->Y);
	Surface.Draw(tempSprite);
	if(Parent)
	{
		Parent->ChildUpdate(this);
	}
}

void Component::Tick(float dt)
{
	for(int i = 0; Children.size(); i++)
	{
		if(Children[i] && Children[i]->Enabled && Children[i]->Visible)
		{
			Children[i]->Tick(dt);
		}
	}
}

void Component::OnKeyPress(int key, bool shift, bool ctrl, bool alt)
{
	if(focusedChild && focusedChild->Enabled)
	{
		focusedChild->OnKeyPress(key, shift, ctrl, alt);
	}
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

Component* Component::GetChildAtPosition(int x, int y)
{
	for(int i = 0; Children.size(); i++)
	{
		if(Children[i] && Children[i]->Enabled && Children[i]->Visible &&
			Children[i]->X < x &&Children[i]->Y < Y &&
			Children[i]->Width+Children[i]->X > x && Children[i]->Height+Children[i]->Y > y)
		{
			return Children[i];
		}
	}
	return NULL;
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

