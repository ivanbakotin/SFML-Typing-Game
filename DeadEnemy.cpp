#include "Header.hpp"

DeadEnemy::DeadEnemy(float x, float y, Texture* dead) {
	this->rectSprite.height = 526;
	this->rectSprite.width = 629;
	this->sprite.setTextureRect(rectSprite);
	this->sprite.setTexture(*dead);
	this->sprite.scale(0.2f, 0.2f);
	this->sprite.setPosition(x, y);
}

void DeadEnemy::renderDead(RenderWindow& target) {
	if (this->clock.getElapsedTime().asSeconds() > 0.1f) {
		if (this->rectSprite.left < 6919) {
			this->rectSprite.left += 629;
		} 
		sprite.setTextureRect(rectSprite);
		this->clock.restart();
	}

	target.draw(this->sprite);
}
