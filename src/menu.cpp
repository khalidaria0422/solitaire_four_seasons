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
const sf::Vector2f Menu::BTN_SIZE_SMALL(100.f, 50.f);

//---------- Class menu ----------//
//---------- 'structors ----------//
Menu::Menu(sf::RenderWindow& window, const sf::Font& font, const sf::Vector2f& modalSize) : window(window), font(font), modalSize(modalSize) {
  //---------- pos offsets ----------//
  float btnPosX = modalSize.x - (BTN_SIZE.x / 2.f); 
  pos.modal = {modalSize.x / 2.f, modalSize.y / 2.f};
  pos.btnNewGame = {btnPosX, (modalSize.y / 2.f) + BTN_SIZE.y};
  pos.btnSettings = {btnPosX, modalSize.y - (BTN_SIZE.y / 2.f)};
  pos.btnExit = {btnPosX, modalSize.y + (modalSize.y / 2.f) - (2.f * BTN_SIZE.y)};

  //---------- create menu modal ----------//
  modal.setSize(modalSize);
  modal.setFillColor(sf::Color(148, 137, 121));
  modal.setPosition(pos.modal);

  //---------- create menu btns ----------//
  btnCreate(btnNewGame, pos.btnNewGame, lbl.btnNewGame, "New Game");
  btnCreate(btnSettings, pos.btnSettings, lbl.btnSettings, "Settings");
  btnCreate(btnExit, pos.btnExit, lbl.btnExit, "Exit");
} 

//---------- utilities ----------//
//---------- render menu ----------//
void Menu::renderMenu() {
  // //---------- change btn bg clr when hovering ----------//
  btnHovering(btnNewGame, lbl.btnNewGame);
  btnHovering(btnSettings, lbl.btnSettings);
  btnHovering(btnExit, lbl.btnExit);

  window.draw(modal);
  window.draw(btnNewGame);
  window.draw(btnSettings);
  window.draw(btnExit);
  window.draw(lbl.btnNewGame);
  window.draw(lbl.btnSettings);
  window.draw(lbl.btnExit);

  if (showModalConf) confirmChoice(); // confirm choice for exit
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
bool Menu::btnHovering(sf::RectangleShape& btn, const sf::Text& lbl) {
  sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
  bool hovering = btn.getGlobalBounds().contains(mousePos);

  if (hovering) btn.setFillColor(lbl.getString() != "Exit" ? sf::Color(34, 40, 49) : sf::Color(170, 74, 68)); // accent color for 'Exit'
  else btn.setFillColor(sf::Color(57, 62, 60));

  return hovering;
}

//---------- btn click func ----------//
bool Menu::btnClicked(const sf::Event& event) {
  if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
    if (btnHovering(btnNewGame, lbl.btnNewGame)) return true;
    if (btnHovering(btnSettings, lbl.btnSettings)) std::cout << "btnSettings" << std::endl;
    if (btnHovering(btnExit, lbl.btnExit)) { showModalConf = true; }
  }

  return false;
}

//---------- confirm choice ----------//
void Menu::confirmChoice() {
  //---------- set pos offsets ----------//
  pos.modalConf = {modalSize.x - (modalSize.x / 4.f), modalSize.y - (modalSize.y / 4.f)};
  pos.btnYes = {pos.modalConf.x, pos.modalConf.y + (pos.modalConf.y / 2.f)};
  pos.btnNo = {pos.modalConf.x + (pos.modalConf.x / 2.f), pos.modalConf.y + (pos.modalConf.y / 2.f)};

  //---------- create confirm modal ----------//
  modalConf.setSize({modalSize.x / 2.f, modalSize.y / 2.f});
  modalConf.setFillColor(sf::Color(148, 137, 121));
  modalConf.setPosition(pos.modalConf);

  //---------- create confirm btns ----------//
  btnCreate(btnYes, pos.btnYes, lbl.btnYes, "Yes");
  btnCreate(btnNo, pos.btnNo, lbl.btnNo, "No");
  btnYes.setSize(BTN_SIZE_SMALL);
  btnNo.setSize(BTN_SIZE_SMALL);
  
  // create a dark overlay
  sf::RectangleShape blur(sf::Vector2f(window.getSize()));
  blur.setFillColor(sf::Color(0, 0, 0, 128));

  window.draw(blur);
  window.draw(modalConf);
  window.draw(btnYes);
  window.draw(btnNo);
}
