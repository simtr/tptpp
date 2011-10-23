#include "Sandbox.hpp"

#include <ui/State.hpp>
#include <ui/Component.hpp>
#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace sim;

Sandbox::Sandbox(int width, int height, int subdivision) :
    base(width, height),
    renderer(width+1 ,height),
    simLayer(width, height, subdivision)
{
    srand ( time(NULL) );
    //testing
    int acc=1,vel=1;

    for(int i = 0; i < 1700;i++)
    {
        simLayer.Parts[i]->ChangeType<Metl>(METL);
        if(acc>798||acc<1)
        {
            vel*=-1;
        }
        acc+=vel;
        simLayer.Parts[i]->SetPos(acc,rand() % 600 ,simLayer.PartTable);
    }
}

void Sandbox::Draw(void *userdata)
{       sf::RenderWindow* rw = reinterpret_cast<sf::RenderWindow*>(userdata);
        renderer.Render(&simLayer, rw);
        State::Draw(userdata);


}
