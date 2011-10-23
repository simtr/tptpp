#ifndef _PARTICLE_HPP
#define _PARTICLE_HPP

#include <iostream>

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Shape.hpp>

class Particle{
public:
	float X,Y;
	int Type,LayerIndex,Life,SprkLife,Ctype,XPos,YPos;
	//for extra temps if we need them.
	int Tmp[3];
	sf::Color partColor;
	int Index;
        void SetPos(float x, float y, Particle*** partTable);
        Particle(){Type =0; X=0.0f;Y=0.0f;return;};
    template<class T> void ChangeType(int type){
        changeType<T>(this,type);
}
	virtual void Logic(){};
	virtual void MoveLogic(Particle*** partTable);
	virtual void SpawnLogic(){}
        virtual void Render(sf::RenderTexture&){};

        sf::Shape GetSfPoint();
private:
template<class T> void changeType(Particle* p, int type){
        int X2 = this->X;
        int Y2 = this->Y;
        delete this;
        p = new T;
        p->Type = type;

        p->X=X2;
        p->Y=Y2;
}
};
#include <Particles/PartList.hpp>
#endif
