//
// Created by adrijaneddebian on 4/27/18.
//

#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include "Player.hpp"

sf::View Player::getView(sf::Vector2u windowSize) {
    sf::View view = sf::View(sf::Vector2f(position), sf::Vector2f(windowSize));
    view.zoom(currentZoom);
    return view;
}

Player::Player() {
    position = sf::Vector2f(350, 350);
    playerTexture.loadFromFile("res/player.png");
    playerSprite.setTexture(playerTexture);
    playerSprite.setOrigin(playerTexture.getSize().x / 2, playerTexture.getSize().y / 2); // NOLINT
    playerSprite.setPosition(position);
}

void Player::update(sf::Window &window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        position.x += 3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        position.x -= 3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        position.y -= 3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        position.y += 3;
    }
    playerSprite.setPosition(position);
    sf::Vector2u windowCenter = window.getSize() / 2u;
    sf::Vector2i angle = sf::Mouse::getPosition(window) - sf::Vector2i(windowCenter);
    playerSprite.setRotation(static_cast<float>(std::atan2(angle.y, angle.x) * 180 / 3.141592654) + 90);
}

void Player::zoom(float &delta) {
    currentZoom -= delta * 0.1f * currentZoom;
    if (currentZoom > 10) {
        currentZoom = 10;
    }
    if (currentZoom < 0.1) {
        currentZoom = 0.1;
    }
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates) const {
    target.draw(playerSprite);
}
