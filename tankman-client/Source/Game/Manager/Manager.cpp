#include "Manager.h"

bool Manager::gmover = false;
bool Manager::theend = false;

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

	npcs = new NPC(map, player);
}

Manager::~Manager() {
	if (engine != nullptr)
		delete engine;
	
	if (player != nullptr)
		delete player;
	
	if (map != nullptr)
		delete map;
	
	if (npcs != nullptr)
		delete npcs;

	engine = nullptr;
	player = nullptr;
	map = nullptr;
	npcs = nullptr;
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
				engine->beginRender();
					gameover.Render();
				engine->endRender();

				if (Keyboard::Key(GLFW_KEY_ENTER)) {
					state = Gamestate::PLAYING;
					playerPosition pl = map->getPlayerPosition();
					player->setPosition(pl.x, pl.y);
					Manager::gmover = false;
				}
				break;
			}
			case Gamestate::PLAYING: {
				if (Manager::gmover == true)
					state = Gamestate::GAMEOVER;

				if (Manager::theend == true)
					state = Gamestate::END;
				
				player->move();
				npcs->move();

				engine->beginRender();
					map->render();
					player->render();
					npcs->render();
				engine->endRender();

				break;
			}
		}
	}
}