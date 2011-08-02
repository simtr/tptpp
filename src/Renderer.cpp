#include <SFML/Graphics.hpp>
#include <Renderer.hpp>
#include <iostream>
#include <GlobalDefines.hpp>
void Renderer::Render(Layer* simLayer, sf::RenderTarget* rt){

        PixBuff.Create(Width,Height);

     for(int i = 0; i < simLayer->MaxParts;i++){
        if( simLayer->Parts[i]->Type){
        simLayer->Parts[i]->Render(PixBuff);
        }
    }
     spr.SetImage(PixBuff);
     rt->Draw(spr);
    //rt->Draw(sf::Shape::Circle(20, 20, 50, sf::Color::White));
}
Renderer::Renderer(int width, int height)
{


    spr.SetPosition(0,0);

Width = width;
Height = height;

}

