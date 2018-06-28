//
// Created by adrijaneddebian on 4/27/18.
//

#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include "Player.hpp"
#include "const.hpp"
#include <iostream>

sf::View Player::getView(sf::Vector2u windowSize) {
    sf::View view = sf::View(sf::Vector2f(position), sf::Vector2f(windowSize));
    view.zoom(currentZoom);
    return view;
}

Player::Player(b2Body *body): body{body} {
    playerTexture.loadFromFile("res/player.png");
    playerSprite.setTexture(playerTexture);
    playerSprite.setOrigin(playerTexture.getSize().x / 2.0f, playerTexture.getSize().y / 2.0f);
    playerSprite.setPosition(position);
}

void Player::update(sf::Window &window) {
    bool accelerating = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (body->GetLinearVelocity().x <= maxMoveSpeed) {
            body->ApplyLinearImpulse(b2Vec2{0.03f, 0}, body->GetWorldCenter(), true);
        }
        accelerating = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (body->GetLinearVelocity().x >= -maxMoveSpeed) {
            body->ApplyLinearImpulse(b2Vec2{-0.03f, 0}, body->GetWorldCenter(), true);
        }
        accelerating = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (body->GetLinearVelocity().y >= -maxMoveSpeed) {
            body->ApplyLinearImpulse(b2Vec2{0, -0.03f}, body->GetWorldCenter(), true);
        }
        accelerating = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if (body->GetLinearVelocity().y <= maxMoveSpeed) {
            body->ApplyLinearImpulse(b2Vec2{0, 0.03f}, body->GetWorldCenter(), true);
        }
        accelerating = true;
    }
    // Stop when not moving
    if (!accelerating) {
        if (body->GetLinearVelocity().x > 0.03f) {
            body->ApplyLinearImpulse(b2Vec2{-0.03f, 0}, body->GetWorldCenter(), true);
        }
        else if (body->GetLinearVelocity().x < -0.03f) {
            body->ApplyLinearImpulse(b2Vec2{0.03f, 0}, body->GetWorldCenter(), true);
        }
        else {
            body->SetLinearVelocity(b2Vec2{0, body->GetLinearVelocity().y});
        }
        if (body->GetLinearVelocity().y > 0.03f) {
            body->ApplyLinearImpulse(b2Vec2{0, -0.03f}, body->GetWorldCenter(), true);
        }
        else if (body->GetLinearVelocity().y < -0.03f) {
            body->ApplyLinearImpulse(b2Vec2{0, 0.03f}, body->GetWorldCenter(), true);
        }
        else {
            body->SetLinearVelocity(b2Vec2{body->GetLinearVelocity().x, 0});
        }
    }
    std::cout << body->GetAngle() << std::endl;
    playerSprite.setPosition(position);
    sf::Vector2u windowCenter = window.getSize() / 2u;
    sf::Vector2i angle = sf::Mouse::getPosition(window) - sf::Vector2i(windowCenter);
    playerSprite.setRotation(static_cast<float>(std::atan2(angle.y, angle.x) * 180 / 3.141592654) + 90);
    b2Vec2 bodyPositionCopy = {body->GetPosition().x, body->GetPosition().y};
    bodyPositionCopy *= 1 / tileSizeMetres;
    bodyPositionCopy *= tileSizePixels;
    position.x = bodyPositionCopy.x;
    position.y = bodyPositionCopy.y;
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
