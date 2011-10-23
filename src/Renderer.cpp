#include <SFML/Graphics.hpp>
#include <Renderer.hpp>
#include <iostream>
#include <GlobalDefines.hpp>
void Renderer::Render(Layer* simLayer, sf::RenderTarget* rt)
{
    PixBuff.Clear();

    for(int i = 0; i < simLayer->MaxParts;i++)
    {
        if( simLayer->Parts[i]->Type)
        {
            simLayer->Parts[i]->Render(PixBuff);
        }
    }
    PixBuff.Display(); // display content on the rendertexture, ready to draw on screen now
    spr.SetTexture(PixBuff.GetTexture()); // get texture from the rendertexture
    rt->Draw(spr);
    //rt->Draw(sf::Shape::Circle(20, 20, 50, sf::Color::White));
}
Renderer::Renderer(int width, int height)
{
    spr.SetPosition(0,0);

    Width = width;
    Height = height;
    PixBuff.Create(Width,Height);
}

