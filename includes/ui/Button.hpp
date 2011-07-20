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

		bool Toggleable;

		std::string ButtonText;

		virtual void OnMouseClick(int x, int y, unsigned int button);
		virtual void OnMouseUnclick(int x, int y, unsigned int button);
		virtual void OnMouseUp(int x, int y, unsigned int button);

		virtual void OnMouseEnter(int x, int y, int dx, int dy);
		virtual void OnMouseLeave(int x, int y, int dx, int dy);

		virtual void Draw(void* userdata);

        inline bool GetState() { return state; }
        virtual void DoAction(); //action of button what ever it may be

    protected:
        bool isButtonDown, state, isMouseInside;

	};
}

#endif
