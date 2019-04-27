#include "Sprite.h"

Sprite::Sprite() {
	xPos = 0;
	yPos = 0;
	rot = 0;
	scaleX = 0;
	scaleY = 0;
	texture = Texture();
}

Sprite::Sprite(std::string imagePath) {
	texture = Texture(imagePath);
	xPos = 0;
	yPos = 0;
	rot = 0;
	scaleX = 0;
	scaleY = 0;
}

Sprite::Sprite(std::string imagePath, float _xPos, float _yPos) {
	texture = Texture(imagePath);
	xPos = _xPos;
	yPos = _yPos;
	rot = 0;
	scaleX = 0;
	scaleY = 0;
}


// public Methods

void Sprite::Render() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.getID());
	glLoadIdentity();

	glTranslatef(xPos, yPos, 0);
	glRotatef(rot, 0, 0, 1);
	glScalef(scaleX, scaleY, 1);

	glColor4f(1, 1, 1, 1);

	glBegin(GL_QUADS);
	{
		glTexCoord2f(0, 0);		glVertex2i(-texture.getWidth() / 2, -texture.getHeight() / 2);
		glTexCoord2f(1, 0);		glVertex2i(texture.getWidth() / 2 + 2, -texture.getHeight() / 2);
		glTexCoord2f(1, 1);		glVertex2i(texture.getWidth() / 2 + 2, texture.getHeight() / 2);
		glTexCoord2f(0, 1);		glVertex2i(-texture.getWidth() / 2, texture.getHeight() / 2);
	}
	glEnd();

	glDisable(GL_TEXTURE_2D);

	sizeX = texture.getWidth();
	sizeY = texture.getHeight();
}

void Sprite::Update() {

}

void Sprite::setPosition(float _xPos, float _yPos) {
	xPos = _xPos;
	yPos = _yPos;
}

void Sprite::setRotation(float _rot) {
	rot = _rot;
}

void Sprite::setScale(float x) {
	scaleX = x;
	scaleY = x;
}

void Sprite::setScale(float x, float y) {
	scaleX = x;
	scaleY = y;
}

double Sprite::getPositionX() {
	return xPos;
}

double Sprite::getPositionY() {
	return yPos;
}

double Sprite::getRotation() {
	return rot;
}