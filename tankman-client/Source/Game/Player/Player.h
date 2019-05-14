#pragma once
#include <iostream>
#include "../Source/Engine/Graphics/Sprite.h"
#include "initPosition.h"
#include "../MapLoader/MapLoader.h"
#include "../Source/Engine/IO/Keyboard.h"
#include "../Source/Game/Manager/Manager.h"
#include <vector>
#include <cmath>

float randFloat(float a, float b);

class Player {
	public:
		Player(MapLoader* map);
		~Player();
		void move();
		void render();
		int lives = 3;
		Player();
		Sprite* getBody();
		void setPosition(float x, float y);
	private:
		bool collide(Sprite *obj);
		Sprite* body;
		MapLoader* mmap;
		static float speed;
		float playerBounds[4];

		std::vector<Sprite> life;
};