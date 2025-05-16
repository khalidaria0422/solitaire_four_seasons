#pragma once
#include "../include/colors.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <vector>

//---------- class NewGame ----------//
class NewGame {
public:
  //---------- 'structors ----------//
  NewGame(sf::RenderWindow& window);

  //---------- utils ----------//
  void renderNewGame();
  void genRandDeck();
  void centerOrigin(sf::Sprite& sprite);
  void createPlaceholder(sf::RectangleShape& ph, const sf::Color clr, const sf::Vector2f& pos);
  void dealInit();

  //---------- pub membs ----------//
  static std::vector<int> deck;

  static std::vector<std::string> hand;
  static std::vector<std::string> waste;

  // foundations
  static std::vector<std::string> foundTopL;
  static std::vector<std::string> foundTopR;
  static std::vector<std::string> foundBtmL;
  static std::vector<std::string> foundBtmR;

  // tableau
  static std::vector<std::string> tabTop;
  static std::vector<std::string> tabRight;
  static std::vector<std::string> tabBtm;
  static std::vector<std::string> tabLeft;
  static std::vector<std::string> tabCenter;

private:
  sf::RenderWindow& window;
  static const sf::Vector2f PH_SIZE;
  static const float MARGIN;

  struct spriteType {
    sf::Sprite hand;
    sf::Sprite waste;

    // foundations
    sf::Sprite foundTopL;
    sf::Sprite foundTopR;
    sf::Sprite foundBtmL;
    sf::Sprite foundBtmR;

    // tableau
    sf::Sprite tabTop;
    sf::Sprite tabRight;
    sf::Sprite tabBtm;
    sf::Sprite tabLeft;
    sf::Sprite tabCenter;
  } sprite;

  //---------- placeholder pos ----------//
  struct posType {
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
};
