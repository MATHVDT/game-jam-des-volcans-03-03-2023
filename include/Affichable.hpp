#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#include <SFML/Graphics/Sprite.hpp>

typedef struct Affichable
{
    sf::Sprite sprite;
    uint couche;
} Affichable_t;

bool compareAffichables(const Affichable_t &r1, const Affichable_t &r2);

struct CompareAffichables
{
    bool operator()(const Affichable_t &a, const Affichable_t &b) const
    {
        return a.couche < b.couche;
    }
};

#endif