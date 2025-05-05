#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

//---------- class LoadSprite ----------//
class LoadSprite {
public:
  //---------- 'structors ----------//
  LoadSprite(sf::RenderWindow& window);

  //---------- utilities ----------//
  static void loadTexture();

private:
  static sf::Texture Texture;
  static const sf::Vector2i SPRITE_SIZE;
};
