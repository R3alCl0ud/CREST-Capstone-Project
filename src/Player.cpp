#include "headers/Player.hpp"
#include "headers/Game.hpp"
#include <iostream>
#include <string>
#include <sstream>

namespace engine {

  // public functions:
  Player::Player() {
    // Create a default rectangle bounds
    this->bound = sf::IntRect(10, 10, 50, 30);
    // load default texture
    // loadFromFile("src/images/DiscLoader.png");

    // set bounds and color
    this->sprite.setTextureRect(this->bound);
    this->sprite.setColor(sf::Color(255, 255, 255, 255));
    shape.setSize(sf::Vector2f(50, 125));
    shape.setOrigin(25, 62.5);
    shape.setOutlineColor(sf::Color(200,200,200));
    shape.setOutlineThickness(-5.0f);
    RectangleCollider2D* rect = new engine::RectangleCollider2D(this);
    rect->setSize(sf::Vector2f(50, 125));
    this->collider2D = rect;
    physics2D.useGravity(true);
    this->jumpPressed = false;

    textFont.loadFromFile("src/fonts/arial.ttf");
    // text = new sf::Text("Velocity :<0.0, 0.0>", textFont);

  }

  Player::Player(sf::IntRect bounds) {
    this->bound = bounds;
    this->sprite.setTextureRect(this->bound);
    this->sprite.setColor(sf::Color(255, 255, 255, 255));
  }

  Player::Player(sf::IntRect bounds, sf::Color color) {
    this->bound = bounds;
    this->sprite.setTextureRect(this->bound);
    this->sprite.setColor(color);
  }

  void Player::draw(sf::RenderTarget& target) {
    // printf("player draw\n");
    target.draw(this->shape);
    std::ostringstream vel;
    vel.precision(4);
    vel <<"Velocity: <" <<std::fixed<< physics2D.getVelocity().x  << ", " <<std::fixed<< physics2D.getVelocity().y  << ">";
    std::ostringstream pos;
    pos.precision(4);
    pos << "Position: (" <<std::fixed<<position.x / 75<<", "<<std::fixed<<position.y/75<<")";
    // return
    sf::Text text( vel.str(), textFont);
    sf::Text textPOS(pos.str(), textFont);
    text.setPosition(position - sf::Vector2f(940, 430));
    textPOS.setPosition(position - sf::Vector2f(940, 360));
    text.setCharacterSize(64);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::White);
    textPOS.setCharacterSize(64);
    textPOS.setStyle(sf::Text::Bold);
    textPOS.setFillColor(sf::Color::White);
    target.draw(text);
    target.draw(textPOS);
  }

  // default deconstructor
  Player::~Player() {}

  void Player::start() {
    // physics2D.addForce(sf::Vector2f(10, 0));
  }

  void Player::fixedUpdate() {
    // printf("player fixed\n");
    // engine::Physics2D px = getPhysics();

    // this->move(this->physics2D.deltaV() * (float) 25);
  }

  void Player::onCollisionEnter(engine::Collider2D* collider2D) {
    // printf("Player collided with something\n");
    if (!canJump) canJump = true;
  }

  void Player::onCollisionExit(engine::Collider2D* collider2D) {
    // printf("Player collided with something\n");
    if (canJump) canJump = false;
  }

  void Player::update() {
    // physics2D.addForce(sf::Vector2f(0, G_C) * (float)engine::Game::DeltaTime());

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && canJump) {
      physics2D.addForce(sf::Vector2f(0, -12.5));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && physics2D.getVelocity().x > -6.0f) {
      physics2D.addForce(sf::Vector2f(-6 * 15 * engine::Game::DeltaTime(), 0));
      // move(-4.375, 0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && physics2D.getVelocity().x < 6.0f) {
      physics2D.addForce(sf::Vector2f(6 * 15 * engine::Game::DeltaTime(), 0));
      // move(4.375, 0);
    }

    engine::Game* g = engine::Game::GetGame();
    sf::View view = g->mWindow.getView();
    view.setCenter(this->getPosition());
    g->mWindow.setView(view);

  }

  void Player::setColor(sf::Color color) {
    this->sprite.setColor(color);
  }

  double Player::deltaX() {
    return (double) this->physics2D.deltaX();
  }

  double Player::deltaY() {
    return (double) this->physics2D.deltaY();
  }


}
