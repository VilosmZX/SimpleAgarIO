#include "Player.hpp"

Player::Player(float x, float y) : x{x}, y{y} {
  this->shape.setPosition(this->x, this->y);
  this->initVariables();
  this->initShape();
}

Player::~Player() {}

void Player::initShape() {
  this->shape.setFillColor(sf::Color::Green);
  this->shape.setSize(sf::Vector2f(50.f, 50.f));
}

void Player::initVariables() {
  this->velocity = 10.f;
  this->health = MAX_HP;
}

const sf::RectangleShape &Player::getShape() const { return this->shape; }

void Player::checkWindowCollision(sf::RenderTarget *target) {
  // Check Left
  if (this->shape.getGlobalBounds().left <= 0.f) {
    this->shape.setPosition(0.f, this->shape.getPosition().y);
  }
  // Check Right
  if ((this->shape.getGlobalBounds().left +
       this->shape.getGlobalBounds().width) >= target->getSize().x) {
    this->shape.setPosition(target->getSize().x -
                                this->shape.getGlobalBounds().width,
                            this->shape.getPosition().y);
  }
  // Check Top
  if (this->shape.getGlobalBounds().top <= 0.f) {
    this->shape.setPosition(this->shape.getPosition().x, 0.f);
  }
  // Check Bottom
  if ((this->shape.getGlobalBounds().top +
       this->shape.getGlobalBounds().height) >= target->getSize().y) {
    this->shape.setPosition(this->shape.getPosition().x,
                            target->getSize().y -
                                this->shape.getGlobalBounds().height);
  }
}

void Player::movement() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    this->shape.move(-this->velocity, 0.f);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    this->shape.move(this->velocity, 0.f);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    this->shape.move(0.f, -this->velocity);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    this->shape.move(0.f, this->velocity);
  }
}

void Player::update(sf::RenderTarget *target) {
  this->movement();
  this->checkWindowCollision(target);
}

void Player::render(sf::RenderTarget *target) { target->draw(this->shape); }

const unsigned int &Player::getPoints() const { return this->points; }

void Player::setPoints(unsigned int point) { this->points = point; }
