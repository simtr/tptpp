#inlcude "Layer.hpp"
Layer::Layer()
{
	MaxParts = 612*384;
	for(int i = 0; i <MaxParts;i++)
	Parts[i].Index=i;
}