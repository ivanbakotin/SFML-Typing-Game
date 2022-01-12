#pragma once

#include "Header.hpp"

class Game {
private:
	Text uiText;

	Texture backgroundTex;
	Texture textureWalk;
	Texture textureDead;

	long score;
	int health;

	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	long level;
	bool dead;
	bool started;

	void initFont();
	void initText();
	void initTexture();
	void initBackground();

	void spawnDeadEnemy(float x, float y);
	void spawnEnemy(RenderWindow& target);
	void updateEnemies(RenderWindow& target);
	void renderEnemies(RenderWindow& target);
	void RenderUI(RenderWindow& target);
	void renderDeadEnemies(RenderWindow& target);

public:
	Game();

	void initVariables();
	void renderGame(RenderWindow& target);
	bool getStarted();
	bool getDead();
	void setStarted(bool value);

	Font font;
	Sprite background;

	vector<Enemy> enemies;
	vector<DeadEnemy> deadEnemies;
	
	int focusedEnemy;
};
