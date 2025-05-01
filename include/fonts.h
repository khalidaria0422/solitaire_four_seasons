#pragma once
#include <SFML/Graphics.hpp>

//---------- class Font ----------//
class Font {
public:
  //---------- 'structors ----------//
  Font() = default;

  //---------- utilities ----------//
  static void loadFont();

  //---------- members ----------//
  static sf::Font Reg;
  static sf::Font Bold;
};
