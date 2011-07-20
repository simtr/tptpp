#include "Layer.hpp"
#include "Particles/Particle.hpp"
#include "GlobalDefines.hpp"
#include "GlobalFunctions.hpp"
template<class T>void CreatePart(Layer& layer,int x,int y,int type){
for(int i =0; i < layer.MaxParts;i++)
    if(layer.Parts[i].Type==0){
        layer.Parts[i].ChangeType<T>(type);
        layer.Parts[i].SetPos(x,y,layer.PartTable);
    }
}
void CreatePartByLookup(Layer& layer,int x,int y,int type){
        switch (type){
            case METL:
            CreatePart<Metl>(layer,x,y,type);
        }
    }

