//
// Created by adrijaneddebian on 4/26/18.
//

#ifndef LETSBUILD_GROUNDDRAWER_HPP
#define LETSBUILD_GROUNDDRAWER_HPP


#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include "const.hpp"

class GroundDrawer  : public sf::Drawable {
    enum GroundTypes {
        sand = 0,
        grass = 1
    };
    GroundTypes **groundTypesArray2D;
    sf::VertexArray vertexArray;
    sf::Texture groundTexture;
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    GroundDrawer();
};


#endif //LETSBUILD_GROUNDDRAWER_HPP
