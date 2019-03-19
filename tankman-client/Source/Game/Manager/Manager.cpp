#include "Manager.h"

Manager::Manager() {
	engine = new Engine();
	engine->initWindow("CLIENT");
	
	state = Gamestate::START;
}

Manager::~Manager() {
	delete engine;
}

void Manager::Start() {
	while (true) {
		if (Keyboard::Key(GLFW_KEY_ESCAPE))
			break;

		engine->Update();
		
		// TO-DO: A class for player (movement, rotation, shooting, etc.)
		// TO-DO: Physics (gravitation, etc.)
		Body player("Source/Assets/Art/Player/Player1.png");

		player.initInput();
		switch (state) {
			case Gamestate::START: {
				engine->beginRender();
				player.render();
				engine->endRender();
				break;
			}
			case Gamestate::GAMEOVER: {
				// TO-DO: Game Over screen
				break;
			}
			case Gamestate::PLAYING: {
				// TO-DO: Playing screen
				break;
			}
		}
	}
}
