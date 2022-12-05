#include "Ball.hpp"

Ball::Ball(sf::RenderTarget *target) : window{target} { this->initShape(); }

Ball::~Ball() {}

void Ball::initShape() {
  // Max size 20, Min Size 10
  this->shape.setRadius((float)(rand() % 10 + 10));
  // Random Color
  sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
  this->shape.setFillColor(color);
  this->shape.setPosition(
      sf::Vector2f((float)(rand() % this->window->getSize().x -
                           this->shape.getGlobalBounds().width),
                   (float)(rand() % this->window->getSize().y -
                           this->shape.getGlobalBounds().height)));
}

const sf::CircleShape &Ball::getShape() const { return this->shape; }

void Ball::render() { this->window->draw(this->shape); }

void Ball::update() {}
