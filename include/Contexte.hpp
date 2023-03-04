#ifndef __CONTEXT_HPP
#define __CONTEXT_HPP

#include <iostream>
#include <vector>
#include <set>

#include <SFML/Graphics.hpp>

#include "../include/Affichable.hpp"
#include "../include/objet.hpp"
#include "../include/bougeable.hpp"

class Contexte
{
private:
    sf::RenderWindow _window;
    float _largeurFenetre;
    float _hauteurFenetre;

    std::vector<std::set<Affichable_t, CompareAffichables>> _tousLesObjets;

    bool _jeuEnCours;
    sf::Event _event;

    Bougeable *_objetBougeableSelectionne;
    Objet *_objetEnInteractionAvecObjetBougeableSelectionne;

private: // Static
    static Contexte *_instance;

public:
    static Contexte *obtenirInstance();

public:
    Contexte(/* args */);
    ~Contexte();

    bool obtenirSonderEvenement();
    void dessiner(const sf::Drawable &dessinable);
    void dessiner(const sf::Drawable *dessinable);
    void dessiner();

    void afficherFenetre();

    void ajouterAffichable(int scene,
                           const Affichable_t &&affichable);

    // Getter
    bool obtenirJeuEnCours() const;
    const sf::Event &obtenirEvenement() const;

    // Setter
    void definirJeuEnCours(bool valeur = false);
};

/***************************************************/
/*                 Méthodes inline                 */
/***************************************************/

// Getter
inline bool Contexte::obtenirJeuEnCours() const { return _jeuEnCours; }
inline const sf::Event &Contexte::obtenirEvenement() const { return _event; }

// Setter
inline void Contexte::definirJeuEnCours(bool valeur) { _jeuEnCours = valeur; }

#endif