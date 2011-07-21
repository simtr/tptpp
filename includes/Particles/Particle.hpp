#ifndef _PARTICLE_HPP
#define _PARTICLE_HPP
#include <SFML/Graphics.hpp>
class Particle{
public:
	float X,Y;
	int Type,LayerIndex,Life,SprkLife,Ctype,XPos,YPos;
	//for extra temps if we need them.
	int Tmp[3];
	sf::Color partColor;
	int Index;
	Particle(){Type = 0;return;};
    template<class T> void ChangeType(int type){
	changeType<T>(this,type);
}
	virtual void Logic(){};
	virtual void MoveLogic(Particle*** partTable);
	virtual void SpawnLogic(){}
	virtual void Render(sf::RenderWindow*){};
	void SetPos(float x, float y, Particle*** partTable);
private:
template<class T> void changeType(Particle* p, int type){
	delete this;
	p = new T;
	p->Type = type;
}
};
#endif
