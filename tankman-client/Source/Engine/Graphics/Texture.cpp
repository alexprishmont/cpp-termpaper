#include "Texture.h"

Texture::Texture() {
	id = -1;
}

Texture::Texture(int _id) {
	id = _id;
	if (!getTextureParams())
		std::cout << "Error loading image![ID: " << id << "]" << std::endl;
}

Texture::Texture(std::string path) {
	id = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_INVERT_Y);
	if (!getTextureParams())
		std::cout << "Error loading image! [path: " << path << "]" << std::endl;
}

bool Texture::getTextureParams() {
	if (id > 0) {
		int mipLevel = 0;
		glBindTexture(GL_TEXTURE_2D, id);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_WIDTH, &width);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_HEIGHT, &height);
		return true;
	}
	return false;
}

// public Methods

int Texture::getID() {
	return id;
}

int Texture::getWidth() {
	return width;
}

int Texture::getHeight() {
	return height;
}