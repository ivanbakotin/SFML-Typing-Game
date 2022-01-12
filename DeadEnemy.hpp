#pragma once

#include "Header.hpp"

class DeadEnemy {
private:
	Sprite sprite;
	Clock clock;

public:
	DeadEnemy(float x, float y, Texture* dead1);

	void renderDead(RenderWindow& target, Texture* dead2);
};
