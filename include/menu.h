#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

//---------- class Menu ----------//
class Menu {
public:
  //---------- 'structors ----------//
  Menu(const sf::Vector2f& modalSize, const sf::Font& font); 

  //---------- utilities ----------//
  void renderMenu(sf::RenderWindow& window);
  void btnCreate(sf::RectangleShape& btn, const sf::Vector2f& pos, sf::Text& lbl, const std::string& name);
  bool btnHovering(const sf::RenderWindow& window, sf::RectangleShape& btn, const sf::Text& lbl);
  bool btnClicked(sf::RenderWindow& window, const sf::Event& event);
  void newGame();
 
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

class MenuSettings : public Menu {};
