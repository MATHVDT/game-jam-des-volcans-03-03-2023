#ifndef __CONTEXT_HPP__
#define __CONTEXT_HPP__

// #include "../FRsupEN.hpp"

#include <iostream>
#include <vector>
#include <set>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "../include/Affichable.hpp"
#include "../include/objet.hpp"
#include "../include/bougeable.hpp"
#include "../include/Fond.hpp"

class Bougeable;
class Objet;

#define NB_SCENES 6

class Contexte
{
private:
    sf::RenderWindow _fenetre;
    float _largeurFenetre;
    float _hauteurFenetre;

    Fond *_fond;

    std::vector<std::multiset<Objet *, CompareObjetPointeur>> _tousLesObjets;
    uint _sceneChargee;

    bool _jeuEnCours;
    sf::Event _evenement;

    Bougeable *_objetBougeableSelectionne;
    Objet *_objetEnInteractionAvecObjetBougeableSelectionne;

    uint _score;

private: // Static
    static Contexte *_instance;

public:
    static Contexte *obtenirInstance();

public:
    Contexte();
    ~Contexte();

    bool obtenirSonderEvenement();
    void dessiner(const sf::Drawable &dessinable);
    void dessiner(const sf::Drawable *dessinable);
    void dessiner();

    void afficherFenetre();

    void ajouterAffichable(int scene,
                           Objet *o);

    // Fonction obtenir
    int obtenirSceneChargee() const;
    void retirerAffichable(int scene,
                           Objet *o);

    void retirerAffichableSceneChargee(Objet *o);

    bool obtenirJeuEnCours() const;
    std::multiset<Objet *, CompareObjetPointeur> &obtenirObjetSceneChargee();
    const sf::Event &obtenirEvenement() const;
    Bougeable *obtenirObjetBougeableSelectionne() const;
    Objet *obtenirObjetEnInteractionAvecObjetBougeableSelectionne() const;
    const sf::Vector2f obtenirSourisPosition() const;
    uint obtenirScore() const;

    void definirJeuEnCours(bool valeur = false);
    void definirObjetBougeableSelectionne(Bougeable *o);
    void definirObjetEnInteractionAvecObjetBougeableSelectionne(Objet *o);
    void definirScore(uint score);
    void definirSceneChargee(uint scene);
};

/***************************************************/
/*                 Méthodes inline                 */
/***************************************************/

// Fonction obtenir
inline bool Contexte::obtenirJeuEnCours() const { return _jeuEnCours; }
inline const sf::Event &Contexte::obtenirEvenement() const { return _evenement; }
inline std::multiset<Objet *, CompareObjetPointeur> &Contexte::obtenirObjetSceneChargee() { return _tousLesObjets[_sceneChargee]; }
inline Bougeable *Contexte::obtenirObjetBougeableSelectionne() const { return _objetBougeableSelectionne; }
inline Objet *Contexte::obtenirObjetEnInteractionAvecObjetBougeableSelectionne() const { return _objetEnInteractionAvecObjetBougeableSelectionne; }
inline uint Contexte::obtenirScore() const { return _score; }

// Fonction définir
inline void Contexte::definirJeuEnCours(bool valeur) { _jeuEnCours = valeur; }
inline void Contexte::definirObjetBougeableSelectionne(Bougeable *o) { _objetBougeableSelectionne = o; }
inline void Contexte::definirObjetEnInteractionAvecObjetBougeableSelectionne(Objet *o) { _objetEnInteractionAvecObjetBougeableSelectionne = o; }
inline void Contexte::definirScore(uint score) { _score += score; }

inline void Contexte::definirSceneChargee(uint scene)
{
    _sceneChargee = scene;

    std::string nom_piece = "ressources/fonds/piece_" + std::to_string(_sceneChargee) + ".png";
    _fond->obtenirSprite()->setTexture(*(Fond::texturesFond[nom_piece]));
}

#endif
