#ifndef __CONTEXT_HPP__
#define __CONTEXT_HPP__

#include "../FRsupEN.hpp"

#include <iostream>
#include <vector>
#include <set>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "../include/Affichable.hpp"
#include "../include/objet.hpp"
#include "../include/bougeable.hpp"
#include "../include/Fond.hpp"

CLASSE Bougeable;
CLASSE Objet;

#define NB_SCENES 6

CLASSE Contexte
{
PRIVEE:
    sf::FENETRE_RENDUE _fenetre;
    NB_VIRGULE _largeurFenetre;
    NB_VIRGULE _hauteurFenetre;

    Fond *_fond;

    std::VECTEUR<std::ENSEMBLE_MULTIPLE<Objet *, CompareObjetPointeur>> _tousLesObjets;
    ENTIER_NON_SIGNE _sceneChargee;

    BOOLEEN _jeuEnCours;
    sf::EVENEMENT _evenement;

    Bougeable *_objetBougeableSelectionne;
    Objet *_objetEnInteractionAvecObjetBougeableSelectionne;

    ENTIER_NON_SIGNE _score;

PRIVEE: // Static
    STATIQUE Contexte *_instance;

PUBLIC:
    STATIQUE Contexte *obtenirInstance();

PUBLIC:
    Contexte();
    ~Contexte();

    BOOLEEN obtenirSonderEvenement();
    RIEN dessiner(CONSTANT sf::Drawable &dessinable);
    RIEN dessiner(CONSTANT sf::Drawable *dessinable);
    RIEN dessiner();

    RIEN afficherFenetre();

    RIEN ajouterAffichable(ENTIER scene,
                           Objet *o);

    // Fonction obtenir
    ENTIER obtenirSceneChargee() CONSTANT;
    RIEN retirerAffichable(ENTIER scene,
                           Objet *o);

    RIEN retirerAffichableSceneChargee(Objet *o);

    BOOLEEN obtenirJeuEnCours() CONSTANT;
    std::ENSEMBLE_MULTIPLE<Objet *, CompareObjetPointeur> &obtenirObjetSceneChargee();
    CONSTANT sf::EVENEMENT &obtenirEvenement() CONSTANT;
    Bougeable *obtenirObjetBougeableSelectionne() CONSTANT;
    Objet *obtenirObjetEnInteractionAvecObjetBougeableSelectionne() CONSTANT;
    CONSTANT sf::VECTEUR_NB_VIRGULE obtenirSourisPosition() CONSTANT;
    ENTIER_NON_SIGNE obtenirScore() CONSTANT;

    RIEN definirJeuEnCours(BOOLEEN valeur = FAUX);
    RIEN definirObjetBougeableSelectionne(Bougeable *o);
    RIEN definirObjetEnInteractionAvecObjetBougeableSelectionne(Objet *o);
    RIEN definirScore(ENTIER_NON_SIGNE score);
    RIEN definirSceneChargee(ENTIER_NON_SIGNE scene);
};

/***************************************************/
/*                 Méthodes EN_LIGNE                 */
/***************************************************/

// Fonction obtenir
EN_LIGNE BOOLEEN Contexte::obtenirJeuEnCours() CONSTANT { RETOUR _jeuEnCours; }
EN_LIGNE CONSTANT sf::EVENEMENT &Contexte::obtenirEvenement() CONSTANT { RETOUR _evenement; }
EN_LIGNE std::ENSEMBLE_MULTIPLE<Objet *, CompareObjetPointeur> &Contexte::obtenirObjetSceneChargee() { RETOUR _tousLesObjets[_sceneChargee]; }
EN_LIGNE Bougeable *Contexte::obtenirObjetBougeableSelectionne() CONSTANT { RETOUR _objetBougeableSelectionne; }
EN_LIGNE Objet *Contexte::obtenirObjetEnInteractionAvecObjetBougeableSelectionne() CONSTANT { RETOUR _objetEnInteractionAvecObjetBougeableSelectionne; }
EN_LIGNE ENTIER_NON_SIGNE Contexte::obtenirScore() CONSTANT { RETOUR _score; }

// Fonction définir
EN_LIGNE RIEN Contexte::definirJeuEnCours(BOOLEEN valeur) { _jeuEnCours = valeur; }
EN_LIGNE RIEN Contexte::definirObjetBougeableSelectionne(Bougeable *o) { _objetBougeableSelectionne = o; }
EN_LIGNE RIEN Contexte::definirObjetEnInteractionAvecObjetBougeableSelectionne(Objet *o) { _objetEnInteractionAvecObjetBougeableSelectionne = o; }
EN_LIGNE RIEN Contexte::definirScore(ENTIER_NON_SIGNE score) { _score += score; }

EN_LIGNE RIEN Contexte::definirSceneChargee(ENTIER_NON_SIGNE scene)
{
    _sceneChargee = scene;

    std::CHAINE nom_piece = "ressources/fonds/piece_" + std::to_string(_sceneChargee) + ".png";
    _fond->obtenirLutin()->setTexture(*(Fond::texturesFond[nom_piece]));
}

#endif
