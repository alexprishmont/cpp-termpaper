#include "npc.h"

float randFloat(float a, float b) {
	return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}

NPC::NPC(std::vector<Sprite> npcs, MapLoader* map) { npc = npcs; mmap = map; }
NPC::~NPC() { delete mmap; }

bool NPC::collide(Sprite* obj, Sprite* body) {
	float difX = body->getPositionX() - obj->getPositionX();
	float difY = body->getPositionY() - obj->getPositionY();
	if (abs(difX) < body->sizeX && abs(difY) < body->sizeY)
		return true;
	else
		return false;
}

void NPC::move() {
	for (auto n : npc) {
		float x = randFloat(1.0f, 3.0f);
		float y = randFloat(1.0f, 3.0f);

		float prevX = n.getPositionX(), prevY = n.getPositionY();
		n.setPosition(prevX + x, prevY + y);

		for (auto s : mmap->sprites) {
			if (collide(&s, &n)) {
				n.setPosition(prevX, prevY);
				std::cout << "collision" << std::endl;
			}
		}

		if (collide(&n, &Player::getBody())) {
			std::cout << "collision with player" << std::endl;
		}

	}
}

void NPC::render() {
	for (auto n : npc)
		n.Render();
}