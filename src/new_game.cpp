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

//---------- init statics ----------//
const sf::Vector2f NewGame::PH_SIZE(160.f, 240.f); // 2.5 scale of 'SPRITE_SIZE'
const float NewGame::MARGIN = 50.f;
std::vector<int> NewGame::deck(52); // create the 52 card deck

//---------- class NewGame ----------//
//---------- 'structors ----------//
NewGame::NewGame(sf::RenderWindow& window) : window(window) {
  genRandDeck();

  //---------- pos offsets ----------//
  pos.phHand = {MARGIN, MARGIN};
  pos.phWaste = {MARGIN, PH_SIZE.y + (2.f * MARGIN)};

  // helpers
  float x1 = PH_SIZE.x + (3.f * MARGIN);
  float x2 = (PH_SIZE.x * 2.f) + (4.f * MARGIN);
  float x3 = (PH_SIZE.x * 3.f) + (5.f * MARGIN);

  float y1 = MARGIN;
  float y2 = PH_SIZE.y + (2.f * MARGIN);
  float y3 = (PH_SIZE.y * 2.f) + (3.f * MARGIN);

  // top row
  pos.phTopL = {x1, y1};
  pos.phTop = {x2, y1};
  pos.phTopR = {x3, y1};

  // mdl row
  pos.phLeft = {x1, y2};
  pos.phCenter = {x2, y2};
  pos.phRight = {x3, y2};

  // btm row
  pos.phBtmL = {x1, y3};
  pos.phBtm = {x2, y3};
  pos.phBtmR = {x3, y3};

  createPlaceholder(phHand, Clr::OnSecondary, pos.phHand);
  createPlaceholder(phWaste, Clr::Surface, pos.phWaste);

  // top row
  createPlaceholder(phTopL, Clr::Accent, pos.phTopL);
  createPlaceholder(phTop, Clr::Secondary, pos.phTop);
  createPlaceholder(phTopR, Clr::Accent, pos.phTopR);

  // mdl row
  createPlaceholder(phLeft, Clr::Secondary, pos.phLeft);
  createPlaceholder(phCenter, Clr::Secondary, pos.phCenter);
  createPlaceholder(phRight, Clr::Secondary, pos.phRight);

  // btm row
  createPlaceholder(phBtmL, Clr::Accent, pos.phBtmL);
  createPlaceholder(phBtm, Clr::Secondary, pos.phBtm);
  createPlaceholder(phBtmR, Clr::Accent, pos.phBtmR);

  dealInit();
  renderNewGame(); // render all objects
}

//---------- utilities ----------//
//---------- render objects ----------//
void NewGame::renderNewGame() {
  //---------- placeholders ----------//
  window.draw(phHand);
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

  //---------- sprites ----------//
  window.draw(sprite.hand);
}

//---------- generate a random non-repeating deck ----------//
void NewGame::genRandDeck() {
  std::iota(deck.begin(), deck.end(), 1); // fill vector with consecutive values (starting at 1)
  std::random_device rd;
  static std::mt19937 gen(rd());
  std::shuffle(deck.begin(), deck.end(), gen); // shuffle the deck based on gen
}

//---------- helper for centering sprite origin ----------//
void NewGame::centerOrigin(sf::Sprite& sprite) { sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f); }

//---------- helper for creating placeholders ----------//
void NewGame::createPlaceholder(sf::RectangleShape& ph, const sf::Color clr, const sf::Vector2f& pos) {
  ph.setSize(PH_SIZE);
  ph.setFillColor(clr);
  ph.setPosition(pos);
}

//---------- someFunc ----------//
void NewGame::dealInit() {
  centerOrigin(sprite.hand);
  sprite.hand.setTexture(LoadSprite::Texture);
  sprite.hand.setTextureRect(LoadSprite::card.heart.king);
  sprite.hand.setScale(LoadSprite::SPRITE_SCALE);
  sprite.hand.setPosition(pos.phHand.x - 32.f, pos.phHand.y - 48.f);
}
