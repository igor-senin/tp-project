#include <game.h>
#include <iostream>

void Game::initWindow() {
  window.create(sf::VideoMode(400, 400), "Game"
                /*sf::Style::Fullscreen*/);
  window.setFramerateLimit(80);

  std::cout << window.getSize().x << ' ' << window.getSize().y << '\n';
}

void Game::initPlayer() {
  player = new Player(tilemap, window.getSize());
}

void Game::initTilemap() {
  tilemap = new TileMap();
}

Game::Game() {
  initWindow();
  initTilemap();
  initPlayer();
}

Game::~Game() {
  delete player;
}

void Game::update() {
  updateWindow();

  updatePlayer();
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

void Game::render() {
  window.clear();

  tilemap->Draw(getWindow());
  renderPlayer();

  window.display();
}

sf::RenderWindow& Game::getWindow() {
  return window;
}

void Game::renderPlayer() {
  player->render(window);
}
