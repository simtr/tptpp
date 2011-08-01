#ifndef RENDERER_HPP
#define RENDERER_HPP
#include "Layer.hpp"
#include <SFML/Graphics.hpp>

class Renderer
{
public:
    //A GLITCH WITH C++ IS THAT ALL VIRTUAL FUNCTIONS MUST BE DEFINED AND DECLARED IN THE HEADER!
        virtual void Render(Layer* simLayer, sf::RenderTarget* rt);
};
#endif
