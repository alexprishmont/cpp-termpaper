#pragma once

#include <GLFW\glfw3.h>
#include <SOIL\SOIL.h>
#include <iostream>
#include <string>

class Texture {
	public:
		Texture();
		Texture(int _id);
		Texture(std::string path);

		int getID();
		int getWidth();
		int getHeight();

	private:
		int id;
		int width;
		int height;
		bool getTextureParams();
};