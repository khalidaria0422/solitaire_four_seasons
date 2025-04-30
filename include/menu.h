#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

//---------- class Menu ----------//
class Menu {
public:
  //---------- 'structors ----------//
  Menu(const sf::Vector2f& modalSize, const sf::Font& font); 

  //---------- utilities ----------//
  void main(sf::RenderWindow& window);
  void settings(sf::RenderWindow& window);
  void createBtn(sf::RectangleShape& btn, const sf::Vector2f& pos, sf::Text& lbl, const std::string& name);

private:
  sf::Font font;
  static const sf::Vector2f BTN_SIZE;

  struct posType {
    sf::Vector2f modal;
    sf::Vector2f btnNewGame;
    sf::Vector2f btnSettings;
    sf::Vector2f btnExit;
  } pos;
 
  struct lblType {
    sf::Text btnNewGame;
    sf::Text btnSettings;
    sf::Text btnExit;
  } lbl;

  sf::RectangleShape modal;
  sf::RectangleShape btnNewGame;
  sf::RectangleShape btnSettings;
  sf::RectangleShape btnExit;
};
