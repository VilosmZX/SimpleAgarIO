#pragma once
#include "Ball.hpp"
#include "Player.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

#define FPS 60
#define MAX_BALLS 30
#define SPAWN_INTERVAL 1.f

class Game {
  sf::RenderWindow *window;
  sf::Event ev;
  unsigned int width, height;
  bool endGame;
  Player player;
  std::vector<Ball> balls;
  float elapsedTime;
  sf::Clock clock;
  sf::Font font;
  sf::Text text;

  void initVariables();
  void initText();
  void initFont();
  void initWindow();
  void events();
  void update();
  void render();

  void spawnEnemy();
  void renderEnemy();
  void updateEnemy();

  void checkCollision();

  const bool getRunning() const;

  void renderGUI(sf::RenderTarget *target);
  void updateGUI();

public:
  Game(unsigned int width, unsigned int height);
  virtual ~Game();
  void loop();
};
