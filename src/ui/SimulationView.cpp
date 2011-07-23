#include <SFML/Graphics.hpp>
#include <ui/SimulationView.hpp>
#include <Renderer.hpp>
#include <Layer.hpp>

#include <iostream>
#include <string>

using namespace ui;

SimulationView::SimulationView(int x, int y, int width, int height):
Component(x, y, width, height),
renderer(NULL),
simulation(NULL)
{
}

void SimulationView::Tick(float dt)
{
}

void SimulationView::Draw(void* userdata)
{
    sf::RenderWindow* rw = reinterpret_cast<sf::RenderWindow*>(userdata);

	if(simulation && renderer)
	{
		renderer->Render(simulation, rw);
	}
}

void SimulationView::OnMouseUp(int x, int y, unsigned int button)
{

}

void SimulationView::OnMouseDown(int x, int y, unsigned int button)
{
	if(simulation)
	{
		//simulation->CreateParticle()
	}
}

void SimulationView::OnMouseEnter(int x, int y, int dx, int dy)
{

}

void SimulationView::OnMouseLeave(int x, int y, int dx, int dy)
{

}

void SimulationView::AttachRenderer(Renderer* newRenderer)
{
	renderer = newRenderer;
}

void SimulationView::AttachLayer(Layer* simLayer)
{
	simulation = simLayer;
}
