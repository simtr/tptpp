#ifndef UI_PANEL_HPP
#define UI_PANEL_HPP
#include <SFML/Graphics.hpp>
#include "Component.hpp"

namespace ui
{
	class Panel : public Component
	{
	public:
		Panel(int x, int y, int width, int height);
		virtual void Add(Component *child);
		virtual void Draw();
	};
}

#endif
