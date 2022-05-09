#include <SFML/System/Vector2.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <game.h>
#include <iostream>

void Game::initWindow() {
  window.create(sf::VideoMode(2000, 1000), "Game",
                sf::Style::Fullscreen);
  window.setFramerateLimit(80);
}

void Game::initStartWindow() {
  start_window.create(sf::VideoMode(500, 500), "Start window", 
                      sf::Style::Fullscreen);
  //start_window.setPosition(sf::Vector2i(100, 100));
  start_window.setFramerateLimit(80);
}

void Game::initPlayer() {
  player = new Player(tilemap, window.getSize());
}

void Game::initTilemap() {
  tilemap = new TileMap();
}

Game::Game() {
  initStartWindow();
  updateStartWindow();
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

void Game::updateStartWindow() {
  sf::Font font;
  font.loadFromFile("../resources/7fonts.ru_VtksLemonDrop.ttf");
  sf::Text message("Press enter to start...", font, 60);
  message.setPosition(100, 100);
  message.setColor(sf::Color::Red);
  message.setStyle(sf::Text::Bold | sf::Text::Underlined);
  while (true) {
    start_window.clear();
    start_window.draw(message);
    start_window.display();
    sf::Event ev;
    while (start_window.pollEvent(ev)) {
      if (ev.type == sf::Event::Closed
      or (ev.type == sf::Event::KeyPressed
      and ev.key.code == sf::Keyboard::Return)) {
        start_window.close();
        goto break_point;
      }
    }
  }
break_point:
  return;
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
