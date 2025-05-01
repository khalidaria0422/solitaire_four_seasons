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
  Menu(sf::RenderWindow& window, const sf::Vector2f& modalSize);

  //---------- utilities ----------//
  void renderMenu();
  void btnCreate(sf::RectangleShape& btn, const sf::Vector2f& btnSize, const sf::Vector2f& pos, sf::Text& lbl, const std::string& name);
  bool btnHovering(sf::RectangleShape& btn, const sf::Text& lbl);
  bool btnClicked(const sf::Event& event);
  void confirmChoice();

private:
  sf::RenderWindow& window;
  const sf::Vector2f& modalSize;
  static const sf::Vector2f BTN_SIZE;
  static const sf::Vector2f BTN_SIZE_SMALL;

  struct posType {
    sf::Vector2f modal;
    sf::Vector2f btnNewGame;
    sf::Vector2f btnSettings;
    sf::Vector2f btnExit;

    sf::Vector2f modalConf;
    sf::Vector2f confTitle;
    sf::Vector2f confDesc;
    sf::Vector2f btnYes;
    sf::Vector2f btnNo;
  } pos;
 
  struct lblType {
    sf::Text title;
    sf::Text btnNewGame;
    sf::Text btnSettings;
    sf::Text btnExit;

    sf::Text confTitle;
    sf::Text confDesc;
    sf::Text btnYes;
    sf::Text btnNo;
  } lbl;

  sf::RectangleShape modal;
  sf::RectangleShape btnNewGame;
  sf::RectangleShape btnSettings;
  sf::RectangleShape btnExit;

  sf::RectangleShape modalConf;
  sf::RectangleShape btnYes;
  sf::RectangleShape btnNo;
  bool showModalConf = false;
};

