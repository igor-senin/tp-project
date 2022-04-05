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
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window.close();
    } else if (event.type == sf::Event::KeyPressed
    and event.key.code == sf::Keyboard::Escape) {
      window.close();
    }

    if (event.type == sf::Event::KeyReleased
        and (event.key.code == sf::Keyboard::A or
            event.key.code == sf::Keyboard::D or
            event.key.code == sf::Keyboard::W or
            event.key.code == sf::Keyboard::S)) {
      player->resetAnimationTimer();
    }
  }

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