#include "Header.hpp"

void GameOver::initText(Font* font) {
    this->gameOverText.setFont(*font);
    this->gameOverText.setCharacterSize(36);
    this->gameOverText.setFillColor(Color::Black);
    this->gameOverText.setString("GAME OVER");
    this->gameOverText.setPosition(
        1920 / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
        1080 / 2.f - this->gameOverText.getGlobalBounds().height / 2.f
    );
}

GameOver::GameOver(Font* font) {
    this->initText(font);
}

void GameOver::renderGameOver(GameWindow *game) {

    game->getWindow()->draw(this->gameOverText);

    if (Mouse::isButtonPressed(Mouse::Left)) {
        if (this->gameOverText.getGlobalBounds().contains(game->getMousePos())) {
            game->initVariables();
        }
    }
}
