#ifndef RENDERER_HPP
#define RENDERER_HPP
#include "Layer.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

class Renderer
{
public:
    //A GLITCH WITH C++ IS THAT ALL VIRTUAL FUNCTIONS MUST BE DEFINED AND DECLARED IN THE HEADER!
        virtual void Render(Layer* simLayer, sf::RenderTarget* rt);
        Renderer(int,int);
        int Width,Height;
        sf::RenderTexture PixBuff;
        sf::Sprite spr;
};
#endif
