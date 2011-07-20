#ifndef __SYS_COMPONENT_H__
#define __SYS_COMPONENT_H__

#include <vector>
#include <SFML/Graphics.hpp>

#include "State.hpp"

namespace ui
{
    class State;

	class Component
	{
	public:
		Component(int x, int y, int width, int height);
		virtual ~Component();

		inline void LocalizePoint(int& x, int& y) { x -= X; y -= Y; } //convert a global point (point on the state) to a point based on component's position
		inline void GlobalizePoint(int& x, int& y) { x += X; y += Y; } //convert a local point based on component's position to a global point on the state

		bool Focused;
		bool Visible;
		bool Enabled;
		int Width;
		int Height;
		int X;
		int Y;

		virtual void Tick(float dt);
		virtual void Draw(void* userdata);

		virtual void OnMouseEnter(int localx, int localy, int dx, int dy);
		virtual void OnMouseLeave(int localx, int localy, int dx, int dy);
		virtual void OnMouseMoved(int localx, int localy, int dx, int dy);
		virtual void OnMouseMovedInside(int localx, int localy, int dx, int dy);
		virtual void OnMouseHover(int localx, int localy);
		virtual void OnMouseDown(int localx, int localy, unsigned int button);
		virtual void OnMouseUp(int localx, int localy, unsigned int button);
		virtual void OnMouseClick(int localx, int localy, unsigned int button);
		virtual void OnMouseUnclick(int localx, int localy, unsigned int button);
		virtual void OnMouseWheel(int localx, int localy, int d);
		virtual void OnMouseWheelInside(int localx, int localy, int d);
		virtual void OnMouseWheelFocused(int localx, int localy, int d);
		virtual void OnKeyPress(int key, bool shift, bool ctrl, bool alt);
		virtual void OnKeyRelease(int key, bool shift, bool ctrl, bool alt);

		State* Parent;
	};
}

#endif // __SYS_COMPONENT_H__
