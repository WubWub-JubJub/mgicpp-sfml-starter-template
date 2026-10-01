
#ifndef SFML_GAME_H
#define SFML_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseButtonPressed(const sf::Event::MouseButtonPressed* event);
  void mouseButtonReleased(const sf::Event::MouseButtonReleased* event);
  void keyPressed(const sf::Event::KeyPressed* event);
  void keyReleased(const sf::Event::KeyReleased* event);

 private:
  sf::RenderWindow& window;
  
  sf::Texture background_texture;
  sf::Sprite background = sf::Sprite(background_texture);

  sf::Texture bird_texture;
  sf::Sprite bird = sf::Sprite(bird_texture);

  sf::Font font;
  sf::Text title_text = sf::Text(font);
  sf::Text text = sf::Text(font);

  bool in_menu = true; 
  sf::Text play_text = sf::Text(font);
  sf::Text quit_text = sf::Text(font);
  sf::Text play_option = sf::Text(font);
  sf::Text quit_option = sf::Text(font);
  sf::Text menu_text = sf::Text(font);
  bool play_selected = true;

 

};

#endif // SFML_GAME_H
