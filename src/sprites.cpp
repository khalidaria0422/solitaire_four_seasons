// sprites.cpp
// -----------------------------------------------
// Loads sprite sheet containing all 52 cards and the
// back. Assigns each rank in each suit the coords to their
// respective sprite.
// -----------------------------------------------

#include "../include/sprites.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <filesystem>
#include <iostream>
#include <string>

// Path to the root project dir
const std::string rootPath = std::filesystem::current_path().string();

sf::Texture LoadSprite::Texture;
LoadSprite::cardType LoadSprite::card;
const sf::Vector2i LoadSprite::SPRITE_SIZE(64, 96);
const sf::Vector2f LoadSprite::SPRITE_SCALE(3.5f, 3.5f);

void LoadSprite::loadTexture() {
  if (!Texture.loadFromFile(rootPath +
                            "/assets/textures/playing_cards_sprite.png"))
    std::cerr << "Failed to load the texture." << std::endl;
}

// Assigns sprite coords to each rank in each suit
void LoadSprite::assignCoords() {
  // Coords for back of the card
  card.back = {SPRITE_SIZE.x, SPRITE_SIZE.y * 5, SPRITE_SIZE.x, SPRITE_SIZE.y};

  for (int suit = 0; suit < 4; suit++) {
    rankType *currentSuit = nullptr;

    switch (suit) {
    case 0:
      currentSuit = &card.heart;
      break;
    case 1:
      currentSuit = &card.spade;
      break;
    case 2:
      currentSuit = &card.club;
      break;
    case 3:
      currentSuit = &card.diamond;
      break;
    }

    for (int rank = 0; rank < 13; rank++) {
      // New sprite coords is calced each 'rank' iter
      sf::IntRect rect(SPRITE_SIZE.x * rank, SPRITE_SIZE.y * suit,
                       SPRITE_SIZE.x, SPRITE_SIZE.y);

      // Assigns sprite coords to current 'rank' iter
      switch (rank) {
      case 0:
        currentSuit->ace = rect;
        break;
      case 1:
        currentSuit->two = rect;
        break;
      case 2:
        currentSuit->three = rect;
        break;
      case 3:
        currentSuit->four = rect;
        break;
      case 4:
        currentSuit->five = rect;
        break;
      case 5:
        currentSuit->six = rect;
        break;
      case 6:
        currentSuit->seven = rect;
        break;
      case 7:
        currentSuit->eight = rect;
        break;
      case 8:
        currentSuit->nine = rect;
        break;
      case 9:
        currentSuit->ten = rect;
        break;
      case 10:
        currentSuit->jack = rect;
        break;
      case 11:
        currentSuit->queen = rect;
        break;
      case 12:
        currentSuit->king = rect;
        break;
      }
    }
  }
}
