#pragma once

#include "Header.hpp"

class DeadEnemy {
private:
	Sprite sprite;
	Clock clock;
	IntRect rectSprite;

public:
	DeadEnemy(float x, float y, Texture* dead);

	void renderDead(RenderWindow& target);
};
