#include "../include/Affichable.hpp"

bool compareAffichables(const Affichable_t &r1, const Affichable_t &r2)
{
    return r1.couche < r2.couche;
}
