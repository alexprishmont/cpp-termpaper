#include "Manager.h"

Manager::Manager() {
	engine = new Engine();
	engine->initWindow("CLIENT");

	map = new MapLoader();
	map->create();
	
	state = Gamestate::START;

	player = new Player(map);

}

Manager::~Manager() {
	delete engine;
	delete map;
	delete player;
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
				player->move();
				engine->beginRender();
				map->render();
				player->render();
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
