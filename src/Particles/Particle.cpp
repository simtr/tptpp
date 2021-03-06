#ifndef _PARTICLE_CPP
#define _PARTICLE_CPP
#include <Particles/Particle.hpp>
#include <iostream>
#include <SFML/OpenGL.hpp>
void Particle::SetPos(float x, float y, Particle*** partTable)
{
    partTable[(int)X][(int)Y]= 0;
    partTable[(int)x][(int)y]= this;
    X=x;
    Y=y;
    XPos = (int)X;
    YPos = (int)Y;
    //myShape = sf::Shape::Rectangle(X,Y,1,1,partColor);
}
void Particle::MoveLogic(Particle*** partTable)
{
    if(partTable[XPos][YPos+1]==0)
    {
        SetPos(X,Y+1,partTable);
    }
}
sf::Shape Particle::GetSfPoint()
{
    return(sf::Shape::Rectangle(sf::FloatRect(X,Y,1,1),sf::Color::Red));
}
void Particle::Render(sf::RenderTexture& pixbuff)
{
    /*myShape.SetPosition(X,Y); // trying points
    pixbuff.Draw(myShape);*/
    glPointSize(10.0f);
    glBegin(GL_POINTS);
    glColor3f(partColor.r, partColor.g, partColor.b);
    glVertex2f(X,Y);
    glEnd();
}

#endif
