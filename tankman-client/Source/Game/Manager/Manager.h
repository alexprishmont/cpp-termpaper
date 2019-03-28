#pragma once
#include <iostream>
#include "../Source/Engine/Engine.h"
#include "../MapLoader/MapLoader.h"
#include "../Player/Player.h"

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
		void setState();
		Engine *engine;
		MapLoader* map;
		Sprite startSprite;
		Gamestate state;
		Player *player;
};