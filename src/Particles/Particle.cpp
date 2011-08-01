#ifndef _PARTICLE_CPP
#define _PARTICLE_CPP
#include <Particles/Particle.hpp>
#include <iostream>
void Particle::SetPos(float x, float y, Particle*** partTable){
        partTable[(int)X][(int)Y]= 0;
	partTable[(int)x][(int)y]= this;
	X=x;
	Y=y;
        XPos = (int)X;
        YPos = (int)Y;

}
void Particle::MoveLogic(Particle*** partTable){
        if(partTable[XPos][YPos+1]==0)
                SetPos(X,Y+1,partTable);
}
sf::Shape Particle::GetSfPoint(){
    return(sf::Shape::Circle(sf::Vector2f(X,Y),1,sf::Color::Blue));

}
#endif
