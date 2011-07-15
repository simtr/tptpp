#ifndef __SYS_COMPONENT_H__
#define __SYS_COMPONENT_H__
#include <vector>
#include <SFML/Graphics.hpp>

namespace ui
{	
	class Component
	{
	public:
		Component(int x, int y, int width, int height);
		~Component();

		bool Visible;
		bool Enabled;
		int Width;
		int Height;
		int X;
		int Y;
		sf::RenderImage Surface;
		Component* Parent;

		virtual void Tick(float dt);

		virtual void OnMouseEnter(int localx, int localy);
		virtual void OnMouseLeave(int localx, int localy);
		virtual void OnMouseMoved(int localx, int localy, int dx, int dy);
		virtual void OnMouseDown(int x, int y, unsigned int button);
		virtual void OnMouseUp(int x, int y, unsigned int button);
		virtual void OnMouseWheel(int localx, int localy, int d);
		virtual void OnKeyPress(int key, bool shift, bool ctrl, bool alt);
		virtual void OnKeyUnpress(int key, bool shift, bool ctrl, bool alt);
		
		virtual void ChildUpdate(Component *child);
		
		virtual void Add(Component *child);

		void SetSize(int width, int height);
		void SetPosition(int x, int y);
		void SetEnabled(bool enabled);
		
		virtual void Repaint();
		
	protected:
		std::vector<Component*> Children;
	};
}

#endif // __SYS_COMPONENT_H__