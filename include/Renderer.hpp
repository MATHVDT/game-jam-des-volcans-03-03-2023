#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#include <SFML/Graphics/Sprite.hpp>

struct Renderer
{
    sf::Sprite *sprite;
    uint layer;
} Renderer_t;

#endif