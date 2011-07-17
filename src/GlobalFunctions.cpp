#include "GlobalFunctions.hpp"
#include "Layer.hpp"
template<class T>void CreatePart(Layer& layer,int x,int y,int type){
for(int i =0; i < layer.MaxParts;i++)
    if(layer.Parts[i].Type=0){
        layer.Parts[i].ChangeType<T>(type);
    }
}
