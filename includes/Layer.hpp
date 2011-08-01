#ifndef _LAYER_HPP
#define _LAYER_HPP
#include <SFML/Graphics.hpp>
#include <Particles/Particle.hpp>
#include <vector>
class Layer{
public:
	int Index;
	int ResX,ResY,ScaleFactor;
	int MaxParts;
	Particle*** PartTable;
        std::vector<Particle*> Parts;
	Layer(int,int,int);
	~Layer();
};
#endif
