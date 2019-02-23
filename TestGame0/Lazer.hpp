#pragma once

#include "utils.h"

class Lazer
{
public:
	Lazer();
	void setPosition(float, float);
	void setOrigin(float, float);
	void setColor(sf::Color);
	void rotate(float);
	void shoot(float, float);
	~Lazer();

	sf::RectangleShape lzr;
	float x, y, xo, yo, angle;
	sf::Color color;

private:
	sf::RenderWindow window;
};

Lazer::Lazer()
{
	lzr.setFillColor(color);
	lzr.setPosition(x, y);
	lzr.setOrigin(xo, yo);
	lzr.rotate(angle);
}

void Lazer::setColor(sf::Color color) {
	lzr.setFillColor(color);
}

void Lazer::setOrigin(float x, float y) {
	this->xo = x;
	this->yo = y;
}

void Lazer::setPosition(float x, float y) {
	this->x = x;
	this->y = y;
}

void Lazer::rotate(float angle) {
	lzr.rotate(angle);
}

void Lazer::shoot(float x, float y) {	
	auto todeg = [=](double agl){
		return (agl * (180 / PI));
	};

	auto torad = [=](double agl) {
		return (agl * (PI / 180));
	};

	double length = sqrt(pow(this->x - x, 2) + pow((480 - this->y) - (480 - y), 2));
	double angle = asin(torad(((480 - this->y) - (480 - y)) / length));
	this->lzr.rotate(todeg(angle));
	lzr.setSize(sf::Vector2f(length, 3));

	// get the sine of the angle using a/c formula
	// get the angle using arcsin
	// rotating the rect
	// all this using mouse
}

Lazer::~Lazer()
{
}
