#include "Header.hpp"

void Menu::initText(Font *font) {
    this->menuText.setFont(*font);
    this->menuText.setCharacterSize(36);
    this->menuText.setFillColor(Color::Black);
    this->menuText.setString("START THE GAME");
    this->menuText.setPosition(
        1920 / 2.f - this->menuText.getGlobalBounds().width / 2.f,
        1080 / 2.f - this->menuText.getGlobalBounds().height / 2.f
    );
}

Menu::Menu(Font *font) {
    this->initText(font);
}

void Menu::renderMenu(GameWindow* game) {
    
    game->getWindow()->draw(this->menuText);

    if (Mouse::isButtonPressed(Mouse::Left)) {
        if (this->menuText.getGlobalBounds().contains(game->getMousePos())) {
           game->setStarted(true);
        }
    }
}
