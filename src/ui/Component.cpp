#include <ui/Engine.hpp>
#include <ui/Point.hpp>
#include <ui/State.hpp>
#include <ui/Component.hpp>

using namespace ui;

Component::Component(State* s)
:
Position(Point(0,0)),
Size(Point(0,0))
{
}

Component::~Component()
{

}

void Component::Draw()
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

void Component::OnMouseClick(int localx, int localy, unsigned int button)
{
}

void Component::OnMouseDown(int x, int y, unsigned int button)
{
}

void Component::OnMouseHover(int localx, int localy)
{
}

void Component::OnMouseMoved(int localx, int localy, int dx, int dy)
{
}

void Component::OnMouseMovedInside(int localx, int localy, int dx, int dy)
{
}

void Component::OnMouseUnclick(int localx, int localy, unsigned int button)
{
}

void Component::OnMouseUp(int x, int y, unsigned int button)
{
}

void Component::OnMouseWheel(int localx, int localy, int d)
{
}

void Component::OnMouseWheelFocused(int localx, int localy, int d)
{
}