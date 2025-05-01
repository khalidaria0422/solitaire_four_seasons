#include "../include/menu.h"
#include "../include/fonts.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/*
clr primary: 34, 40, 49
clr secondary: 57, 62, 60
clr accent: 170, 74, 68
clr onSecondary: 148, 137, 121
clr surface: 223, 208, 184
sf
*/

//---------- init consts ----------//
const sf::Vector2i SIZE_WIN(1920, 1080);
const sf::Vector2f SIZE_MENU(static_cast<float>(SIZE_WIN.x) / 2.f, static_cast<float>(SIZE_WIN.y) / 2.f);

int main() {
  //---------- init vars/objs ----------//
  sf::RenderWindow window(sf::VideoMode(SIZE_WIN.x, SIZE_WIN.y), "Solitaire Four Seasons");
  window.setVerticalSyncEnabled(true);
  Font::loadFont(); // load noto fonts (reg and bold)

  // menu creating
  Menu mainMenu(window, SIZE_MENU);
  bool renderMenu = true;

  //---------- event loop ----------//
  while(window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close(); // close functionality (x button)

      //---------- keypresses ----------//
      if (event.type == sf::Event::KeyPressed) { 
        if (event.key.control && event.key.code == sf::Keyboard::W) window.close(); // close functionality (ctrl + w)
        if (event.key.code == sf::Keyboard::Escape) renderMenu = !(renderMenu && true); // toggle main menu
      } 

      //---------- mouse clicks ----------//
      // if new game is clicked, close menu and start the game, else, read other btns
      if (renderMenu) renderMenu = !(mainMenu.btnClicked(event));
    }

    //---------- clear/draw/display ----------//
    window.clear(sf::Color(34, 40, 49));
    if (renderMenu) mainMenu.renderMenu();
    window.display();
  }

  return 0;
}
