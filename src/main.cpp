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
#include <filesystem>
#include <iostream>
#include "../include/menu.h"

/*
sf::Color clrBg(34, 40, 49);
sf::Color clrScnd(57, 62, 60);
sf::Color clrTbl(148, 137, 121);
sf::Color clrFnd(223, 208, 184);
*/

//---------- init consts ----------//
const std::string rootPath = std::filesystem::current_path().string(); // path to the root project dir
const sf::Vector2i SIZE_WIN(1920, 1080);
const sf::Vector2f SIZE_MENU(static_cast<float>(SIZE_WIN.x) / 2.f, static_cast<float>(SIZE_WIN.y) / 2.f);
const sf::Vector2f SIZE_SETTINGS(0.f, 0.f);

int main() {
  //---------- init objs ----------//
  //---------- sfml ----------//
  sf::RenderWindow window(sf::VideoMode(SIZE_WIN.x, SIZE_WIN.y), "Solitaire Four Seasons");
  window.setVerticalSyncEnabled(true);

  sf::Font font;
  if (!font.loadFromFile(rootPath + "/assets/fonts/NotoSans-Regular.ttf")) { std::cerr << "Failed to load the font." << std::endl; return 1; }

  //---------- user def ----------//
  Menu menuFull(SIZE_MENU, font); // for creating menus (e.g., main-menu, settings-menu, etc.)

  //---------- event loop ----------//
  while(window.isOpen()) {
    sf::Event event;

    //---------- I/O events ----------//
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close(); // close functionality (x button)

      //---------- keypresses ----------//
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.control && event.key.code == sf::Keyboard::W) window.close(); // close functionality (ctrl + w)
      }
    }

    //---------- clear/draw/display ----------//
    window.clear(sf::Color(34, 40, 49));
    menuFull.main(window);
    window.display();
  }

  return 0;
}
