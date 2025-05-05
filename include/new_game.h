#pragma once
#include "../include/colors.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <vector>

//---------- class NewGame ----------//
class NewGame {
public:
  //---------- 'structors ----------//
  NewGame(sf::RenderWindow& window);

  //---------- utilities ----------//
  void createPlaceholder(sf::RectangleShape& ph, const sf::Color clr, const sf::Vector2f& pos);

private:
  sf::RenderWindow& window;
  static const sf::Vector2f PH_SIZE;
  static const float MARGIN;

  struct posType {
    //---------- placeholder pos ----------//
    sf::Vector2f phHand;
    sf::Vector2f phWaste;

    // foundations
    sf::Vector2f phTopL;
    sf::Vector2f phTopR;
    sf::Vector2f phBtmL;
    sf::Vector2f phBtmR;

    // tableau
    sf::Vector2f phTop;
    sf::Vector2f phRight;
    sf::Vector2f phBtm;
    sf::Vector2f phLeft;
    sf::Vector2f phCenter;
  } pos;

  //---------- placeholder rects ----------//
  sf::RectangleShape phHand;
  sf::RectangleShape phWaste;

  // foundations
  sf::RectangleShape phTopL;
  sf::RectangleShape phTopR;
  sf::RectangleShape phBtmL;
  sf::RectangleShape phBtmR;

  // tableau
  sf::RectangleShape phTop;
  sf::RectangleShape phRight;
  sf::RectangleShape phBtm;
  sf::RectangleShape phLeft;
  sf::RectangleShape phCenter;

  //---------- storage ----------//
  std::vector<std::string> hand;
  std::vector<std::string> waste;

  // foundations
  std::vector<std::string> foundTopL;
  std::vector<std::string> foundTopR;
  std::vector<std::string> foundBtmL;
  std::vector<std::string> foundBtmR;

  // tableau
  std::vector<std::string> tabTop;
  std::vector<std::string> tabRight;
  std::vector<std::string> tabBtm;
  std::vector<std::string> tabLeft;
  std::vector<std::string> tabCenter;
};
