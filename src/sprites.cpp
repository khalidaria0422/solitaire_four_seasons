#include "../include/sprites.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <string>
#include <filesystem>

//---------- init consts ----------//
const std::string rootPath = std::filesystem::current_path().string(); // path to the root project dir

//---------- init statics ----------//
sf::Texture LoadSprite::Texture;
const sf::Vector2i LoadSprite::SPRITE_SIZE(64, 96);

//---------- class LoadSprite ----------//
//---------- 'structors ----------//
LoadSprite::LoadSprite(sf::RenderWindow& window) {
  sf::Sprite someSprite;
  someSprite.setTexture(Texture);
  someSprite.setTextureRect(sf::IntRect(SPRITE_SIZE.x * 2, SPRITE_SIZE.y * 5, SPRITE_SIZE.x, SPRITE_SIZE.y));
  someSprite.setScale(3.5f, 3.5f);
  window.draw(someSprite);
}

//---------- utilities ----------//
//---------- load 'playing_cards_sprite' ----------//
void LoadSprite::loadTexture() { if (!Texture.loadFromFile(rootPath + "/assets/textures/playing_cards_sprite.png")) std::cerr << "Failed to load the texture." << std::endl; }
