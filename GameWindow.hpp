#pragma once

#include "Header.hpp"

class GameWindow : public Game {
private:
	VideoMode videoMode;
	Vector2f mousePosView;
	Vector2i mousePosWindow;
	Event event;
	RenderWindow* window;

	void updateMousePositions();
	void updateEvents();

public:
	GameWindow();
	~GameWindow();

	void updateWindowEvents();

	bool isRunning();
	RenderWindow* getWindow();
	Vector2f getMousePos();
};