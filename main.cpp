#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "const.hpp"
#include "GroundDrawer.hpp"
#include "Player.hpp"
#include "World.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(defaultWindowWidth, defaultWindowHeight), "Let's Build It");
    window.setVerticalSyncEnabled(true);

    GroundDrawer groundDrawer;
    sf::RenderTexture groundRenderTexture;
    groundRenderTexture.create(defaultWidthTiles * tileSizePixels, defaultHeightTiles * tileSizePixels);
    World world;
    Player player {world.createPerson((b2Vec2) {10, 10})};
    sf::Music music;
    music.openFromFile("res/soundtrack.ogg");
    music.setLoop(true); // temp until moar music
    music.play();

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
            if (event.type == sf::Event::MouseWheelScrolled) {
                player.zoom(event.mouseWheelScroll.delta);
            }
        }
        player.update(window);
        world.step();
        window.setView(player.getView(window.getSize()));
        window.clear(sf::Color::Black);
        groundRenderTexture.clear(sf::Color::Red);
        groundRenderTexture.draw(groundDrawer);
        groundRenderTexture.display();
        const sf::Texture &texture = groundRenderTexture.getTexture();
        sf::Sprite sprite(texture);
        window.draw(sprite);
        window.draw(player);
        window.display();
    }
    return 0;
}