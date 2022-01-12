#pragma once

#include "Header.hpp"

class Menu {
public:
	Text menuText;

	void initText(Font *font);
	void renderMenu(GameWindow* game);

	Menu(Font *font);
};
