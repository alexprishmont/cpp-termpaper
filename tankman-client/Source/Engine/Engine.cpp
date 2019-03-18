#include "Engine.h"

// Game window height & width
int Engine::screenHeight = 800;
int Engine::screenWidth = 1180;

// Engine constructor & destructor
Engine::Engine() {
	gameWindow = NULL;
}

Engine::~Engine() {

}

// Engine main methods

bool Engine::initWindow(char* windowTitle) {
	if (!glfwInit()) {
		std::cout << "Cannot initiliaze a game window.";
		return false;
	}

	gameWindow = glfwCreateWindow(screenWidth, screenHeight, windowTitle, NULL, NULL);
	if (!gameWindow) {
		glfwTerminate();
		return false;
	}

	// GLFW setup
	glfwMakeContextCurrent(gameWindow);
	glfwSetWindowAspectRatio(gameWindow, 4, 3);
	glfwSetWindowSizeLimits(gameWindow, screenWidth, screenHeight, screenWidth, screenHeight);
	int w, h;
	glfwGetFramebufferSize(gameWindow, &w, &h);
	glfwSwapInterval(1);

	glfwSetKeyCallback(gameWindow, Keyboard::onKeyboardKeyPressed);
	glfwSetCursorPosCallback(gameWindow, Mouse::mousePosCallback);
	glfwSetMouseButtonCallback(gameWindow, Mouse::mouseButtonCallback);

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (mode->width - screenWidth) / 2;
	int yPos = (mode->height - screenHeight) / 2;
	glfwSetWindowPos(gameWindow, xPos, yPos);
	
	// GL setup
	// Viewport
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -10, 10);
	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW);

	// Alpha Blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return true;
}

void Engine::Update() {
	glfwPollEvents();
}

void Engine::beginRender() {
	glClearColor(0, 1, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Engine::endRender() {
	glfwSwapBuffers(gameWindow);
}