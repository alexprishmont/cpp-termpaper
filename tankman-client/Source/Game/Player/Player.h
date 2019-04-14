#pragma once
#include <iostream>
#include "../Source/Engine/Graphics/Sprite.h"
#include "initPosition.h"
#include "../MapLoader/MapLoader.h"

class Player {
	public:
		Player(MapLoader* map);
		~Player();
		void move();
		void render();
	private:
		Sprite* body;
		MapLoader* mmap;
		void rotate(float angle);
		static float speed;
		void collide();
		float playerBounds[4];
};