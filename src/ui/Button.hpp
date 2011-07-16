#ifndef UI_BUTTON_HPP
#define UI_BUTTON_HPP
#include <SFML/Graphics.hpp>
#include "Component.hpp"
#include <string>

namespace ui
{	
	class Button : public Component
	{
	public:
		Button(int x, int y, int width, int height, const std::string& buttonText);

		const std::string& ButtonText;

		virtual void OnMouseUp(int x, int y, unsigned int button);
		virtual void Repaint();
		void SetAction();
	private:

	};
}

#endif