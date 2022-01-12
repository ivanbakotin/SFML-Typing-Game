#include "Header.hpp"

void Game::initVariables() {
    this->health = 10;
    this->score = 0;
    this->level = 0;
    this->enemySpawnTimerMax = 300.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 10;
    this->focusedEnemy = 0;
    this->started = false;
    this->dead = false;
    this->enemies = {};
    this->deadEnemies = {};
}

void Game::initFont() {
    this->font.loadFromFile("Fonts/GothicA1-Regular.ttf");
}

void Game::initText() {
    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(36);
    this->uiText.setFillColor(Color::Black);
}

void Game::initTexture() {
    this->backgroundTex.loadFromFile("Textures/Desert.jpg");
    this->textureWalk.loadFromFile("Textures/ZombieWalk.png");
    this->textureDead.loadFromFile("Textures/ZombieDead.png");
}

void Game::initBackground() {
    this->background.setTexture(this->backgroundTex);
    this->background.setScale(2.5f, 2.5f);
}

Game::Game() {
    this->initVariables();
    this->initFont();
    this->initText();
    this->initTexture();
    this->initBackground();
}

bool Game::getStarted() {
    return this->started;
}

bool Game::getDead() {
    return this->dead;
}

void Game::setStarted(bool value) {
    this->started = value;
}

void Game::spawnEnemy(RenderWindow& target) {
    Enemy enemyObject(target.getSize().y, this->level, &this->font, &this->textureWalk);
    this->enemies.push_back(enemyObject);
}

void Game::spawnDeadEnemy(float x, float y) {
    DeadEnemy enemyObject(x, y, &this->textureDead);
    this->deadEnemies.push_back(enemyObject);
}

void Game::updateEnemies(RenderWindow& target) {

    if (this->maxEnemies > this->enemies.size()) {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
            this->spawnEnemy(target);
            this->enemySpawnTimer = 0.f;
        } else {
            this->enemySpawnTimer += 1.f;
        }
    }

    for (int i = 0; i < this->enemies.size(); i++) {

        if (this->enemies[i].checkDead()) {
            spawnDeadEnemy(this->enemies[i].getShape().getPosition().x, this->enemies[i].getShape().getPosition().y);
            this->enemies.erase(this->enemies.begin() + this->focusedEnemy);
            this->score += 1;
            this->level = this->score / 5;
            this->focusedEnemy = 0;
            continue;
        }

        this->enemies[i].moveEnemy();

        this->enemies[i].setFocusedEnemy(Color::Black);
        
        if (i == this->focusedEnemy) {
            this->enemies[i].setFocusedEnemy(Color::Magenta);
        }

        if (this->enemies[i].getShape().getPosition().x > target.getSize().x) {
            this->health -= 1;
            if (this->health <= 0) {
                this->dead = true;
            }
            if (this->focusedEnemy) {
                this->focusedEnemy -= 1;
            }
            this->enemies.erase(this->enemies.begin() + i);
        }
    }
}

void Game::renderEnemies(RenderWindow& target) {
    for (auto& enemy : this->enemies) {
        enemy.renderAlive(target);
    }
}

void Game::renderDeadEnemies(RenderWindow& target) {
    if (this->deadEnemies.size() > 5) {
        this->deadEnemies.erase(this->deadEnemies.begin());
    }

    for (auto& enemy : this->deadEnemies) {
        enemy.renderDead(target);
    }
}

void Game::RenderUI(RenderWindow& target) {
    stringstream ss;

    ss << "Points: " << this->score <<" Health: " << this->health <<" Level: " << this->level;

    this->uiText.setString(ss.str());

    target.draw(this->uiText);
}

void Game::renderGame(RenderWindow& target) {
    updateEnemies(target);
    renderEnemies(target);
    RenderUI(target);
    renderDeadEnemies(target);
}
