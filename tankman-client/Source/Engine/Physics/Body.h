#pragma once
#include <iostream>
#include "../Graphics/Sprite.h"
#include "../IO/Keyboard.h"
#include <string>

class Body {
	public:
		Body();
		Body(std::string pathToBodyTexture);
		~Body();

		void initInput();
		void render();
	private:
		Sprite *bodyPng;
		void gravitationForce();
		static float movementSpeed;
		static float gravitation;

		void setRotation(float _rot);
		void move();
};