#pragma once
#include <iostream>
#include "../Source/Engine/Engine.h"
#include "../MapLoader/MapLoader.h"
#include "../Source/Game/Player/Player.h"
#include "../Source/Game/NPC/npc.h"

enum Gamestate {
	START,
	GAMEOVER,
	PLAYING
};

class Manager {
	public:

		Manager();
		~Manager();

		void Start();

		static bool gmover;
		static bool theend;
	private:
		Engine* engine;
		Player* player;
		MapLoader* map;
		NPC* npcs;
		Gamestate state;
		Sprite startSprite;
		Sprite gameover;
};