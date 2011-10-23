#include <Particles/Metl.hpp>

Metl::Metl()
{
   partColor = sf::Color(55,55,55,255);
   myShape = sf::Shape::Rectangle(X,Y,1,1,partColor);
}

Metl::~Metl()
{
    //dtor
}
void Metl::Render(sf::RenderTexture& pixbuff)
{
    //pixbuff.SetPixel(XPos,YPos,sf::Color::Red); // devnote : since its not image, I'll do a temp drawing with shape::rect
    //pixbuff.Draw(sf::Shape::Rectangle(X,Y,1,1,partColor));
    myShape.SetPosition(X,Y);
    pixbuff.Draw(myShape);
}
