#include "Header.hpp"

void Enemy::initSentence(long level) {

	vector<string> article = { "the", "a", "one", "some", "any" };
	vector<string> noun = { "boy", "girl", "house", "dog", "town", "bus", "car", "apple", "pear", "lemon", "horror"};
	vector<string> noun_hard = { "strawberry", "squirrel", "university", "desperate", "technology", "cemetery", "laboratory"};
	vector<string> verb = { "drove", "jumped", "swam", "went", "ran", "walked", "skipped" };
	vector<string> preposition = { "to", "from", "in", "over", "under", "on", "at" };

	vector<string> end = { "?", "!", "." };

	string randomSentence;

	string part_0 = level >= 0 ? article[rand() % article.size()] : "";
	string part_1 = level > 0 ? " " + noun[rand() % noun.size()] : "";
	string part_2 = level > 1 ? " " + verb[rand() % verb.size()] : "";
	string part_3 = level > 2 ? " " + preposition[rand() % preposition.size()] : "";
	string part_4 = level > 3 ? " " + article[rand() % article.size()] : "";
	string part_5 = level > 4 ? " " + noun_hard[rand() % noun_hard.size()] : "";

	randomSentence = part_0 + part_1 + part_2 + part_3 + part_4 + part_5 + end[rand() % 3];

	randomSentence[0] = toupper(randomSentence[0]);

	this->sentence = randomSentence;
	this->displaySentence = randomSentence;
}

void Enemy::initSprite(Texture* textureFake, unsigned x) {
	this->rectSprite.height = 519;
	this->rectSprite.width = 430;
	this->sprite.setTextureRect(rectSprite);
	this->sprite.setTexture(*textureFake);
	this->sprite.scale(0.2f, 0.2f);
	this->sprite.setPosition(
		0.f,
		static_cast<float>(rand() % static_cast<int>(x - 200)) + 75
	);
}

void Enemy::initText(Font* fontfake) {
	this->enemyText.setFont(*fontfake);
	this->enemyText.setCharacterSize(24);
	this->enemyText.setFillColor(Color::Black);
}

Enemy::Enemy(unsigned x, long level, Font* fontfake, Texture* textureFake) {
	initSentence(level);
	initSprite(textureFake, x);
	initText(fontfake);
	this->moveSpeed = 1.f;
}

void Enemy::renderAlive(RenderTarget &target) {
	stringstream ss;

	ss << this->displaySentence;

	this->enemyText.setString(ss.str());
	this->enemyText.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y - 25);

	target.draw(this->enemyText);
	target.draw(this->sprite);
}

bool Enemy::checkDead() {
	return !this->displaySentence.size();
}

void Enemy::checkInput(char s) {
	if (this->displaySentence[0] == s) {
		this->displaySentence.erase(0, 1);
	} else {
		this->displaySentence = this->sentence;
	}
}

Sprite Enemy::getShape() {
	return this->sprite;
}

void Enemy::animateWalk() {
	if (this->clock.getElapsedTime().asSeconds() > 0.1f) {
		if (this->rectSprite.left == 3870) {
			this->rectSprite.left = 0;
		} else {
			this->rectSprite.left += 430;
		}
		sprite.setTextureRect(rectSprite);
		this->clock.restart();
	}
}

void Enemy::moveEnemy() {
	this->sprite.move(this->moveSpeed, 0.f);
	animateWalk();
}

void Enemy::setFocusedEnemy(Color color) {
	this->enemyText.setFillColor(color);
}
