#include "Mouse.h"

double Mouse::x = 0;
double Mouse::y = 0;

bool Mouse::Keys[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::KeysDown[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::KeysUp[GLFW_MOUSE_BUTTON_LAST] = { 0 };

void Mouse::mousePosCallback(GLFWwindow* window, double _x, double _y) {
	int w, h;
	glfwGetFramebufferSize(window, &w, &h);

	x = _x;
	y = h - _y;
}

void Mouse::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (button < 0)
		return;

	if (action != GLFW_RELEASE && !Keys[button]) {
		KeysDown[button] = true;
		KeysUp[button] = false;
	}

	if (action == GLFW_RELEASE && Keys[button]) {
		KeysDown[button] = false;
		KeysUp[button] = true;
	}

	Keys[button] = action != GLFW_RELEASE;
}

double Mouse::getMouseX() {
	return x;
}

double Mouse::getMouseY() {
	return y;
}

bool Mouse::buttonDown(int button) {
	bool x = KeysDown[button];
	KeysDown[button] = false;
	return x;
}

bool Mouse::buttonUp(int button) {
	bool x = KeysUp[button];
	KeysUp[button] = false;
	return x;
}

bool Mouse::Button(int button) {
	return Keys[button];
}