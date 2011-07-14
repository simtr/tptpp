#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

int main(int argc, char** argv){
	// Create the main window
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML Window thingy");
	// Start game loop
	while (App.IsOpened()){ 
		// Process events
		sf::Event Event;
		while (App.PollEvent(Event)){
			// Close window : exit
			if (Event.Type == sf::Event::Closed)
				App.Close();
			// Escape key : exit
			if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Keyboard::Escape))
				App.Close();
		}
		//Clear everything
		App.Clear();
		//random shapes
		App.Draw(sf::Shape::Line(10, 10, 710, 100, 15, sf::Color::Red));
		App.Draw(sf::Shape::Circle(200, 200, 100, sf::Color::Yellow, 10, sf::Color::Blue));
		App.Draw(sf::Shape::Rectangle(350, 200, 600, 350, sf::Color::Green));

		//random bouncy text
		static float textX = 100.0f;
		static float textY = 150.0f;
		static int changeX = 1;
		static int changeY = 1;
		textX += changeX;
		textY += changeY;
		if (textX > 600) changeX = -1;
		if (textY > 500) changeY = -1;
		if (textX <= 0) changeX = 1;
		if (textY <= 0) changeY = 1;

		sf::String String = "The Powder Toy";
		sf::Text Text(String);
		Text.SetColor(sf::Color(128, 128, 0));
		Text.Move(textX,textY);

		App.Draw(Text);

		//Draw everything
		App.Display();
	}
return EXIT_SUCCESS;
}