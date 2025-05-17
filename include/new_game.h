// new_game.h
// -----------------------------------------------
// NewGame class provides utils for generating a random
// deck, and creating placeholders/general layout of the
// game. It also handles rendering.
// -----------------------------------------------

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

class NewGame {
public:
  NewGame(sf::RenderWindow &window);

  // -- Utils --
  void renderNewGame();
  void genRandDeck();
  void centerOrigin(sf::Sprite &sprite);
  void createPlaceholder(sf::RectangleShape &ph, const sf::Color clr,
                         const sf::Vector2f &pos);
  void dealInit();

  // -- Pub membs --
  static std::vector<int> deck;
  static std::vector<std::string> stock;
  static std::vector<std::string> waste;

  // Foundations
  static std::vector<std::string> foundTopL;
  static std::vector<std::string> foundTopR;
  static std::vector<std::string> foundBtmL;
  static std::vector<std::string> foundBtmR;

  // Tableau
  static std::vector<std::string> tabTop;
  static std::vector<std::string> tabRight;
  static std::vector<std::string> tabBtm;
  static std::vector<std::string> tabLeft;
  static std::vector<std::string> tabCenter;

private:
  sf::RenderWindow &window;
  static const sf::Vector2f PH_SIZE;
  static const float MARGIN;

  struct spriteType {
    sf::Sprite stock;
    sf::Sprite waste;

    // Foundations
    sf::Sprite foundTopL;
    sf::Sprite foundTopR;
    sf::Sprite foundBtmL;
    sf::Sprite foundBtmR;

    // Tableau
    sf::Sprite tabTop;
    sf::Sprite tabRight;
    sf::Sprite tabBtm;
    sf::Sprite tabLeft;
    sf::Sprite tabCenter;
  } sprite;

  // -- Placeholder pos --
  struct posType {
    sf::Vector2f phStock;
    sf::Vector2f phWaste;

    // Foundations
    sf::Vector2f phTopL;
    sf::Vector2f phTopR;
    sf::Vector2f phBtmL;
    sf::Vector2f phBtmR;

    // Tableau
    sf::Vector2f phTop;
    sf::Vector2f phRight;
    sf::Vector2f phBtm;
    sf::Vector2f phLeft;
    sf::Vector2f phCenter;
  } pos;

  // -- Placeholder rects --
  sf::RectangleShape phStock;
  sf::RectangleShape phWaste;

  // Foundations
  sf::RectangleShape phTopL;
  sf::RectangleShape phTopR;
  sf::RectangleShape phBtmL;
  sf::RectangleShape phBtmR;

  // Tableau
  sf::RectangleShape phTop;
  sf::RectangleShape phRight;
  sf::RectangleShape phBtm;
  sf::RectangleShape phLeft;
  sf::RectangleShape phCenter;
};
