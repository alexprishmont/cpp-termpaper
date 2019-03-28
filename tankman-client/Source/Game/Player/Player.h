#pragma once
#include <iostream>
#include "../Source/Engine/Graphics/Sprite.h"
#include "initPosition.h"

class Player {
	public:
		Player(playerPosition player);
		~Player();
		void move();
		void render();
	private:
		Sprite* body;
		void rotate(float angle);
		static float speed;
};