#pragma once
#include <iostream>
#include "../Graphics/Sprite.h"
#include <string>

class Body {
	public:
		Body();
		Body(std::string pathToBodyTexture);
		~Body();

		void moveBody(float _x, float _y, float speed);
		void gravitationForce();
	private:
		Sprite *bodyPng;
		float movementSpeed;
		static float gravitation;
};