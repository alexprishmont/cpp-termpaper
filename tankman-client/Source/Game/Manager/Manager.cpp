#include "Manager.h"

Manager::Manager() {
	engine = new Engine();
	engine->initWindow("CLIENT");

	map = new MapLoader();
	map->create();
	
	state = Gamestate::START;

	player = new Player(map);

	startSprite = Sprite("Source/Assets/Art/startgame.png", engine->screenWidth/2, engine->screenHeight/2);
	startSprite.setScale(1.0f);

	gameover = Sprite("Source/Assets/Art/gameover.png", engine->screenWidth / 2, engine->screenHeight / 2);
	gameover.setScale(1.0f);

	npcs = new NPC(map->monsters, map);
}

Manager::~Manager() {
	delete engine;
	delete player;
	delete map;
	delete npcs;
}

double lastTime = glfwGetTime();
int nbFrames = 0;

void Manager::Start() {
	while (true) {
		if (Keyboard::Key(GLFW_KEY_ESCAPE))
			break;

		double currentTime = glfwGetTime();
		nbFrames++;
		if (currentTime - lastTime >= 1.0) {
			printf("%f ms/frame\n", 1000.0 / double(nbFrames));
			nbFrames = 0;
			lastTime += 1.0;
		}

		engine->Update();
		
		// TO-DO: A class for player (movement, rotation, shooting, etc.)
		// TO-DO: Physics (gravitation, etc.)
		switch (state) {
			case Gamestate::START: {
				engine->beginRender();
				map->render();
				startSprite.Render();
				engine->endRender();

				if (Keyboard::Key(GLFW_KEY_ENTER))
					state = Gamestate::PLAYING;
				break;
			}
			case Gamestate::GAMEOVER: {
				// TO-DO: Game Over screen
				engine->beginRender();
				gameover.Render();
				engine->endRender();

				if (Keyboard::Key(GLFW_KEY_ENTER))
					state = Gamestate::PLAYING;
				break;
			}
			case Gamestate::PLAYING: {
				// TO-DO: Playing screen
				player->move();
				npcs->move();
				engine->beginRender();
				map->render();
				player->render();
				npcs->render();
				engine->endRender();

				if (player->lives <= 0)
					state = Gamestate::GAMEOVER;
				break;
			}
		}
	}
}
