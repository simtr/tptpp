#include <ui/Engine.hpp>
#include <ui/State.hpp>
#include <vector>
#include <ui/Component.hpp>

using namespace ui;

State::State(Engine* engine)
:
engine_(engine)
{
}

State::~State()
{
	Components.~vector();
}

bool State::IsFocused(const Component &c)
{
	return &c == focusedComponent_;
}

void State::Exit()
{
}

void State::Initialized()
{
}

void State::Draw()
{
	//draw
	for(int i = 0; i < Components.size(); i++)
		if(Components[i]->Visible)
		{
			if(AllowExclusiveDrawing)
				Components[i]->Draw();
			else
				if(
					Components[i]->Position.X + Components[i]->Size.X >= 0 &&
					Components[i]->Position.Y + Components[i]->Size.Y >= 0 &&
					Components[i]->Position.X < this->GetEngine()->GetWidth() &&
					Components[i]->Position.Y < this->GetEngine()->GetHeight()
				  )
					Components[i]->Draw();
		}
			
}

void State::Tick(float dt)
{
	//on mouse hover
	for(int i = 0; i < Components.size(); i++)
		if(!Components[i]->Locked &&
			this->GetEngine()->GetMouseX() >= Components[i]->Position.X &&
			this->GetEngine()->GetMouseY() >= Components[i]->Position.Y &&
			this->GetEngine()->GetMouseX() < Components[i]->Position.X + Components[i]->Size.X &&
			this->GetEngine()->GetMouseY() < Components[i]->Position.Y + Components[i]->Size.Y
		)
		{
			Components[i]->OnMouseHover(this->GetEngine()->GetMouseX(), this->GetEngine()->GetMouseY());
			break;
		}
			
	//tick
	for(int i = 0; i < Components.size(); i++)
		Components[i]->Tick(dt);
}

void State::OnKeyPress(int key, bool shift, bool ctrl, bool alt)
{
	//on key press
	if(focusedComponent_ != NULL)
		if(!focusedComponent_->Locked)
			focusedComponent_->OnKeyPress(key, shift, ctrl, alt);
}

void State::OnKeyUnpress(int key, bool shift, bool ctrl, bool alt)
{
	//on key unpress
	if(focusedComponent_ != NULL)
		if(!focusedComponent_->Locked)
			focusedComponent_->OnKeyUnpress(key, shift, ctrl, alt);
}

void State::OnMouseDown(int x, int y, unsigned int button)
{
	//on mouse click
	for(int i = Components.size() - 1; i > -1 ; i--)
		if(!Components[i]->Locked)
			if(x >= Components[i]->Position.X && y >= Components[i]->Position.Y && x < Components[i]->Position.X + Components[i]->Size.X && y < Components[i]->Position.Y + Components[i]->Size.Y)
			{
				Components[i]->OnMouseClick(x - Components[i]->Position.X, y - Components[i]->Position.Y, button);
				this->focusedComponent_ = Components[i];
				break;
			}

	//on mouse down
	for(int i = Components.size() - 1; i > -1 ; i--)
		if(!Components[i]->Locked)
			Components[i]->OnMouseDown(x - Components[i]->Position.X, y - Components[i]->Position.Y, button);
}

void State::OnMouseMove(int x, int y, int dx, int dy)
{
	//on mouse move (if true, and inside)
	for(int i = Components.size() - 1; i > -1 ; i--)
		if(!Components[i]->Locked)
		{
			Point local = Point(x - Components[i]->Position.X, y - Components[i]->Position.Y);

			Components[i]->OnMouseMoved(local.X, local.Y, dx, dy);
			if(x >= Components[i]->Position.X &&
			   y >= Components[i]->Position.Y &&
			   x < Components[i]->Position.X + Components[i]->Size.X &&
			   y < Components[i]->Position.Y + Components[i]->Size.Y
			)
				Components[i]->OnMouseMovedInside(local.X, local.Y, dx, dy);
		}
}

void State::OnMouseUp(int x, int y, unsigned int button)
{
	//on mouse unclick
	for(int i = Components.size() - 1; i > -1 ; i--)
		if(!Components[i]->Locked)
			if(x >= Components[i]->Position.X && y >= Components[i]->Position.Y && x < Components[i]->Position.X + Components[i]->Size.X && y < Components[i]->Position.Y + Components[i]->Size.Y)
			{
				Components[i]->OnMouseUnclick(x - Components[i]->Position.X, y - Components[i]->Position.Y, button);
				this->focusedComponent_ = Components[i];
				break;
			}

	//on mouse up
	for(int i = Components.size() - 1; i > -1 ; i--)
		if(!Components[i]->Locked)
			Components[i]->OnMouseUp(x - Components[i]->Position.X, y - Components[i]->Position.Y, button);
}

void State::OnMouseWheel(int x, int y, int d)
{
	//on mouse wheel focused
	for(int i = Components.size() - 1; i > -1 ; i--)
		if(x >= Components[i]->Position.X && y >= Components[i]->Position.Y && x < Components[i]->Position.X + Components[i]->Size.X && y < Components[i]->Position.Y + Components[i]->Size.Y)
		{
			if(!Components[i]->Locked)
				Components[i]->OnMouseWheelFocused(x - Components[i]->Position.X, y - Components[i]->Position.Y, d);
			break;
		}
	
	//on mouse wheel
	for(int i = Components.size() - 1; i > -1 ; i--)
		if(!Components[i]->Locked)
			Components[i]->OnMouseWheel(x - Components[i]->Position.X, y - Components[i]->Position.Y, d);
}