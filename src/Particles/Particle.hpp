#ifndef _PARTICLE_HPP
#define _PARTICLE_HPP
class Particle{
public:
	int X,Y,Type,LayerIndex;
	int Index;
	Particle(){Type = 0;return;};
	template<class T>void ChangeType(int);
	virtual void Logic(){};
	virtual void MoveLogic(int**);
	void SetPos(int x, int y, int** partTable);
private:
	template<class T>void changeType(Particle* p,int);
};
#endif
