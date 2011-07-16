#include "Particle.hpp"
template<class T> void Particle::ChangeType(int type){
	
	changeType<T>(this,type);
}
template<class T> void Particle::changeType(Particle* p, int type){
	delete this;
		p = new T;
	p->Type = type;
}
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