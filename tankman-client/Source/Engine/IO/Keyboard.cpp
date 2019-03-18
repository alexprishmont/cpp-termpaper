#include "Keyboard.h"

bool Keyboard::Keys[GLFW_KEY_LAST] = { 0 };
bool Keyboard::KeysDown[GLFW_KEY_LAST] = { 0 };
bool Keyboard::KeysUp[GLFW_KEY_LAST] = { 0 };

void Keyboard::onKeyboardKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key < 0)
		return;

	if (action != GLFW_RELEASE && !Keys[key]) {
		KeysDown[key] = true;
		KeysUp[key] = false;
	}

	if (action == GLFW_RELEASE && Keys[key]) {
		KeysDown[key] = false;
		KeysUp[key] = true;
	}

	Keys[key] = action != GLFW_RELEASE;

}

bool Keyboard::keyDown(int key) {
	bool x = KeysDown[key];
	KeysDown[key] = false;
	return x;
}

bool Keyboard::keyUp(int key) {
	bool x = KeysUp[key];
	KeysUp[key] = false;
	return x;
}

bool Keyboard::Key(int key) {
	return Keys[key];
}