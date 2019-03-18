#pragma once
#include <iostream>
#include <GLFW\glfw3.h>

class Mouse {
	public:
		static void mousePosCallback(GLFWwindow* window, double _x, double _y);
		static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

		static double getMouseX();
		static double getMouseY();

		static bool buttonDown(int button);
		static bool buttonUp(int button);
		static bool Button(int button);

	private:
		static double x;
		static double y;

		static bool Keys[];
		static bool KeysDown[];
		static bool KeysUp[];
};