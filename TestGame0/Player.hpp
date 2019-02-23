#pragma once
#include "utils.h"

class Player
{
public:
	Player(const char*);
	void animate(char, float);
	void setPosition(float, float);
	//void shoot(Enemy);
	~Player();

	sf::IntRect sprite_rect;
	sf::Texture texture;
	sf::Sprite sprite;
	void makebigger(float);
	
private:
	sf::Clock clock;
};

Player::Player(const char* s)
{
	texture.loadFromFile(s);
	sprite.setTexture(texture);
	sprite_rect.left = 32;
	sprite_rect.top = 0;
	sprite_rect.width = 32;
	sprite_rect.height = 32;
	sprite.setTextureRect(sprite_rect);
}

void Player::makebigger(float n) {
	this->sprite.setScale(n, n);
}

void Player::setPosition(float x, float y) {
	this->sprite.setPosition(x, y);
}

void Player::animate(char dir, float speed)
{
	if (clock.getElapsedTime().asSeconds() > 0.125f)
	{
		if (dir == 'l')
		{
			sprite_rect.top = 32;
			if (sprite_rect.left == 64)
			{
				sprite_rect.left = 0;
			}
			else
			{
				sprite_rect.left += 32;
			}
			this->sprite.setPosition(this->sprite.getPosition().x - speed, this->sprite.getPosition().y);
			this->sprite.setTextureRect(sprite_rect);
			clock.restart();
		}
		else if (dir == 'r')
		{
			sprite_rect.top = 64;
			if (sprite_rect.left == 64)
			{
				sprite_rect.left = 0;
			}
			else
			{
				sprite_rect.left += 32;
			}
			this->sprite.setPosition(this->sprite.getPosition().x + speed, this->sprite.getPosition().y);
			this->sprite.setTextureRect(sprite_rect);
			clock.restart();
		}
		else if (dir == 'd')
		{
			sprite_rect.top = 0;
			if (sprite_rect.left == 64)
			{
				sprite_rect.left = 0;
			}
			else
			{
				sprite_rect.left += 32;
			}
			this->sprite.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y + speed);
			this->sprite.setTextureRect(sprite_rect);
			clock.restart();
		}
		else if (dir == 'u')
		{
			sprite_rect.top = 96;
			if (sprite_rect.left == 64)
			{
				sprite_rect.left = 0;
			}
			else
			{
				sprite_rect.left += 32;
			}
			this->sprite.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y - speed);
			this->sprite.setTextureRect(sprite_rect);
			clock.restart();
		}
	}
}

Player::~Player()
{
}
