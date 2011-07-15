#inlcude "Layer.hpp"
Layer::Layer(int resX,int resY,int scaleFactor)
{
	ResX=resX;
	ResY=resY;
	ScaleFactor=scaleFactor;
	MaxParts = resX*resY;
	PartTable = new int[resX][resY];
	for(int i = 0; i <MaxParts;i++)
	Parts[i].Index=i;
}
Layer::~Layer(){
for(int i = 0; i < ResX;i++){
	delete[] PartTable[i];}
	delete Parts;
	
	
	}