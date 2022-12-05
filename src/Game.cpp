#include "Game.hpp"

Game::Game(unsigned int width, unsigned int height)
    : width{width}, height{height} {
  this->initWindow();
  this->initVariables();
  this->initFont();
  this->initText();
}

Game::~Game() { delete this->window; }

void Game::initVariables() {
  this->player = Player(10.f, 10.f);
  this->endGame = false;
}

void Game::initWindow() {
  this->window =
      new sf::RenderWindow(sf::VideoMode(this->width, this->height), "Shooter");
  this->window->setFramerateLimit(FPS);
}

void Game::initFont() {
  if (!this->font.loadFromFile("res/fonts/pixel.ttf")) {
    std::cout << "Cant load font!" << std::endl;
  }
}

void Game::initText() {
  this->text.setFont(this->font);
  this->text.setFillColor(sf::Color::White);
  this->text.setCharacterSize(24);
  this->text.setString("Hello World!");
}

void Game::updateGUI() {
  std::stringstream ss;
  ss << this->player.getPoints();
  this->text.setString(ss.str());

  switch (this->player.getPoints()) {
  case 10:
    this->text.setFillColor(sf::Color::Yellow);
    break;
  case 25:
    this->text.setFillColor(sf::Color::Blue);
    break;
  case 50:
    this->text.setFillColor(sf::Color::Red);
    break;
  case 100:
    this->text.setFillColor(sf::Color(212, 175, 55, 255));
    break;
  }
}

const bool Game::getRunning() const { return this->window->isOpen(); }

void Game::events() {
  while (this->window->pollEvent(this->ev)) {
    switch (this->ev.type) {
    case sf::Event::Closed:
      this->window->close();
      break;
    case sf::Event::KeyPressed:
      if (this->ev.key.code == sf::Keyboard::Escape)
        this->window->close();
      break;
    }
  }
}

void Game::update() {
  this->spawnEnemy();

  this->player.update(this->window);
  this->updateEnemy();
  this->checkCollision();
  this->updateGUI();
}

void Game::render() {
  this->renderGUI(this->window);
  this->player.render(this->window);
  this->renderEnemy();
}

void Game::renderGUI(sf::RenderTarget *target) { target->draw(this->text); }

void Game::loop() {
  while (this->getRunning()) {
    srand(time(0));
    this->elapsedTime = clock.getElapsedTime().asSeconds();
    this->window->clear();

    this->events();
    this->update();
    this->render();

    this->window->display();
  }
}

void Game::spawnEnemy() {
  if (!(elapsedTime < SPAWN_INTERVAL)) {
    if (!(this->balls.size() == MAX_BALLS)) {
      this->balls.push_back(Ball(this->window));
      clock.restart();
    }
  }
}

void Game::renderEnemy() {
  for (Ball ball : this->balls) {
    ball.render();
  }
}

void Game::updateEnemy() {
  for (Ball ball : this->balls) {
    ball.update();
  }
}

void Game::checkCollision() {
  for (size_t ballIndex = 0; ballIndex < this->balls.size(); ballIndex++) {
    if (this->player.getShape().getGlobalBounds().intersects(
            this->balls[ballIndex].getShape().getGlobalBounds())) {
      this->balls.erase(this->balls.begin() + ballIndex);
      this->player.setPoints(this->player.getPoints() + 1);
    }
  }
}
