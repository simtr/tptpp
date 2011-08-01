#include "Sandbox.hpp"

#include <ui/State.hpp>
#include <ui/Component.hpp>
#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace sim;

Sandbox::Sandbox(int width, int height, int subdivision) :
base(width, height),
renderer(),
simLayer(width, height, subdivision)
{
     srand ( time(NULL) );
    //testing
    for(int i = 0; i < 500;i++){
    simLayer.Parts[i]->ChangeType<Metl>(METL);
    simLayer.Parts[i]->SetPos(i,rand() % 501 ,simLayer.PartTable);
}
}

void Sandbox::Draw(void *userdata)
{
	State::Draw(userdata);
	sf::RenderWindow* rw = reinterpret_cast<sf::RenderWindow*>(userdata);
	renderer.Render(&simLayer, rw);
}
