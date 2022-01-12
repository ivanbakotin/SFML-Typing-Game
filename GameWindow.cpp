#include "Header.hpp"

GameWindow::GameWindow() {
    this->window = new RenderWindow(videoMode.getDesktopMode(), "Typing Game", Style::Fullscreen);
    this->window->setFramerateLimit(60);
}

GameWindow::~GameWindow() {
    delete this->window;
}

void GameWindow::updateMousePositions() {
    this->mousePosWindow = Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void GameWindow::updateEvents() {
    while (this->window->pollEvent(this->event)) {
        switch (this->event.type) {
            case Event::Closed:
                this->window->close();
                break;

            case Event::KeyPressed:
                if (event.key.code == Keyboard::Escape) {
                    this->window->close();
                }
                break;

            case Event::TextEntered:
                if (this->event.key.code == 9) { // CHECK FOR TAB KEYPRESS
                    if (this->enemies.size() <= this->focusedEnemy + 1) {
                        this->focusedEnemy = 0;
                    } else {
                        this->focusedEnemy += 1;
                    }
                }
                else {
                    if (this->enemies.size()) {
                        this->enemies[this->focusedEnemy].checkInput(static_cast<char>(event.text.unicode));
                    }
                }
                break;
        }
    }
}

void GameWindow::updateWindowEvents() {
    updateMousePositions();
    updateEvents();
}

bool GameWindow::isRunning() {
    return this->window->isOpen();
}

RenderWindow* GameWindow::getWindow() {
    return this->window;
}

Vector2f GameWindow::getMousePos() {
    return this->mousePosView;
}
