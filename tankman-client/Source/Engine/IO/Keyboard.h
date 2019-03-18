#pragma once
#include <iostream>
#include <GLFW\glfw3.h>

class Keyboard {
	public:
		static void onKeyboardKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mods);

		static bool keyDown(int key);
		static bool keyUp(int key);
		static bool Key(int key);

	private:
		static bool Keys[];
		static bool KeysDown[];
		static bool KeysUp[];
};