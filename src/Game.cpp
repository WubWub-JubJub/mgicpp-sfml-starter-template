
#include "Game.h"
#include <iostream>
#include <string>

Game::Game(sf::RenderWindow& game_window)
	: window(game_window)
{
  srand(time(NULL)); //seeds random number generator with the current time
}

Game::~Game()
{
 // Branch change testing testing 
}

// We call this once after the game class is instantiated
bool Game::init()
{
	if (in_menu == true)
	{
		if (!font.openFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
		{
			std::cout << "title text not loaded" << std::endl;
		}
		window.clear(sf::Color::Black);
		menu_text.setString("Whack a Mole");
		menu_text.setFont(font);
		menu_text.setCharacterSize(100);
		menu_text.setFillColor(sf::Color::Red);
		menu_text.setPosition({ 200, 50});
		window.draw(menu_text);
		play_text.setString("> Play <");
		play_text.setFont(font);
		play_text.setCharacterSize(72);
		play_text.setFillColor(sf::Color::White);
		play_text.setPosition({400, 250});
		window.draw(play_text);
		quit_text.setString("Quit");
		quit_text.setFont(font);
		quit_text.setCharacterSize(72);
		quit_text.setFillColor(sf::Color::White);
		quit_text.setPosition({ 400, 400 });
		window.draw(quit_text);

	}
	if (!background_texture.loadFromFile("../Data/Images/WhackaMole Worksheet/background.png"))
	{
		std::cout << "Failed to load background texture" << std::endl;
	}

	else (background_texture.loadFromFile("../Data/Images/WhackaMole Worksheet/background.png"));
	{
		std::cout << "background loaded" << std::endl;

	}
	background = sf::Sprite(background_texture);

	if (!bird_texture.loadFromFile("../Data/Images/WhackaMole Worksheet/bird.png"))
	{
		std::cout << " Failed to load bird " << std::endl;
	}
	
	bird = sf::Sprite(bird_texture);
	bird.setPosition({ 100,100 });

	if (!font.openFromFile("../Data/Fonts/OpenSans-Bold.ttf")) 
	{
		std::cout << "title text not loaded" << std::endl;
	}
	title_text.setString("Whack a mole");
	title_text.setFont(font);
	title_text.setCharacterSize(100);
	title_text.setFillColor(sf::Color::Red);
	title_text.setPosition({ 200,50 });
	;
	return true;
}

// Update runs after event polling and before rendering
// use it for everything that needs to update between frames
void Game::update(float dt)
{

}

// Runs after update, use it to tell the window what to draw this frame
void Game::render()
{
	if (in_menu == true)
	{
		window.draw(menu_text);
		window.draw(play_text);
		window.draw(quit_text);
	}
	if (in_menu == false) 
	{
		window.draw(background = sf::Sprite(background_texture));
		window.draw(bird);
		window.draw(title_text);
	}
}

//Called by event polling when a MouseButtonPressed event is found
void Game::mouseButtonPressed(const sf::Event::MouseButtonPressed* event)
{
	// Event contains mouse position and which button was clicked

	// Don't need to extract position to a variable like this, this is just to show you it's a Vector2i
	sf::Vector2i position = event->position;

	// You can tell which button was pressed by comparing it to SFML's definitions of mouse buttons
	if (event->button == sf::Mouse::Button::Left)
	{
		//Left mouse button was pressed
	}
}

//Called by event polling when a MouseButtonReleased event is found
void Game::mouseButtonReleased(const sf::Event::MouseButtonReleased* event)
{
	//Works the same as MouseButtonPressed
	if (event->button == sf::Mouse::Button::Left)
	{
		//Left mouse button was released
	}
}

// Called by event polling when a KeyPressed event is found
void Game::keyPressed(const sf::Event::KeyPressed* event)
{
	// You can tell which button was pressed by the scancode to SFML's definitions of keyboard keys
	if ((event->scancode == sf::Keyboard::Scancode::W) || (event->scancode == sf::Keyboard::Scancode::S))
	{
		play_selected = !play_selected;
		if (play_selected) 
		{
			play_text.setString("> Play < ");
			quit_text.setString(" Quit ");
		}
		if (!play_selected)
		{
			play_text.setString(" Play ");
			quit_text.setString(" > Quit <");
		}
	}
	else if (event->scancode == sf::Keyboard::Scancode::Enter)
	{
		if (play_selected)
		{
			in_menu = false;

		}
		else
		{
			window.close();
		}
	}
}

// Called by event polling when a KeyReleased event is found
void Game::keyReleased(const sf::Event::KeyReleased* event)
{
	// Works the same way as KeyPressed
	if (event->scancode == sf::Keyboard::Scancode::W)
	{
		// W was released
	}

}


