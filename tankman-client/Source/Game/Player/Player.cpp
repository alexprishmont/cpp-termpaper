#include "Player.h"
#include "../Source/Engine/IO/Keyboard.h"
#include "../MapLoader/MapLoader.h"
Player::Player(MapLoader* map) {
	playerPosition player = map->getPlayerPosition();
	body = new Sprite("Source/Assets/Art/Player/elf_male.png", player.x, player.y);
	body->setScale(1.0f);

	mmap = map;
}

Player::~Player() {
	delete body;
	delete mmap;
}

float Player::speed = 1.5;

bool Player::collide(Sprite *obj) {
	float difX = body->getPositionX() - obj->getPositionX();
	float difY = body->getPositionY() - obj->getPositionY();
	if (abs(difX) < body->sizeX && abs(difY) < body->sizeY)
		return true;
	else
		return false;
}

void Player::move() {
	// Move player
	// Speed up player movement
	if (Keyboard::Key(GLFW_KEY_SPACE))
		speed = 2.5;
	else if (!Keyboard::Key(GLFW_KEY_SPACE))
		speed = 1.5;

	// Move it!
	float prevX = body->getPositionX(), prevY = body->getPositionY();
	if (Keyboard::Key(GLFW_KEY_UP)) {
		body->setPosition(body->getPositionX(), body->getPositionY() + 1 * speed);
	}
	if (Keyboard::Key(GLFW_KEY_DOWN)) {
		body->setPosition(body->getPositionX(), body->getPositionY() - 1 * speed);
	}
	if (Keyboard::Key(GLFW_KEY_LEFT)) {
		body->setPosition(body->getPositionX() - 1 * speed, body->getPositionY());
	}
	if (Keyboard::Key(GLFW_KEY_RIGHT)) {
		body->setPosition(body->getPositionX() + 1 * speed, body->getPositionY());
	}

	for (auto _sprite : mmap->sprites) {
		if (collide(&_sprite)) {
			body->setPosition(prevX, prevY);
		}
	}
}

void Player::render() {
	body->Render();
}

Player::Player() {}
Sprite Player::getBody() { return *body;  }
