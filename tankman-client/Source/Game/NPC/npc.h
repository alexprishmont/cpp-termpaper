#pragma once
#include <iostream>
#include "../Source/Engine/Graphics/Sprite.h"
#include "../MapLoader/MapLoader.h"
#include <cmath>
#include <vector>
#include "../Player/Player.h"

class NPC: public Player{
	public:
		NPC(std::vector<Sprite> npcs, MapLoader* map);
		~NPC();

		virtual void render() override;
		virtual void move() override;
	private:
		bool collide(Sprite* obj, Sprite* body);
		std::vector<Sprite> npc;
		MapLoader* mmap;
};