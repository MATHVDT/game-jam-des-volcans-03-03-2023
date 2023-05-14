#include "../include/Contexte.hpp"

Contexte *Contexte::_instance = nullptr;

Contexte::Contexte()
{
    _largeurFenetre = 1600.0f;
    _hauteurFenetre = 900.0f;

    _sceneChargee = 0;
    POUR (ENTIER k = 0; k < NB_SCENES; ++k)
    {
        _tousLesObjets.AJOUTER_FIN(std::ENSEMBLE_MULTIPLE<Objet *, CompareObjetPointeur>());
    }

    _jeuEnCours = VRAI;

    _objetBougeableSelectionne = nullptr;
    _objetEnInteractionAvecObjetBougeableSelectionne = nullptr;

    _fenetre.create(sf::VideoMode(_largeurFenetre,
                                  _hauteurFenetre),
                    "Club sandwich : ne rien faire de stupide dans les salles, ou pas",
                    sf::Style::Default);

    _fenetre.setActive();
    _fenetre.setPosition(sf::Vector2i(50, 50));

    std::CHAINE nom_piece = "ressources/fonds/piece_" + std::to_string(_sceneChargee) + ".png";
    _fond = NOUVEAU Fond(nom_piece, sf::VECTEUR_NB_VIRGULE(0.0f, 0.0f), sf::VECTEUR_NB_VIRGULE(_largeurFenetre / 1920.0f, _hauteurFenetre / 1080.0f), (unsigned ENTIER)0);

    _score = 0;
}

Contexte::~Contexte()
{
    POUR (auto &scene : _tousLesObjets)
    { // Pour chaque scene
        POUR (auto &o : scene)
        { // Pour chaque objet
            SUPPRIMER o;
        }
    }
    SUPPRIMER _fond;
    _fenetre.close();
}

Contexte *Contexte::obtenirInstance()
{
    SI (Contexte::_instance == nullptr)
    {
        Contexte::_instance = NOUVEAU Contexte();
        SI (Contexte::_instance == nullptr)
        {
            std::SORTIE_ERREUR << "Erreur de NOUVEAU\n";
            RETOUR nullptr;
        }
    }
    RETOUR Contexte::_instance;
}

BOOLEEN Contexte::obtenirSonderEvenement()
{
    RETOUR _fenetre.SONDAGE_EVENEMENT(_evenement);
}

/// @brief Dessine tous les objets
RIEN Contexte::dessiner()
{
    dessiner(_fond->obtenirLutin());

    auto &scene = _tousLesObjets[_sceneChargee];
    POUR (auto &o : scene)
    { // Pour chaque objet
        dessiner(o->obtenirLutin());
    }
}

RIEN Contexte::dessiner(CONSTANT sf::Drawable &dessinable)
{
    _fenetre.DESSINER(dessinable);
}

RIEN Contexte::dessiner(CONSTANT sf::Drawable *dessinable)
{
    _fenetre.DESSINER(*dessinable);
}

/// @brief Affiche la fenetre.
RIEN Contexte::afficherFenetre()
{
    _fenetre.AFFICHER();
    _fenetre.EFFACER();
}

/// @brief Ajoute un objet a la liste de tous les objets.
/// @param scene
/// @param affichable
RIEN Contexte::ajouterAffichable(ENTIER scene,
                                 Objet *o)
{
    _tousLesObjets[scene].INSERER(o);
}

ENTIER Contexte::obtenirSceneChargee() CONSTANT
{
    RETOUR _sceneChargee;
}
/// @brief Retire un objet a la liste de tous les objets.
/// @param scene
/// @param affichable
RIEN Contexte::retirerAffichable(ENTIER scene,
                                 Objet *o)
{
    _tousLesObjets[scene].ECRASER(o);
}

RIEN Contexte::retirerAffichableSceneChargee(Objet *o)
{
    retirerAffichable(_sceneChargee, o);
}

CONSTANT sf::VECTEUR_NB_VIRGULE Contexte::obtenirSourisPosition() CONSTANT
{
    // récupération de la position de la souris dans la fenêtre
    sf::Vector2i pixelPos = sf::SOURIS::OBTENIR_POSITION(_fenetre);
    // conversion en coordonnées "monde"
    RETOUR _fenetre.PIXEL_CARTE_EN_COORDONNEES(pixelPos);
}
