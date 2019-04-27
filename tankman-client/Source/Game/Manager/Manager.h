#pragma once
#include <iostream>
#include "../Source/Engine/Engine.h"
#include "../MapLoader/MapLoader.h"
#include "../Player/Player.h"
#include "../NPC/npc.h"

class Manager {
	public:
		enum Gamestate {
			START,
			GAMEOVER,
			PLAYING
		};

		Manager();
		~Manager();

		void Start();

	private:
		Engine *engine;
		MapLoader* map;
		Sprite startSprite;
		Sprite gameover;
		Gamestate state;
		Player *player;
		NPC *npcs;
};