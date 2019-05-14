#pragma once
#include <iostream>
#include "../Source/Engine/Graphics/Sprite.h"
#include "../MapLoader/MapLoader.h"
#include <cmath>
#include <vector>
#include "../Player/Player.h"

class NPC {
	public:
		NPC(MapLoader* map, Player* _player);
		~NPC();

		void render();
		void move();
	private:
		bool collide(Sprite* obj, Sprite* body);
		MapLoader* mmap;
		Player* player;
};