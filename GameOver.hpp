#pragma once

#include "Header.hpp"

class GameOver {
public:
	Text gameOverText;

	void initText(Font* font);
	void renderGameOver(GameWindow *game);

	GameOver(Font* font);
};
