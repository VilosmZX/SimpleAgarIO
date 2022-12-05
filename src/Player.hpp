#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#define MAX_HP 100.f

class Player {
  sf::RectangleShape shape;
  float x, y;
  float velocity;
  float health;
  unsigned int points = 0;

  void initVariables();
  void initShape();

  void movement();
  void checkWindowCollision(sf::RenderTarget *target);

public:
  Player(){};
  Player(float x, float y);
  virtual ~Player();
  void update(sf::RenderTarget *target);
  void render(sf::RenderTarget *target);
  const unsigned int &getPoints() const;
  void setPoints(unsigned int point);
  const sf::RectangleShape &getShape() const;
};
