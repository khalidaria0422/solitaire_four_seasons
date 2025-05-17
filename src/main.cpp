// main.cpp
// -----------------------------------------------
// Contains the main event loop, and rendering of the
// game.
// -----------------------------------------------

#include "../include/colors.h"
#include "../include/fonts.h"
#include "../include/menu.h"
#include "../include/new_game.h"
#include "../include/sprites.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>

const sf::Vector2i SIZE_WIN(1920, 1080);
const sf::Vector2f SIZE_MENU(static_cast<float>(SIZE_WIN.x) / 2.f,
                             static_cast<float>(SIZE_WIN.y) / 2.f);

int main() {
  sf::RenderWindow window(sf::VideoMode(SIZE_WIN.x, SIZE_WIN.y),
                          "Solitaire Four Seasons");
  window.setVerticalSyncEnabled(true);
  Font::loadFont();
  LoadSprite::loadTexture();
  LoadSprite::assignCoords();

  // Create the main menu for the game
  Menu mainMenu(window, SIZE_MENU);
  bool renderMenu = false;

  // -- Event Loop --
  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      // Close game via the built in 'x' btn
      if (event.type == sf::Event::Closed)
        window.close();

      // -- Keypresses --
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.control && event.key.code == sf::Keyboard::W)
          window.close();

        // Toggle main menu via the esc btn
        if (event.key.code == sf::Keyboard::Escape)
          renderMenu = !(renderMenu && true);
      }

      // -- Mouse Events --
      // Close main menu if 'New Game' btn is clicked
      if (renderMenu)
        renderMenu = !(mainMenu.btnClicked(event));
    }

    // -- Render Game --
    window.clear(Clr::Primary);

    NewGame newGame(window);
    if (renderMenu)
      mainMenu.renderMenu();

    window.display();
  }

  return 0;
}
