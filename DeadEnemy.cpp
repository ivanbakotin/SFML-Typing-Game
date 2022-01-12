#include "Header.hpp"

DeadEnemy::DeadEnemy(float x, float y, Texture* dead1) {
	this->sprite.setTexture(*dead1);
	this->sprite.scale(0.2f, 0.2f);
	this->sprite.setPosition(x, y);
}

void DeadEnemy::renderDead(RenderWindow& target, Texture* dead2) {
	if (this->clock.getElapsedTime().asSeconds() > 1.5f) {
		this->sprite.setTexture(*dead2);	
	} 

	target.draw(this->sprite);
}
