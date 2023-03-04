#ifndef __CONTEXT_HPP
#define __CONTEXT_HPP

#include <iostream>
#include <vector>
#include <set>

#include <SFML/Graphics.hpp>

#include "../include/Affichable.hpp"

class Context
{
private:
    sf::RenderWindow _window;
    float _largeurFenetre;
    float _hauteurFenetre;

    std::vector<std::set<Affichable_t, CompareAffichables>> _tousLesObjets;

    bool _jeuEnCours;

    sf::Event _event;

private: // Static
    static Context *_instance;

public:
    static Context *obtenirInstance();

public:
    Context(/* args */);
    ~Context();

    bool obtenirPollEvent();
    void dessiner(sf::Drawable *dessinable);
    void dessiner();

    void afficherFenetre();

    void ajouterAffichable(int scene,
                           const Affichable_t &&affichable);

    // Getter
    bool obtenirJeuEnCours() const;
    const sf::Event &obtenirEvent() const;

    // Setter
    void definirJeuEnCours(bool valeur = false);
};

/***************************************************/
/*                 Méthodes inline                 */
/***************************************************/

// Getter
inline bool Context::obtenirJeuEnCours() const { return _jeuEnCours; }
inline const sf::Event &Context::obtenirEvent() const { return _event; }

// Setter
inline void Context::definirJeuEnCours(bool valeur) { _jeuEnCours = valeur; }

#endif