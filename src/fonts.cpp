// fonts.cpp
// -----------------------------------------------
// Loads and provides global access to "NotoSans'" both
// regular and bold fonts.
// -----------------------------------------------

#include "../include/fonts.h"
#include <SFML/Graphics/Font.hpp>
#include <filesystem>
#include <iostream>

// Path to the root project dir
const std::string rootPath = std::filesystem::current_path().string();

sf::Font Font::Reg;
sf::Font Font::Bold;

void Font::loadFont() {
  if (!Reg.loadFromFile(rootPath + "/assets/fonts/NotoSans-Regular.ttf") ||
      !Bold.loadFromFile(rootPath + "/assets/fonts/NotoSans-Bold.ttf"))
    std::cerr << "Failed to load the fonts." << std::endl;
}
