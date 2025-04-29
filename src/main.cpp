#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../include/menu.h"

/*
sf::Color clrBg(34, 40, 49);
sf::Color clrScnd(57, 62, 60);
sf::Color clrTbl(148, 137, 121);
sf::Color clrFnd(223, 208, 184);
*/

/********** init consts **********/
const sf::Vector2i SIZE_WIN(1920, 1080);
const sf::Vector2f SIZE_MENU(static_cast<float>(SIZE_WIN.x) / 2.f, static_cast<float>(SIZE_WIN.y) / 2.f);
const sf::Vector2f SIZE_SETTINGS(0.f, 0.f);

int main() {
  /********** init objs *********/
  sf::RenderWindow window(sf::VideoMode(SIZE_WIN.x, SIZE_WIN.y), "Solitaire Four Seasons");
  window.setVerticalSyncEnabled(true);

  Menu menuFull(SIZE_MENU); // for creating menus (e.g., main-menu, settings-menu, etc.)

  /********** event loop **********/
  while(window.isOpen()) {
    sf::Event event;

    /********** I/O events **********/
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close(); // close functionality (x button)

      //---------- keypresses ----------//
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.control && event.key.code == sf::Keyboard::W) window.close(); // close functionality (ctrl + w)
      }
    }

    /********** clear/draw/display **********/
    window.clear(sf::Color(34, 40, 49));
    menuFull.main(window);
    window.display();
  }

  return 0;
}
