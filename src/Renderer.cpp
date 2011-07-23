#include <SFML/Graphics.hpp>
#include <Renderer.hpp>

void Renderer::Render(Layer* simLayer, sf::RenderTarget* rt)
{
	rt->Draw(sf::Shape::Circle(20, 20, 50, sf::Color::White));
}