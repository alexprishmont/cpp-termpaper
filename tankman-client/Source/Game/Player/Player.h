#pragma once
#include <iostream>
#include "../Source/Engine/Graphics/Sprite.h"
#include "initPosition.h"
#include "../MapLoader/MapLoader.h"
#include <cmath>

float randFloat(float a, float b);

class Player {
	public:
		Player(MapLoader* map);
		~Player();
		virtual void move();
		virtual void render();
		int lives = 3;
		Player();
		Sprite getBody();
	private:
		bool collide(Sprite *obj);
		Sprite* body;
		MapLoader* mmap;
		static float speed;
		float playerBounds[4];

		std::vector<Sprite> life;
};