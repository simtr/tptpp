#ifndef _PARTICLE_HPP
#define _PARTICLE_HPP
#include <SFML/Graphics.hpp>
class Particle{
public:
	int X,Y,Type,LayerIndex,Life,SprkLife,Ctype;
	//for extra temps if we need them.
	int Tmp[3];
	sf::Color partColor;
	int Index;
	Particle(){Type = 0;return;};
    template<class T> void ChangeType(int type){
	changeType<T>(this,type);
}
	virtual void Logic(){};
	virtual void MoveLogic(int** partTable);
	virtual void Render(sf::RenderWindow*){};
	void SetPos(int x, int y, int** partTable);
private:
template<class T> void changeType(Particle* p, int type){
	delete this;
	p = new T;
	p->Type = type;
}
};
#endif
