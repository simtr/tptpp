#include <SFML/Graphics.hpp>
#include "Particles/Particle.hpp"
class Layer{
	public:
	int Resx,ResY,ScaleFactor;
	const int MaxParts;
	int** PartTable;
	Particle Parts[MaxParts];
	Layer(int,int,int){}
	~Layer(){}
	
	
	
};