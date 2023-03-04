#ifndef __CONTEXT_HPP
#define __CONTEXT_HPP

#include <iostream>
#include <vector>
#include <set>

#include <SFML/Graphics.hpp>

#include "../include/Affichable.hpp"
#include "../include/objet.hpp"
#include "../include/bougeable.hpp"

class Bougeable;
class Objet;

#define NB_SCENES 6

class Contexte
{
private:
    sf::RenderWindow _window;
    float _largeurFenetre;
    float _hauteurFenetre;

    std::vector<std::set<Objet *>> _tousLesObjets;
    uint _sceneChargee;

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
                           Objet *o);

    // Getter
    bool obtenirJeuEnCours() const;
    std::set<Objet *> &obtenirObjetSceneChargee();
    const sf::Event &obtenirEvenement() const;
    Bougeable *obtenirObjetBougeableSelectionne() const;
    Objet *obtenirObjetEnInteractionAvecObjetBougeableSelectionne() const;
    const sf::Vector2f obtenirSourisPosition(sf::RenderWindow &window) const;



    // Setter
    void definirJeuEnCours(bool valeur = false);
    void definirObjetBougeableSelectionne(Bougeable *o);
    void definirObjetEnInteractionAvecObjetBougeableSelectionne(Objet *o);
};

/***************************************************/
/*                 Méthodes inline                 */
/***************************************************/

// Getter
inline bool Contexte::obtenirJeuEnCours() const { return _jeuEnCours; }
inline const sf::Event &Contexte::obtenirEvenement() const { return _event; }
inline std::set<Objet *> &Contexte::obtenirObjetSceneChargee() { return _tousLesObjets[_sceneChargee]; }
inline Bougeable *Contexte::obtenirObjetBougeableSelectionne() const { return _objetBougeableSelectionne; }
inline Objet *Contexte::obtenirObjetEnInteractionAvecObjetBougeableSelectionne() const { return _objetEnInteractionAvecObjetBougeableSelectionne; }

// Setter
inline void Contexte::definirJeuEnCours(bool valeur) { _jeuEnCours = valeur; }
inline void Contexte::definirObjetBougeableSelectionne(Bougeable *o) { _objetBougeableSelectionne = o; }
inline void Contexte::definirObjetEnInteractionAvecObjetBougeableSelectionne(Objet *o) { _objetEnInteractionAvecObjetBougeableSelectionne = o; }

#endif