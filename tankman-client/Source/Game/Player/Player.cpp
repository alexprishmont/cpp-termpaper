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
}

float Player::speed = 1.5;

/*
	bounds[0] - right side
	bounds[1] - left side
	bounds[2] - top side
	bounds[3] - bottom side
*/

void Player::collide() {
	float 
		x = body->getPositionX(),
		y = body->getPositionY(),
		*border = body->bounds;
	
	if (x > border[1])
		body->setPosition(border[1], y);
}

void Player::move() {
	// Move player
	// Speed up player movement
	if (Keyboard::Key(GLFW_KEY_SPACE))
		speed = 2.5;
	else if (!Keyboard::Key(GLFW_KEY_SPACE))
		speed = 1.5;


	// Move it!
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
	// Detect collisions
	collide();
}

void Player::render() {
	body->Render();
}