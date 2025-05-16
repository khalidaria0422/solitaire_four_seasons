#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

//---------- class LoadSprite ----------//
class LoadSprite {
public:
  //---------- 'structors ----------//
  LoadSprite() = default;

  //---------- utils ----------//
  static void loadTexture();
  static void assignCoords();

  //---------- pub membs ----------//
  struct rankType { sf::IntRect ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king; };
  struct cardType { rankType heart, spade, club, diamond; sf::IntRect back; };
  static cardType card;
  static sf::Texture Texture;
  static const sf::Vector2f SPRITE_SCALE;

private:
  static const sf::Vector2i SPRITE_SIZE;
};
