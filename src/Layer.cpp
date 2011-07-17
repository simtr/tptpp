#include <Layer.hpp>
Layer::Layer(int resX,int resY,int scaleFactor)
{
	ResX=resX;
	ResY=resY;
	ScaleFactor=scaleFactor;
	MaxParts = resX*resY;
	PartTable = new int*[ResX];
	for(int i = 0; i<ResX;i++)
		PartTable[i] = new int[ResY];
	Parts = new Particle[MaxParts];
	for(int i = 0; i <MaxParts;i++){
		Parts[i].Index=i;
		Parts[i].LayerIndex=Index;
	}
}
Layer::~Layer(){
	for(int i = 0; i < ResX;i++){
		delete[] PartTable[i];
	}
	delete Parts;
}
