// fonts.h
// -----------------------------------------------
// Font class provides global font vars (reg and bold),
// and a function to load the fonts.
// -----------------------------------------------

#pragma once
#include <SFML/Graphics.hpp>

class Font {
public:
  Font() = default;

  static void loadFont();

  static sf::Font Reg;
  static sf::Font Bold;
};
