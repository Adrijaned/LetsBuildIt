//
// Created by adrijaneddebian on 4/27/18.
//

#ifndef LETSBUILD_PLAYER_HPP
#define LETSBUILD_PLAYER_HPP


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Player : public sf::Drawable {
    sf::Texture playerTexture;
    float currentZoom = 1;
    sf::Vector2f position;
    sf::Sprite playerSprite;
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
    sf::View getView(sf::Vector2u windowSize);
    Player();
    void update(sf::Window &window);
    void zoom(float &delta);
};


#endif //LETSBUILD_PLAYER_HPP
