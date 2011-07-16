#include "Component.hpp"
#include <iostream>

using namespace ui;

Component::Component(int x, int y, int width, int height):
X(x),
Y(y),
Width(width),
Height(height),
Focused(false),
Parent(NULL),
focusedChild(NULL),
mouseOverChild(NULL),
mousePressedChild(NULL)
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

void Component::OnKeyRelease(int key, bool shift, bool ctrl, bool alt)
{
	if(focusedChild && focusedChild->Enabled)
	{
		focusedChild->OnKeyRelease(key, shift, ctrl, alt);
	}
}

void Component::OnMouseEnter(int localx, int localy)
{
	mouseOver = true;
	if(Component* child = GetChildAtPosition(localx, localy))
	{
		child->OnMouseEnter(localx-child->X, localy-child->Y);
	}
}

void Component::OnMouseLeave(int localx, int localy)
{
	mouseOver = false;
	if(Component* child = GetChildAtPosition(localx, localy))
	{
		child->OnMouseLeave(localx-child->X, localy-child->Y);
	}
	// Mouse Leave event for any children that are still active
	if(mouseOverChild && mouseOverChild->mouseOver && !(mouseOverChild->X < localx && mouseOverChild->Y < Y && mouseOverChild->Width+mouseOverChild->X > localx && mouseOverChild->Height+mouseOverChild->Y > localy))
	{
		mouseOverChild->OnMouseLeave(localx-mouseOverChild->X, localy-mouseOverChild->Y);
		mouseOverChild = NULL;
	}
	// Mouse release for any children still pressed
	if(mousePressedChild && mousePressedChild->mousePressed && !(mousePressedChild->X < localx && mousePressedChild->Y < Y && mousePressedChild->Width+mousePressedChild->X > localx && mousePressedChild->Height+mousePressedChild->Y > localy))
	{
		mousePressedChild->OnMouseUp(localx-mousePressedChild->X, localy-mousePressedChild->Y, mousePressedChildButton);
		mousePressedChild = NULL;
	}
}

void Component::OnMouseDown(int x, int y, unsigned int button)
{
	mousePressed = true;
	if(Component* child = GetChildAtPosition(x, y))
	{
		child->OnMouseDown(x-child->X, y-child->Y, button);
		if(focusedChild)
		{
			focusedChild->Defocus();
		}
		focusedChild = child;
		mousePressedChild = child;
	}
}

void Component::OnMouseMoved(int localx, int localy, int dx, int dy)
{
	if(Component* child = GetChildAtPosition(localx, localy))
	{
		if(!child->mouseOver)
		{
			child->OnMouseEnter(localx-child->X, localy-child->Y);
		}
		child->OnMouseMoved(localx-child->X, localy-child->Y, dx, dy);
	}
	// Mouse Leave event for any children that are still active
	if(mouseOverChild && mouseOverChild->mouseOver && !(mouseOverChild->X < localx && mouseOverChild->Y < Y && mouseOverChild->Width+mouseOverChild->X > localx && mouseOverChild->Height+mouseOverChild->Y > localy))
	{
		mouseOverChild->OnMouseLeave(localx-mouseOverChild->X, localy-mouseOverChild->Y);
		mouseOverChild = NULL;
	}
	// Mouse release for any children still pressed
	if(mousePressedChild && mousePressedChild->mousePressed && !(mousePressedChild->X < localx && mousePressedChild->Y < Y && mousePressedChild->Width+mousePressedChild->X > localx && mousePressedChild->Height+mousePressedChild->Y > localy))
	{
		mousePressedChild->OnMouseUp(localx-mousePressedChild->X, localy-mousePressedChild->Y, mousePressedChildButton);
		mousePressedChild = NULL;
	}
}

void Component::OnMouseUp(int x, int y, unsigned int button)
{
	mousePressed = false;
	if(Component* child = GetChildAtPosition(x, y))
	{
		child->OnMouseUp(x-child->X, y-child->Y, button);
		mousePressedChild = NULL;
	}
}

void Component::OnMouseWheel(int localx, int localy, int d)
{
	if(Component* child = GetChildAtPosition(localx, localy))
	{
		child->OnMouseWheel(localx-child->X, localy-child->Y, d);
	}
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

void Component::Defocus()
{
	Focused = false;
	if(focusedChild)
	{
		focusedChild->Defocus();
	}
}

