#ifndef SANDBOX_HPP
#define SANDBOX_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <ui/State.hpp>

namespace sim
{
    typedef ui::State base;

	class Sandbox : public ui::State
	{
	public:
		/* Construct sandbox with the given size (in particles) and the scaling
		factor for low resolution simulation (air, gravity, etc...) */
		Sandbox(int width, int height, int subdivision);
	};
}
#endif
