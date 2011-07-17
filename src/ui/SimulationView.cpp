#include <SFML/Graphics.hpp>
#include "SimulationView.hpp"
#include "../ParticleRenderer.hpp"
#include "../Layer.hpp"
#include <iostream>
#include <string>

using namespace ui;

SimulationView::SimulationView(int x, int y, int width, int height):
Component(x, y, width, height),
renderer(NULL),
simulation(NULL)
{
	Repaint();
}

void SimulationView::Tick(float dt)
{
	Repaint();
}

void SimulationView::Repaint()
{
	if(simulation && renderer)
	{
		renderer->Render(simulation, &Surface);
	}

	Surface.Display();
	//Tell the parent that we've changed
	if(Parent)
	{
		Parent->OnChildUpdate(this);
	}
}

void SimulationView::OnMouseUp(int x, int y, unsigned int button)
{
	mousePressed = false;
	//Do action
	Repaint();
}

void SimulationView::OnMouseDown(int x, int y, unsigned int button)
{
	mousePressed = true;
	if(simulation)
	{
		//simulation->CreateParticle()
	}
	Repaint();
}

void SimulationView::OnMouseEnter(int x, int y)
{
	mouseOver = true;
	Repaint();
}

void SimulationView::OnMouseLeave(int x, int y)
{
	mouseOver = false;
	Repaint();
}

void SimulationView::AttachRenderer(ParticleRenderer *newRenderer)
{
	renderer = newRenderer;
}

void SimulationView::AttachLayer(Layer *simLayer)
{
	simulation = simLayer;
}