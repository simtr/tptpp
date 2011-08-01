#include <SFML/Graphics.hpp>
#include <Renderer.hpp>
#include <iostream>
#include <GlobalDefines.hpp>
void Renderer::Render(Layer* simLayer, sf::RenderTarget* rt){

    for(int i = 0; i < 100000;i++){
        if( simLayer->Parts[i]->Type){
        simLayer->Parts[i]->Render(rt);
    }


        }
    rt->Draw(sf::Shape::Circle(20, 20, 50, sf::Color::White));
}
