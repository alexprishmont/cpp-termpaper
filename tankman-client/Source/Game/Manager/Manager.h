#pragma once
#include <iostream>
#include "../Source/Engine/Engine.h"

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
		Sprite startSprite;
		Gamestate state;
};