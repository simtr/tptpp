#include <Particles/Metl.hpp>

Metl::Metl()
{
    //ctor
}

Metl::~Metl()
{
    //dtor
}
void Metl::Render(sf::RenderTexture& pixbuff)
{
    //pixbuff.SetPixel(XPos,YPos,sf::Color::Red); // devnote : since its not image, I'll do a temp drawing with shape::rect
    pixbuff.Draw(sf::Shape::Rectangle(X,Y,1,1,partColor));
}
