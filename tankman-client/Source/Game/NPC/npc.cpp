#include "npc.h"
#include "../Manager/Manager.h"

float randFloat(float a, float b) {
	return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}

NPC::NPC(MapLoader* map, Player* _player) { mmap = map; player = _player; moveY = false; }
NPC::~NPC() { 
	if (mmap != nullptr)
		delete mmap; 
	if (player != nullptr) 
		delete player; 
	mmap = nullptr; 
	player = nullptr; 
}

bool NPC::collide(Sprite* obj, Sprite* body) {
	float difX = body->getPositionX() - obj->getPositionX();
	float difY = body->getPositionY() - obj->getPositionY();
	if (abs(difX) < body->sizeX && abs(difY) < body->sizeY)
		return true;
	else
		return false;
}

void NPC::move() {
	for (int i = 0; i < mmap->monsters.size(); i++) {
		float prevX = mmap->monsters[i].getPositionX(), prevY = mmap->monsters[i].getPositionY();
		float randX = randFloat(-5.0f, 6.0f), randY = randFloat(-3.0f, 5.0f);

		if (!moveY) {
			mmap->monsters[i].setPosition(prevX + randX, prevY);
			moveY = true;
		}
		else {
			mmap->monsters[i].setPosition(prevX, prevY + randY);
			moveY = false;
		}

		if (collide(&mmap->monsters[i], player->getBody()))
			Manager::gmover = true;
		for (int j = 0; j < mmap->sprites.size(); j++) {
			if (collide(&mmap->monsters[i], &mmap->sprites[j]))
				mmap->monsters[i].setPosition(prevX, prevY);
		}
	}
}

void NPC::render() {
	for (auto n : mmap->monsters)
		n.Render();
}