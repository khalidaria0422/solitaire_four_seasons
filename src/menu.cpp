#include "../include/menu.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>

//---------- static consts ----------//
const sf::Vector2f Menu::BTN_SIZE(350.f, 100.f);

//---------- Class menu ----------//
//---------- 'structors ----------//
Menu::Menu(const sf::Vector2f& modalSize, const sf::Font& font) : font(font) {
  //---------- pos offsets ----------//
  float btnPosX = modalSize.x - (BTN_SIZE.x / 2.f); 
  pos.modal = {modalSize.x / 2.f, modalSize.y / 2.f};
  pos.btnNewGame = {btnPosX, (modalSize.y / 2.f) + BTN_SIZE.y};
  pos.btnSettings = {btnPosX, modalSize.y - (BTN_SIZE.y / 2)};
  pos.btnExit = {btnPosX, modalSize.y + (modalSize.y / 2.f) - (2 * BTN_SIZE.y)};

  //---------- menu bg ----------//
  modal.setSize(modalSize);
  modal.setFillColor(sf::Color(148, 137, 121));
  modal.setPosition(pos.modal);

  //---------- menu btns ----------//
  btnCreate(btnNewGame, pos.btnNewGame, lbl.btnNewGame, "New Game");
  btnCreate(btnSettings, pos.btnSettings, lbl.btnSettings, "Settings");
  btnCreate(btnExit, pos.btnExit, lbl.btnExit, "Exit");
} 

//---------- utilities ----------//
//---------- draw menu ----------//
void Menu::renderMenu(sf::RenderWindow& window) {
  // //---------- change btn bg clr when hovering ----------//
  btnHovering(window, btnNewGame, lbl.btnNewGame);
  btnHovering(window, btnSettings, lbl.btnSettings);
  btnHovering(window, btnExit, lbl.btnExit);

  window.draw(modal);
  window.draw(btnNewGame);
  window.draw(btnSettings);
  window.draw(btnExit);
  window.draw(lbl.btnNewGame);
  window.draw(lbl.btnSettings);
  window.draw(lbl.btnExit);
}

//---------- create btn ----------//
void Menu::btnCreate(sf::RectangleShape& btn, const sf::Vector2f& pos, sf::Text& lbl, const std::string& name) {
  btn.setSize(BTN_SIZE);
  btn.setFillColor(sf::Color(57, 62, 60));
  btn.setPosition(pos);

  lbl.setFont(font);
  lbl.setString(name);
  lbl.setCharacterSize(36);
  lbl.setFillColor(sf::Color(223, 208, 184));

  sf::FloatRect lblBnds = lbl.getLocalBounds();
  lbl.setOrigin(lblBnds.left + lblBnds.width / 2.f, lblBnds.top + lblBnds.height / 2.f); // set label origin to center
  lbl.setPosition(pos.x + (BTN_SIZE.x / 2.f), pos.y + (BTN_SIZE.y / 2.f));
}

//---------- btn hover func (changes bg clr) ----------//
bool Menu::btnHovering(const sf::RenderWindow& window, sf::RectangleShape& btn, const sf::Text& lbl) {
  sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
  bool hovering = btn.getGlobalBounds().contains(mousePos);

  if (hovering)
    lbl.getString() != "Exit" ? btn.setFillColor(sf::Color(34, 40, 49)) : btn.setFillColor(sf::Color(170, 74, 68));
  else 
    btn.setFillColor(sf::Color(57, 62, 60));

  return hovering;
}

bool Menu::btnClicked(sf::RenderWindow& window, const sf::Event& event) {
  if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
    if (btnHovering(window, btnNewGame, lbl.btnNewGame)) { newGame(); return true; }
    if (btnHovering(window, btnSettings, lbl.btnSettings)) std::cout << "btnSettings" << std::endl;
    if (btnHovering(window, btnExit, lbl.btnExit)) window.close(); 
  }

  return false;
}

void Menu::newGame() {}
