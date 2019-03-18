#pragma once
#include <GLFW\glfw3.h>
#include "Texture.h"

#include <iostream>
#include <string>

class Sprite {
	public:
		Sprite();
		Sprite(std::string imagePath);
		Sprite(std::string imagePath, float _xPos, float _yPos);

		void Render();
		void Update();

		void setPosition(float _xPos, float _yPos);
		void setRotation(float _rot);

		double getPositionX();
		double getPositionY();


		void setScale(float x);
		void setScale(float x, float y);
	private:
		Texture texture;

		float xPos;
		float yPos;
		float rot;

		float scaleX;
		float scaleY;
};