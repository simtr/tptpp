#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <ui/Component.hpp>
#include <ui/Panel.hpp>
#include <ui/Button.hpp>
#include <ui/State.hpp>
#include <Sandbox.hpp>
#include <Layer.hpp>

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv){
	int windowWidth = 800;
	int windowHeight = 600;

	// Create the main window
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight, 32), "The Powder Toy");

    // Create instance of game
    sim::Sandbox sandboxGame(windowWidth, windowHeight, 4);

	// Other UI Components
	ui::Button testButton(20, 20, 60, 60, "ButtonTest");
	sandboxGame.Add(&testButton);

    float TICKRATE = 1000.f/60.f;
    double TickTime = 0;

    sf::Clock clk;
	// Start game loop
	while (window.IsOpened())
	{
	    TickTime += clk.GetElapsedTime();
	    clk.Reset();

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
		window.Display();
	}

    return EXIT_SUCCESS;
}
