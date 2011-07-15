#include "Particle.hpp"
template<class T> Particle::ChangeType(){
	changeType<T>(this);	
}
template<class T> Particle::changeType(Particle* p){
	delete this;
		p = new T;
}
void Particle::SetPos(int x, int y, int** partTable){
	partTable[x][y]=Index;
	X=x;
	Y=y;
	}
Particle::Particle(){}