#include "Manager.h"

Manager::Manager() {
	engine = new Engine();
	engine->initWindow("CLIENT");

	startSprite = Sprite("Source/Assets/Art/Player/NPC.png", 100, 100);
	startSprite.setScale(1.0f);

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
		if (Keyboard::Key(GLFW_KEY_UP))
			startSprite.setPosition(startSprite.getPositionX(), startSprite.getPositionY() + 1.0);
		if (Keyboard::Key(GLFW_KEY_DOWN))
			startSprite.setPosition(startSprite.getPositionX(), startSprite.getPositionY() - 1.0);
		if (Keyboard::Key(GLFW_KEY_LEFT))
			startSprite.setPosition(startSprite.getPositionX() - 1.0, startSprite.getPositionY());
		if (Keyboard::Key(GLFW_KEY_RIGHT))
			startSprite.setPosition(startSprite.getPositionX() + 1.0, startSprite.getPositionY());

		switch (state) {
			case Gamestate::START: {
				engine->beginRender();
				startSprite.Render();
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
