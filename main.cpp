#include <SFML/Graphics.hpp>

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
			if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Keyboard::Key::Escape))
				App.Close();
		}
		//Clear everything
		App.Clear();
		//random shapes
		App.Draw(sf::Shape::Line(10, 10, 710, 100, 15, sf::Color::Red));
		App.Draw(sf::Shape::Circle(200, 200, 100, sf::Color::Yellow, 10, sf::Color::Blue));
		App.Draw(sf::Shape::Rectangle(350, 200, 600, 350, sf::Color::Green));
		//i get linker errors for text...
		/*sf::String String = "The Powder Toy";
		sf::Text Text(String);
		Text.SetColor(sf::Color(128, 128, 0));
		Text.SetRotation(90.f);
		Text.SetScale(2.f, 2.f);
		Text.Move(100.f, 200.f);
		*/ 
		//Draw everything
		App.Display();
	}
return EXIT_SUCCESS;
}