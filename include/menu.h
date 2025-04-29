#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

/********** class Menu **********/
class Menu {
public:
  //---------- 'structors ----------//
  Menu(const sf::Vector2f& modalSize); 

  //---------- utilities ----------//
  void main(sf::RenderWindow& window);
  void settings(sf::RenderWindow& window);

private:
  static const sf::Vector2f BTN_SIZE;
  struct posType {
    float margTop;
    float margBtm;
    float margBtwn;
    sf::Vector2f modal;
    sf::Vector2f btnNewGame;
    sf::Vector2f btnSettings;
    sf::Vector2f btnExit;
  } pos;
  sf::RectangleShape modal;
  sf::RectangleShape btnNewGame;
  sf::RectangleShape btnSettings;
  sf::RectangleShape btnExit;
};
