#include <Particles/Metl.hpp>

Metl::Metl()
{
    //ctor
}

Metl::~Metl()
{
    //dtor
}
void Metl::Render(sf::RenderTarget* rt)
{
rt->Draw(GetSfPoint());

}
