#pragma once
#include <iostream>
#include <fstream>
#include "../Source/Engine/Graphics/Sprite.h"
#include "GLFW/glfw3.h"
#include <string>
#include <vector>
#include "../Player/initPosition.h"

class MapLoader {
	public:
		MapLoader();
		MapLoader(std::string path);
		void create();
		void render();
		playerPosition getPlayerPosition();
		std::vector<Sprite> sprites;
	private:
		std::vector<std::vector<char>> levelMap;
		std::fstream mapFile;
		playerPosition player;
};