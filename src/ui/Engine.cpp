#include "Engine.h"
#include <sys/State.h>

using namespace sys;

Engine::Engine(int width, int height)
:
width_(width),
height_(height),
state_(NULL),
statequeued_(NULL),
mousex_(0),
mousey_(0),
mousexp_(0),
mouseyp_(0)
{
}

Engine::~Engine()
{
	if(state_ != NULL)
		delete state_;
}

void Engine::SetState(State &state)
{
	statequeued_ = &state;
}

void Engine::SetSize(int width, int height)
{
	width_ = width;
	height_ = height;
}

void Engine::Tick(float dt)
{
	if(state_ != NULL)
		state_->Tick(dt);

	if(statequeued_ != NULL)
	{
		if(state_ != NULL)
		{
			state_->Exit();
			delete state_;
		}
		state_ = statequeued_;
		statequeued_ = NULL;

		if(state_ != NULL)
			state_->Initialized();
	}
}

void Engine::Draw()
{
	if(state_)
		state_->Draw();
}

void Engine::onKeyPress(int key, bool shift, bool ctrl, bool alt)
{
	if(state_)
		state_->OnKeyPress(key, shift, ctrl, alt);
}

void Engine::onKeyUnpress(int key, bool shift, bool ctrl, bool alt)
{
	if(state_)
		state_->OnKeyUnpress(key, shift, ctrl, alt);
}

void Engine::onMouseClick(int x, int y, unsigned int button)
{
	if(state_)
		state_->OnMouseDown(x, y, button);
}

void Engine::onMouseUnclick(int x, int y, unsigned int button)
{
	if(state_)
		state_->OnMouseUp(x, y, button);
}

void Engine::onMouseMove(int x, int y)
{
	mousex_ = x;
	mousey_ = y;
	if(state_)
		state_->OnMouseMove(x, y, mousex_ - mousexp_, mousey_ - mouseyp_);
	mousexp_ = x;
	mouseyp_ = y;
}

void Engine::onMouseWheel(int x, int y, int delta)
{
	if(state_)
		state_->OnMouseWheel(x, y, delta);
}

void Engine::onClose()
{
	if(state_)
		state_->Exit();
}