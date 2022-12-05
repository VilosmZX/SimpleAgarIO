#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Ball {
  sf::CircleShape shape;
  sf::RenderTarget *window;

  void initShape();

public:
  Ball(sf::RenderTarget *target);
  virtual ~Ball();
  void render();
  void update();
  const sf::CircleShape &getShape() const;
};
