#include <game.h>
#include <iostream>

void Game::initWindow() {
  window.create(sf::VideoMode(2000, 1000), "Game",
                sf::Style::Fullscreen);
  window.setFramerateLimit(80);
}

void Game::initPlayer() {
  player = new Player();
}

Game::Game() {
  initWindow();
  initPlayer();
}

Game::~Game() {
  delete player;
}

void Game::update() {
  updateWindow();

  updatePlayer();

  updateCollision();
}

void Game::updateWindow() {
  sf::Event ev;
  while (window.pollEvent(ev)) {
    if (ev.type == sf::Event::Closed
    or (ev.type == sf::Event::KeyPressed
    and ev.key.code == sf::Keyboard::Escape)) {
      window.close();
    }
  }
}

void Game::updatePlayer() {
  player->update();
}

void Game::updateCollision() {
  // Collision bottom of screen
  if (player->getPosition().y + player->getGlobalBounds().height
      > window.getSize().y) {
    player->landedY();
    player->setPosition(
        player->getPosition().x,
        window.getSize().y - player->getGlobalBounds().height
    );
  }
}

void Game::render() {
  window.clear();

  renderPlayer();

  window.display();
}

sf::RenderWindow& Game::getWindow() {
  return window;
}

void Game::renderPlayer() {
  player->render(window);
}