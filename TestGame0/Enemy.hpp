#pragma once
#include "utils.h"

struct PointPX
{
	float x, y;
} point;

class Enemy
{
public:
	Enemy();
	Enemy(const char*, sf::Color);
	void makeBigger(float);
	void setPosition(float, float);
	PointPX getPosition();
	void move(float, float);
	~Enemy();

	sf::Image i_enemy;
	sf::Texture t_enemy;
	sf::Sprite s_enemy;

private:

};

Enemy::Enemy()
{
}

Enemy::Enemy(const char* p, sf::Color color = sf::Color::White)
{
	i_enemy.loadFromFile(p);
	i_enemy.createMaskFromColor(color);
	t_enemy.loadFromImage(i_enemy);
	s_enemy.setTexture(t_enemy);
}

void Enemy::makeBigger(float n) {
	s_enemy.setScale(n, n);
}

void Enemy::move(float x, float y) {
	this->s_enemy.setPosition(this->s_enemy.getPosition().x + x, this->s_enemy.getPosition().y + y);
}

PointPX Enemy::getPosition() {
	point.x = this->s_enemy.getPosition().x;
	point.y = this->s_enemy.getPosition().y;
	return point;
}

void Enemy::setPosition(float x, float y) {
	this->s_enemy.setPosition(x, y);
}

Enemy::~Enemy()
{
}
