#include "../include/menu.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

/********** static consts **********/
const sf::Vector2f Menu::BTN_SIZE(350.f, 100.f);

/********** class Menu **********/
//---------- 'structors ----------//
Menu::Menu(const sf::Vector2f& modalSize) {
  /********** pos offsets **********/
  float btnPosX = modalSize.x - (BTN_SIZE.x / 2.f); 
  pos.modal = {modalSize.x / 2.f, modalSize.y / 2.f};
  pos.btnNewGame = {btnPosX, (modalSize.y / 2.f) + BTN_SIZE.y};
  pos.btnSettings = {btnPosX, modalSize.y - (BTN_SIZE.y / 2)};
  pos.btnExit = {btnPosX, modalSize.y + (modalSize.y / 2.f) - (2 * BTN_SIZE.y)};

  /********** menu bg **********/
  modal.setSize(modalSize);
  modal.setFillColor(sf::Color(223, 208, 184));
  modal.setPosition(pos.modal);

  /********** menu btns **********/
  //---------- btn 'New Game' ----------//
  btnNewGame.setSize(BTN_SIZE);
  btnNewGame.setFillColor(sf::Color(57, 62, 60));
  btnNewGame.setPosition(pos.btnNewGame);

  //---------- btn 'Settings' ----------//
  btnSettings.setSize(BTN_SIZE);
  btnSettings.setFillColor(sf::Color(57, 62, 60));
  btnSettings.setPosition(pos.btnSettings);

  //---------- btn 'Exit' ----------//
  btnExit.setSize(BTN_SIZE);
  btnExit.setFillColor(sf::Color(57, 62, 60));
  btnExit.setPosition(pos.btnExit);
} 

//---------- utilities ----------//
void Menu::main(sf::RenderWindow& window) {
  window.draw(modal);
  window.draw(btnNewGame);
  window.draw(btnSettings);
  window.draw(btnExit);
}

