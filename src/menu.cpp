#include "../include/menu.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

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
  createBtn(btnNewGame, pos.btnNewGame, lbl.btnNewGame, "New Game");
  createBtn(btnSettings, pos.btnSettings, lbl.btnSettings, "Settings");
  createBtn(btnExit, pos.btnExit, lbl.btnExit, "Exit");
} 

//---------- utilities ----------//
//---------- draw menu ----------//
void Menu::main(sf::RenderWindow& window) {
  window.draw(modal);
  window.draw(btnNewGame);
  window.draw(btnSettings);
  window.draw(btnExit);
  window.draw(lbl.btnNewGame);
  window.draw(lbl.btnSettings);
  window.draw(lbl.btnExit);
}

//---------- create btn ----------//
void Menu::createBtn(sf::RectangleShape& btn, const sf::Vector2f& pos, sf::Text& lbl, const std::string& name) {
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
