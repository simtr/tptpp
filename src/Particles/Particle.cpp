#ifndef _PARTICLE_CPP
#define _PARTICLE_CPP
#include <Particles/Particle.hpp>
void Particle::SetPos(int x, int y, Particle*** partTable){
	partTable[X][Y]= 0;
	partTable[x][y]= this;
	X=x;
	Y=y;
}
void Particle::MoveLogic(Particle*** partTable){
	if(partTable[X][Y+1]==0)
		SetPos(X,Y+1,partTable);
}
#endif
