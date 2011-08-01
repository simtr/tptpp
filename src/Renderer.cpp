#include <SFML/Graphics.hpp>
#include <Renderer.hpp>
#include <iostream>
void Renderer::Render(Layer* simLayer, sf::RenderTarget* rt){
    std::cout<<"here"<<std::endl;
    for(int i = 0; i < simLayer->MaxParts;i++){
        if( simLayer->Parts[i].Type){
        simLayer->Parts[i].Render(rt);
    }

    }
    rt->Draw(sf::Shape::Circle(20, 20, 50, sf::Color::White));
}
