#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <string>
#include<sstream>

#include "ui/Component.hpp"
#include "ui/Button.hpp"
#include "ui/State.hpp"
#include "Sandbox.hpp"
#include "Layer.hpp"
#include "Particles/Particle.hpp"
#include "GlobalDefines.hpp"
#include "GlobalFunctions.hpp"
using namespace std;

int main(int argc, char** argv){
    const int fpsmax=150;
    float FPS[fpsmax];
    for(int i = 0; i < fpsmax;i++)
        FPS[i]=60;
    float avgFPS;
	int windowWidth = 800;
	int windowHeight = 600;

	// Create the main window
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight, 32), "The Powder Toy");

	// Create instance of game
	sim::Sandbox sandboxGame(windowWidth, windowHeight, 4);

	// Other UI Components
	ui::Button testButton(20, 20, 60, 60, "ButtonTest");
        sandboxGame.Add(&testButton);
	//add a SimulationView component to Sandbox state

	float TICKRATE = 1000.f/60.f;
	double TickTime = 0;
        stringstream fps;
        fps<<"";
        sf::Text textGraphic(fps.str());
        textGraphic.SetCharacterSize(11);
        textGraphic.SetColor(sf::Color::White);
        textGraphic.SetPosition(650,5);
	sf::Clock clk;
	// Start game loop
        avgFPS=-10;
	while (window.IsOpened())
	{
		TickTime += clk.GetElapsedTime();
		clk.Reset();
                fps.str("");
                fps<<"FPS: ";
                avgFPS=0;
                for (int i = 0; i < fpsmax-1;i++){
                avgFPS+=FPS[i];
                FPS[i]=FPS[i+1];
                }
                FPS[fpsmax-1]= (1.0f / (float)(TickTime/1000));
                avgFPS+=FPS[fpsmax-1];
                avgFPS/=fpsmax;
                fps <<(int)avgFPS;
                textGraphic.SetString(fps.str());


		//Tick loop
		while(TickTime > TICKRATE)
		{
			TickTime -= TICKRATE;

			// Process events
			sf::Event Event;
			while (window.PollEvent(Event))
			{
				if(Event.Type == sf::Event::Closed) // Close window : exit
				{
					window.Close();
				}
				else if(Event.Type == sf::Event::KeyPressed)
				{
					if(Event.Key.Code == sf::Keyboard::Escape) // Escape key : exit
						window.Close();
				}
				else if(Event.Type == sf::Event::MouseButtonPressed)
				{
					int buttonCode = 0;
					switch(Event.MouseButton.Button)
					{
						case sf::Mouse::Left:
							buttonCode = 1;
							break;
						case sf::Mouse::Right:
							buttonCode = 3;
							break;
						case sf::Mouse::Middle:
							buttonCode = 2;
							break;
					}
					sandboxGame.OnMouseDown(Event.MouseButton.X, Event.MouseButton.Y, buttonCode);
				}
				else if(Event.Type == sf::Event::MouseButtonReleased)
				{
					int buttonCode = 0;
					switch(Event.MouseButton.Button)
					{
						case sf::Mouse::Left:
							buttonCode = 1;
							break;
						case sf::Mouse::Right:
							buttonCode = 3;
							break;
						case sf::Mouse::Middle:
							buttonCode = 2;
							break;
					}
					sandboxGame.OnMouseUp(Event.MouseButton.X, Event.MouseButton.Y, buttonCode);
				}
				else if(Event.Type == sf::Event::MouseMoved)
				{
					sandboxGame.OnMouseMove(Event.MouseMove.X, Event.MouseMove.Y);
				}
			}

			sandboxGame.Tick(TICKRATE);
		}

		window.Clear();
		sandboxGame.Draw(&window);
                window.Draw(textGraphic);
		window.Display();

	}

	window.Close();

	return EXIT_SUCCESS;
}
