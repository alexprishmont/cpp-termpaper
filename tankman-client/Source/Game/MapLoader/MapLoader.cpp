#include "MapLoader.h"
#include "../Source/Engine/Engine.h"
#include "../Player/initPosition.h"

MapLoader::MapLoader() { 
	mapFile.open("Source/Levels/level1.cfg");
	std::string line;

	while (std::getline(mapFile, line)) {
		std::vector<char> chars(line.begin(), line.end());
		levelMap.push_back(chars);
	}

	mapFile.close();
}

MapLoader::MapLoader(std::string path) {
	mapFile.open(path.c_str());
	std::string line;

	while (std::getline(mapFile, line)) {
		std::vector<char> chars(line.begin(), line.end());
		levelMap.push_back(chars);
	}

	mapFile.close();
}

void MapLoader::create() {
	int width = Engine::screenWidth / levelMap[0].size();
	int height = Engine::screenHeight / levelMap.size();

	float scale = width / 32;

	for (int i = 0; i < levelMap.size(); i++) {
		for (int j = 0; j < levelMap[i].size(); j++) {
			char temp = levelMap[i][j];
			if (temp == '#') {
				Sprite* wall;
				wall = new Sprite("Source/Assets/Art/Walls/brick_gray_0.png", j * width + width/2, i * height + height/2);
				wall->setScale(scale);
				sprites.push_back(*wall);
			}
			else if (temp == '@') {
				player.x = j * width + width / 2;
				player.y = i * height + height / 2 + 16;
			}
			else if (temp == '^') {
				Sprite* coin;
				coin = new Sprite("Source/Assets/Art/Player/coin.png", j * width + width/2, i * height + height/2 + 3);
				coin->setScale(scale);
				coins.push_back(*coin);
			}
			else if (temp == '%') {
				Sprite* monster;
				monster = new Sprite("Source/Assets/Art/Player/blobRight.png", j * width + width / 2, i * height + height / 2);
				monster->setScale(scale);
				monsters.push_back(*monster);
				mPositions.push_back(std::make_pair(j * width + width / 2, i * height + height / 2));
			}
			else if (temp == 'e') {
				Sprite* _exit;
				_exit = new Sprite("Source/Assets/Art/exit.png", j * width + width / 2, i * height + height / 2);
				_exit->setScale(scale);
				exit = _exit;
			}
		}
	}
}

void MapLoader::render() {
	for (auto i : sprites)
		i.Render();
	for (auto i : coins)
		i.Render();

	exit->Render();
}

playerPosition MapLoader::getPlayerPosition() {
	return player;
}

void MapLoader::reCreateCoins() {

	int width = Engine::screenWidth / levelMap[0].size();
	int height = Engine::screenHeight / levelMap.size();

	float scale = width / 32;

	for (int i = 0; i < levelMap.size(); i++) {
		for (int j = 0; j < levelMap[i].size(); j++) {
			char temp = levelMap[i][j];
			if (temp == '^') {
				Sprite* coin;
				coin = new Sprite("Source/Assets/Art/Player/coin.png", j * width + width / 2, i * height + height / 2 + 3);
				coin->setScale(scale);
				coins.push_back(*coin);
			}
		}
	}
}

void MapLoader::respawnMonsters() {
	for (int i = 0; i < monsters.size(); i++)
		monsters[i].setPosition(mPositions[i].first, mPositions[i].second);
}