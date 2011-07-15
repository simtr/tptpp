#ifndef __SYS_COMPONENT_H__
#define __SYS_COMPONENT_H__

#include "Point.hpp"
#include "State.hpp"

namespace ui
{	
	class State;
	
	class Component  
	{
	public:
		Component(State* s);
		~Component();

		Point Position;
		Point Size;
		bool Locked;
		bool Visible;

		virtual void Tick(float dt);
		virtual void Draw();

		virtual void OnMouseHover(int localx, int localy);
		virtual void OnMouseMoved(int localx, int localy, int dx, int dy);
		virtual void OnMouseMovedInside(int localx, int localy, int dx, int dy);
		virtual void OnMouseDown(int x, int y, unsigned int button);
		virtual void OnMouseUp(int x, int y, unsigned int button);
		virtual void OnMouseClick(int localx, int localy, unsigned int button);
		virtual void OnMouseUnclick(int localx, int localy, unsigned int button);
		virtual void OnMouseWheel(int localx, int localy, int d);
		virtual void OnMouseWheelFocused(int localx, int localy, int d);
		virtual void OnKeyPress(int key, bool shift, bool ctrl, bool alt);
		virtual void OnKeyUnpress(int key, bool shift, bool ctrl, bool alt);

		inline State* GetParent() { return parent_; }

	private:
		State* parent_;
		
	};
}

#endif // __SYS_COMPONENT_H__