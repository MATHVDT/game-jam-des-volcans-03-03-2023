#include "../include/Affichable.hpp"

bool compareAffichables(const Affichable_t &r1, const Affichable_t &r2)
{
    return r1.layer < r2.layer;
}
