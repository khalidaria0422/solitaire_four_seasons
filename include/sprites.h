// sprites.h
// -----------------------------------------------
// LoadSprite class provides utils for loading the
// playing cards sprite sheet, and assigning each
// sprite to its respective rank and suit.
// -----------------------------------------------

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

class LoadSprite {
public:
  LoadSprite() = default;

  // Utils
  static void loadTexture();
  static void assignCoords();

  // -- Pub membs --
  struct rankType {
    sf::IntRect ace, two, three, four, five, six, seven, eight, nine, ten, jack,
        queen, king;
  };
  struct cardType {
    rankType heart, spade, club, diamond;
    sf::IntRect back;
  };
  static cardType card;
  static sf::Texture Texture;
  static const sf::Vector2f SPRITE_SCALE;

private:
  static const sf::Vector2i SPRITE_SIZE;
};
