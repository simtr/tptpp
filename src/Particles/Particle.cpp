#ifndef _PARTICLE_CPP
#define _PARTICLE_CPP
#include <Particles/Particle.hpp>
void Particle::SetPos(int x, int y, int** partTable){
	partTable[X][Y]=0;
	partTable[x][y]=Index;
	X=x;
	Y=y;
}
void Particle::MoveLogic(int** partTable){
	if(partTable[X][Y+1]==0)
		SetPos(X,Y+1,partTable);
}
#endif
