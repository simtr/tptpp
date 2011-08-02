#include <Particles/Metl.hpp>

Metl::Metl()
{
    //ctor
}

Metl::~Metl()
{
    //dtor
}
void Metl::Render(sf::Image& pixbuff)
{
    pixbuff.SetPixel(XPos,YPos,sf::Color::Red);

}
