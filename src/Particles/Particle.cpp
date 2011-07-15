#include "Particle.hpp"
template<class T> Particle::ChangeType(){
	changeType<T>(this);	
}
template<class T> Particle::changeType(Particle* p){
	delete this;
		p = new T;
}