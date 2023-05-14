#ifndef __FR_SUP_EN_HPP__
#define __FR_SUP_EN_HPP__

/*
Ficher de constantes permettant de traduire les mots clés et autres méthodes
dans la merveilleuse langue de Molière.
Le français est parlé (en 2023), sur tous les continents et par environ 321 millions de personnes.
Il est quotidiennement employé par 235 millions personnes dans le monde.
Le français est la langue officielle de 29 Etats dans le monde.
ElIl le fait partie des 6 langues officielles ainsi que des 2 langues de travail à l'ONU.

Cocorico !!!
*/

#define SI if
#define SINON else
#define POUR for
#define CONTINUER continue
#define TANT_QUE while
#define CHOIX switch
#define CAS case
#define QUITTER break;
#define DEFAUT default
#define RETOUR return

#define RIEN void
#define CONSTANT const
#define ENTIER int
#define ENTIER_NON_SIGNE uint
#define NB_VIRGULE float
#define BOOLEEN bool
#define VRAI true
#define FAUX false
#define CHAINE string

#define CLASSE class
#define PRIVEE private
#define PUBLIC public
#define STATIQUE static
#define VIRTUEL virtual
#define SURCHARGE override
#define EN_LIGNE inline

#define PRINCIPAL main
#define NOUVEAU new
#define SUPPRIMER delete

// Bibliothèque standard
#define AJOUTER_FIN push_back
#define INSERER emplace
#define ECRASER erase
#define TROUVER find
#define DEBUT begin
#define FIN end
#define VECTEUR vector
#define ENSEMBLE set
#define ENSEMBLE_MULTIPLE multiset
#define EFFACER clear
#define SORTIE_STANDARD cout
#define SORTIE_ERREUR cerr
#define RETOUR_CHARIOT endl

// SFML
#define VECTEUR_NB_VIRGULE Vector2f
#define RECTANGLE Rect
#define EVENEMENT Event
#define FENETRE_RENDUE RenderWindow
#define OBTENIR_EXTREMITES_GLOBAL getGlobalBounds
#define LUTIN Sprite
#define SONDAGE_EVENEMENT pollEvent
#define DESSINER draw
#define AFFICHER display
#define OBTENIR_POSITION getPosition
#define SOURIS Mouse
#define PIXEL_CARTE_EN_COORDONNEES mapPixelToCoords
#define FERME Closed
#define SOURIS_BOUGEE MouseMoved
#define BOUTON_SOURIS_PRESSE MouseButtonPressed
#define BOUTON_SOURIS_RELACHE MouseButtonReleased
#define EST_BOUTON_PRESSE isButtonPressed
#define INTERSECTE intersects
#define JOUER play
#define DEFINIR_VOLUME setVolume
#define DEFINIR_BOUCLE setLoop

#endif