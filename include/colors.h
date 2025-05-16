#pragma once
#include <SFML/Graphics/Color.hpp>

//---------- class Font ----------//
class Clr {
public:
  //---------- 'structors ----------//
  Clr() = default;

  //---------- members ----------//
  static const sf::Color Primary;
  static const sf::Color Secondary;
  static const sf::Color Accent;
  static const sf::Color OnSecondary;
  static const sf::Color Surface;
  static const sf::Color Blur;
};

