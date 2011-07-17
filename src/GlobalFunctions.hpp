#ifndef _GLOBAL_FUNCTIONS
#define _GLOBAL_FUNCTIONS
#include "Layer.hpp"
#include "Particles/Metl.hpp"
template<class T>void CreatePart(Layer& layer,int x,int y, int type);
void CreatePartByLookup(Layer& layer,int x, int y, int type);
#endif
