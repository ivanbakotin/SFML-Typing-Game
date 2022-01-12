#pragma once

#include "Header.hpp"

class Enemy {
private:
	Text enemyText;
	string sentence;
	string displaySentence;
	Sprite sprite;
	Clock clock;
	float moveSpeed;

	void initText(Font* fontfake);
	void initSprite(Texture* textureFake, unsigned x);
	void initSentence(long level);

	void animateWalk(Texture* text1, Texture* text2);

public:
	Enemy(unsigned x, long level, Font* fontfake, Texture* textureFake);

	Sprite getShape();

	bool checkDead();
	void checkInput(char s);

	void moveEnemy(Texture* text1, Texture* text2);
	void setFocusedEnemy(Color color);

	void renderAlive(RenderTarget& target);
};
