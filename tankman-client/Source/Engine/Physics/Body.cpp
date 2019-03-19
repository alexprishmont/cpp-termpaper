#include "Body.h"

void Body::render() {
	bodyPng->Render();
}

Body::Body() {
	bodyPng = new Sprite("Assets\Art\Player1.png", 100, 100);
	bodyPng->setScale(1.0f);
}

Body::Body(std::string pathToBodyTexture) {
	bodyPng = new Sprite(pathToBodyTexture, 100, 100);
	bodyPng->setScale(1.0f);
}

Body::~Body() {
	delete bodyPng;
}

void Body::setRotation(float _rot) {
	bodyPng->setRotation(_rot);
}


/*

	0 - start position (y += 1)
	90 - x += 1, y = y
	180 - x = x, y -= 1
	270 - x -= 1, y = y

*/

float Body::movementSpeed = 1.0;

void Body::move() {
	float rotation = bodyPng->getRotation();
	if (rotation == 0 || rotation == 360) {
		bodyPng->setPosition(
			bodyPng->getPositionX(),
			bodyPng->getPositionY() + movementSpeed
		);
	}
	else if (rotation == 90) {
		bodyPng->setPosition(
			bodyPng->getPositionX() + movementSpeed,
			bodyPng->getPositionY() 
		);
	}
	else if (rotation == 180) {
		bodyPng->setPosition(
			bodyPng->getPositionX(),
			bodyPng->getPositionY() - movementSpeed
		);
	}
	else if (rotation == 270) {
		bodyPng->setPosition(
			bodyPng->getPositionX() - movementSpeed,
			bodyPng->getPositionY()
		);
	}
}

void Body::initInput() {
	// Body movement
	if (Keyboard::Key(GLFW_KEY_UP)) {
		setRotation(0);
		move();
	}

	if (Keyboard::Key(GLFW_KEY_LEFT)) {
		setRotation(270);
		move();
	}

	if (Keyboard::Key(GLFW_KEY_DOWN)) {
		setRotation(180);
		move();
	}

	if (Keyboard::Key(GLFW_KEY_RIGHT)) {
		setRotation(90);
		move();
	}
	
}