#include "Sandbox.hpp"

#include <ui/State.hpp>
#include <ui/Component.hpp>

using namespace sim;

Sandbox::Sandbox(int width, int height, int subdivision) :
base(width, height),
renderer(),
simLayer(width, height, subdivision)
{

}

void Sandbox::Draw(void *userdata)
{
	State::Draw(userdata);
	sf::RenderWindow* rw = reinterpret_cast<sf::RenderWindow*>(userdata);
	renderer.Render(&simLayer, rw);
}
