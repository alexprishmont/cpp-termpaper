#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "../Source/Engine/Graphics/Sprite.h"
#include "initPosition.h"
#include "../MapLoader/MapLoader.h"

float randFloat(float a, float b);

class Player {
	public:
		Player(MapLoader* map);
		~Player();
		
		void move();
		void render();
		void setPosition(float x, float y);

		Sprite* getBody();
	private:
		bool collide(Sprite* obj);
		Sprite* body;
		MapLoader* mmap;
		static float speed;
};