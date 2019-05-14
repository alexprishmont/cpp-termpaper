#pragma once
#include <iostream>
#include "../Source/Engine/Engine.h"
#include "../MapLoader/MapLoader.h"
#include "../Player/Player.h"
#include "../NPC/npc.h"

enum Gamestate {
	START,
	GAMEOVER,
	PLAYING,
	END
};

class Manager {
	public:

		Manager();
		~Manager();

		void Start();
		static bool gmover;
		static bool theend;
	private:
		Engine *engine;
		Gamestate state;
		MapLoader* map;
		Sprite startSprite;
		Sprite gameover;
		Player *player;
		NPC *npcs;
};