// new_game.cpp
// -----------------------------------------------
// Creates and renders placeholders/general layout
// of the game. It also deals (renders) the first 5
// cards.
// -----------------------------------------------

#include "../include/new_game.h"
#include "../include/sprites.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <algorithm>
#include <numeric>
#include <random>

// 2.5x scale of 'SPRITE_SIZE'
const sf::Vector2f NewGame::PH_SIZE(160.f, 240.f);
const float NewGame::MARGIN = 50.f;
std::vector<int> NewGame::deck(52);

// Generates placeholders for tableau, foundations, etc.
NewGame::NewGame(sf::RenderWindow &window) : window(window) {
  genRandDeck();

  // -- Pos offsets --
  pos.phStock = {MARGIN, MARGIN};
  pos.phWaste = {MARGIN, PH_SIZE.y + (2.f * MARGIN)};

  // Helpers
  float x1 = PH_SIZE.x + (3.f * MARGIN);
  float x2 = (PH_SIZE.x * 2.f) + (4.f * MARGIN);
  float x3 = (PH_SIZE.x * 3.f) + (5.f * MARGIN);

  float y1 = MARGIN;
  float y2 = PH_SIZE.y + (2.f * MARGIN);
  float y3 = (PH_SIZE.y * 2.f) + (3.f * MARGIN);

  // Top row
  pos.phTopL = {x1, y1};
  pos.phTop = {x2, y1};
  pos.phTopR = {x3, y1};

  // Mdl row
  pos.phLeft = {x1, y2};
  pos.phCenter = {x2, y2};
  pos.phRight = {x3, y2};

  // Btm row
  pos.phBtmL = {x1, y3};
  pos.phBtm = {x2, y3};
  pos.phBtmR = {x3, y3};

  // -- Placeholders for the stock, waste pile, tableau, and foundations --
  createPlaceholder(phStock, Clr::OnSecondary, pos.phStock);
  createPlaceholder(phWaste, Clr::Surface, pos.phWaste);

  // Top row
  createPlaceholder(phTopL, Clr::Accent, pos.phTopL);
  createPlaceholder(phTop, Clr::Secondary, pos.phTop);
  createPlaceholder(phTopR, Clr::Accent, pos.phTopR);

  // Mdl row
  createPlaceholder(phLeft, Clr::Secondary, pos.phLeft);
  createPlaceholder(phCenter, Clr::Secondary, pos.phCenter);
  createPlaceholder(phRight, Clr::Secondary, pos.phRight);

  // Btm row
  createPlaceholder(phBtmL, Clr::Accent, pos.phBtmL);
  createPlaceholder(phBtm, Clr::Secondary, pos.phBtm);
  createPlaceholder(phBtmR, Clr::Accent, pos.phBtmR);

  // Deal (render) the first 5 cards on the table
  dealInit();
  renderNewGame();
}

// Renders the placeholders and init sprites (first 5 cards)
void NewGame::renderNewGame() {
  // -- Placeholders --
  window.draw(phStock);
  window.draw(phWaste);

  // top row
  window.draw(phTopL);
  window.draw(phTop);
  window.draw(phTopR);

  // mdl row
  window.draw(phLeft);
  window.draw(phCenter);
  window.draw(phRight);

  // btm row
  window.draw(phBtmL);
  window.draw(phBtm);
  window.draw(phBtmR);

  // -- Sprites --
  window.draw(sprite.stock);
}

// Generates a random non-repeating deck
void NewGame::genRandDeck() {
  // Fill vector with consecutive values (starting at 1)
  std::iota(deck.begin(), deck.end(), 1);

  // -- Shuffle the deck (or vector) --
  std::random_device rd;
  static std::mt19937 gen(rd());
  std::shuffle(deck.begin(), deck.end(), gen);
}

// Centers sprite's origin
void NewGame::centerOrigin(sf::Sprite &sprite) {
  sprite.setOrigin(sprite.getLocalBounds().width / 2.f,
                   sprite.getLocalBounds().height / 2.f);
}

// Creates a generic placeholder (border)
void NewGame::createPlaceholder(sf::RectangleShape &ph, const sf::Color clr,
                                const sf::Vector2f &pos) {
  ph.setSize(PH_SIZE);
  ph.setFillColor(clr);
  ph.setPosition(pos);
}

// SomeFunc
void NewGame::dealInit() {
  centerOrigin(sprite.stock);
  sprite.stock.setTexture(LoadSprite::Texture);
  sprite.stock.setTextureRect(LoadSprite::card.heart.king);
  sprite.stock.setScale(LoadSprite::SPRITE_SCALE);
  sprite.stock.setPosition(pos.phStock.x - 32.f, pos.phStock.y - 48.f);
}
