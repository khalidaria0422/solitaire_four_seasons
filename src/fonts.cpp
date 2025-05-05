#include "../include/fonts.h"
#include <SFML/Graphics/Font.hpp>
#include <iostream>
#include <filesystem>

//---------- init consts ----------//
const std::string rootPath = std::filesystem::current_path().string(); // path to the root project dir

//---------- init statics ----------//
sf::Font Font::Reg;
sf::Font Font::Bold;

//---------- load 'NotoSans' fonts ----------//
void Font::loadFont() {
  if (!Reg.loadFromFile(rootPath + "/assets/fonts/NotoSans-Regular.ttf") || 
      !Bold.loadFromFile(rootPath + "/assets/fonts/NotoSans-Bold.ttf")) std::cerr << "Failed to load the fonts." << std::endl;
}
