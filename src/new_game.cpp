#include "../include/new_game.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

const sf::Vector2f NewGame::PH_SIZE(150.f, 250.f);
const float NewGame::MARGIN = 50.f;

//---------- class NewGame ----------//
//---------- 'structors ----------//
NewGame::NewGame(sf::RenderWindow& window) : window(window) {
  //---------- pos offsets ----------//
  pos.phHand = {MARGIN, MARGIN};
  pos.phWaste = {MARGIN, PH_SIZE.y + (2 * MARGIN)};

  // helpers
  float x1 = PH_SIZE.x + (3 * MARGIN);
  float x2 = (PH_SIZE.x * 2) + (4 * MARGIN);
  float x3 = (PH_SIZE.x * 3) + (5 * MARGIN);

  float y1 = MARGIN;
  float y2 = PH_SIZE.y + (2 * MARGIN);
  float y3 = (PH_SIZE.y * 2) + (3 * MARGIN);

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
}

//---------- utilities ----------//
void NewGame::createPlaceholder(sf::RectangleShape& ph, const sf::Color clr, const sf::Vector2f& pos) {
  ph.setSize(PH_SIZE);
  ph.setFillColor(clr);
  ph.setPosition(pos);
}

