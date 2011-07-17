#ifndef PARTICLERENDERER_HPP
#define PARTICLERENDERER_HPP
#include "Layer.hpp"
#include <SFML/Graphics.hpp>

class ParticleRenderer
{
public:
	virtual void Render(Layer* simLayer, sf::RenderTarget* rt);
};
#endif
