#pragma once

#include <iostream>
#include <GLFW\glfw3.h>

// Textures
#include "Graphics\Texture.h"
#include "Graphics\Sprite.h"

// IO
#include "IO\Keyboard.h"
#include "IO\Mouse.h"

// Physics

class Engine {
	public:
		bool initWindow(char* windowTitle);
		static int screenWidth;
		static int screenHeight;

		Engine();
		~Engine();

		void Update();
		void beginRender();
		void endRender();
		
	private:
		GLFWwindow* gameWindow;

};