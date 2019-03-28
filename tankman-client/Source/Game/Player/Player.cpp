#include "Player.h"
#include "../Source/Engine/IO/Keyboard.h"
#include "../MapLoader/MapLoader.h"
Player::Player(playerPosition player) {
	body = new Sprite("Source/Assets/Art/Player/elf_male.png", player.x, player.y);
	body->setScale(1.0f);
}

Player::~Player() {
	delete body;
}

float Player::speed = 1.5;

void Player::move() {
	if (Keyboard::Key(GLFW_KEY_UP)) {
		body->setPosition(body->getPositionX(), body->getPositionY + 1 * speed);
	}
	if (Keyboard::Key(GLFW_KEY_DOWN)) {

	}
	if (Keyboard::Key(GLFW_KEY_LEFT)) {

	}
	if (Keyboard::Key(GLFW_KEY_RIGHT)) {

	}
}

void Player::render() {
	body->Render();
}