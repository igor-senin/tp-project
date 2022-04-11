#include <game.h>
#include <iostream>

void Game::initWindow() {
  window.create(sf::VideoMode(2000, 1000), "Game",
                sf::Style::Fullscreen);
  window.setFramerateLimit(144);
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
  updatePlayer();

  updateCollision();
}

void Game::updatePlayer() {
  player->update();
}

void Game::render() {
  window.clear();

  renderPlayer();

  window.display();
}

const sf::RenderWindow& Game::getWindow() const {
  return window;
}

void Game::renderPlayer() {
  player->render(window);
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