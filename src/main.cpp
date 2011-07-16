#include <SFML/Graphics.hpp>
#include "ui/Component.hpp"
#include "ui/Panel.hpp"
#include "ui/Button.hpp"
#include <string>
#include "Layer.hpp"
using namespace std;

int main(int argc, char** argv){
	int windowWidth = 800;
	int windowHeight = 600;
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight, 32), "The Powder Toy");
	// Create main panel
	ui::Panel mainPanel(0, 0, windowWidth, windowHeight);
	sf::Sprite mainPanelSprite(mainPanel.Surface.GetImage());
	// Other UI Components
	ui::Button testButton(20, 20, 60, 60, "ButtonTest");
	mainPanel.Add(&testButton);
	// Start game loop
	while (window.IsOpened()){
		// Process events
		sf::Event Event;
		while (window.PollEvent(Event)){
			// Close window : exit
			if (Event.Type == sf::Event::Closed)
				window.Close();
			// Escape key : exit
			if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Keyboard::Escape))
				window.Close();
			// Mouse events
			if (Event.Type == sf::Event::MouseButtonPressed || Event.Type == sf::Event::MouseButtonReleased)
			{
				int buttonCode = 0;
				switch(Event.MouseButton.Button)
				{
				case sf::Mouse::Left:
					buttonCode = 1;
					break;
				case sf::Mouse::Right:
					buttonCode = 4;
					break;
				case sf::Mouse::Middle:
					buttonCode = 2;
					break;
				default:
					buttonCode = 0;
				}
				if(Event.Type == sf::Event::MouseButtonPressed)
					mainPanel.OnMouseDown(Event.MouseButton.X, Event.MouseButton.Y, buttonCode);
				else
					mainPanel.OnMouseUp(Event.MouseButton.X, Event.MouseButton.Y, buttonCode);
			}
			if(Event.Type == sf::Event::MouseMoved)
			{
				mainPanel.OnMouseMoved(Event.MouseMove.X, Event.MouseMove.Y, 0, 0);
			}
		}
		window.Clear();

		window.Draw(mainPanelSprite);

		// Display current buffer
		window.Display();
	}
return EXIT_SUCCESS;
}
