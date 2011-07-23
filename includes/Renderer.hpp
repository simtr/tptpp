#ifndef RENDERER_HPP
#define RENDERER_HPP
#include "Layer.hpp"
#include <SFML/Graphics.hpp>

class Renderer
{
public:
	virtual void Render(Layer* simLayer, sf::RenderTarget* rt);
};
#endif
