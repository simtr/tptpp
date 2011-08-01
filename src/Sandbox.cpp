#include "Sandbox.hpp"

#include <ui/State.hpp>
#include <ui/Component.hpp>
#include <iostream>

using namespace sim;

Sandbox::Sandbox(int width, int height, int subdivision) :
base(width, height),
renderer(),
simLayer(width, height, subdivision)
{
    //testing
    simLayer.Parts[0]->X=0;
    simLayer.Parts[0]->Y=0;
    simLayer.Parts[0]->ChangeType<Metl>(METL);
    simLayer.Parts[0]->SetPos(200,200,simLayer.PartTable);
}

void Sandbox::Draw(void *userdata)
{
	State::Draw(userdata);
	sf::RenderWindow* rw = reinterpret_cast<sf::RenderWindow*>(userdata);
	renderer.Render(&simLayer, rw);
}
