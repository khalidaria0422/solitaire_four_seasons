// colors.h
// -----------------------------------------------
// Clr class provides global colors for UI theming.
// -----------------------------------------------

#pragma once
#include <SFML/Graphics/Color.hpp>

class Clr {
public:
  Clr() = default;

  static const sf::Color Primary;
  static const sf::Color Secondary;
  static const sf::Color Accent;
  static const sf::Color OnSecondary;
  static const sf::Color Surface;
  static const sf::Color Blur;
};
