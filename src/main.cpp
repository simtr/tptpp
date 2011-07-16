#include <SFML/Graphics.hpp>
#include "../includes/ui/Component.hpp"
#include "../includes/ui/Panel.hpp"
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
		}

		window.Draw(mainPanelSprite);

		// Display current buffer
		window.Display();
	}
return EXIT_SUCCESS;
}
