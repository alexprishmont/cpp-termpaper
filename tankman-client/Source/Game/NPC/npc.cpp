#include "npc.h"
#include "../Manager/Manager.h"

float randFloat(float a, float b) {
	return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}

NPC::NPC(MapLoader* map, Player* _player) { mmap = map; player = _player;  }
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
		mmap->monsters[i].setPosition(prevX + randX, prevY + randY);

		if (collide(&mmap->monsters[i], player->getBody()))
			Manager::gmover = true;
		for (int j = 0; j < mmap->sprites.size(); j++) {
			if (collide(&mmap->monsters[i], &mmap->sprites[j]))
				mmap->monsters[i].setPosition(prevX, prevY);
		}
		for (int a = i + 1; a < mmap->monsters.size(); a++) {
			if (collide(&mmap->monsters[i], &mmap->monsters[a])) {
				mmap->monsters[i].setPosition(prevX, prevY);
				mmap->monsters[a].setPosition(prevX - 2.0f, prevY);
			}
		}
	}
}

void NPC::render() {
	for (auto n : mmap->monsters)
		n.Render();
}