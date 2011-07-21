#ifndef _LAYER_HPP
#define _LAYER_HPP
#include <SFML/Graphics.hpp>
#include <Particles/Particle.hpp>
class Layer{
public:
	int Index;
	int ResX,ResY,ScaleFactor;
	int MaxParts;
	Particle*** PartTable;
	Particle* Parts;
	Layer(int,int,int);
	~Layer();
};
#endif
