#include "Body.h"

Body::Body() {
	bodyPng = new Sprite("Assets\Art\Player1.png", 0, 0);
}

Body::Body(std::string pathToBodyTexture) {
	bodyPng = new Sprite(pathToBodyTexture, 0, 0);
}

Body::~Body() {
	delete bodyPng;
}