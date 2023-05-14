#include "../include/Gestionnaire.hpp"

Gestionnaire *Gestionnaire::_instance = nullptr;

Gestionnaire::Gestionnaire(/* args */)
{
	contexte = Contexte::obtenirInstance();
}

Gestionnaire::~Gestionnaire()
{
	SUPPRIMER contexte;
}

Gestionnaire *Gestionnaire::obtenirInstance()
{
	SI(Gestionnaire::_instance == nullptr)
	{
		Gestionnaire::_instance = NOUVEAU Gestionnaire();
		SI(Gestionnaire::_instance == nullptr)
		{
			std::SORTIE_ERREUR << "Erreur de NOUVEAU\n";
			RETOUR nullptr;
		}
	}
	RETOUR Gestionnaire::_instance;
}

RIEN Gestionnaire::enCours()
{
	sf::Music musique;
	SI(!musique.openFromFile("ressources/sons/marseillaise.ogg"))
	{
		std::SORTIE_ERREUR << "dommage pas de musique" << std::RETOUR_CHARIOT;
	}
	SINON
	{
		musique.DEFINIR_VOLUME(10);
		musique.JOUER();
		musique.DEFINIR_BOUCLE(VRAI);
	}
	TANT_QUE(contexte->obtenirJeuEnCours())
	{

		TANT_QUE(contexte->obtenirSonderEvenement())
		{ // Actualise le contexte seulement quand il ya une evenement
			checkEvenement(contexte->obtenirEvenement());
		}
		contexte->dessiner();
		contexte->afficherFenetre();
	}
}

/// @brief Lance les actions suivant les evenements
/// @param evenement
// RIEN Gestionnaire::checkEvenement(CONSTANT sf::EVENEMENT &evenement)
RIEN Gestionnaire::checkEvenement(CONSTANT sf::EVENEMENT &evenement)
{
	CHOIX(evenement.type)
	{
		CAS sf::EVENEMENT::FERME : contexte->definirJeuEnCours(FAUX);
		QUITTER;

		CAS sf::EVENEMENT::SOURIS_BOUGEE : // Souris bougee
										   objetSelectionneSuivreSouris();
		QUITTER;

		CAS sf::EVENEMENT::BOUTON_SOURIS_PRESSE : // bouton appuye
												  checkSourisSurObjet();
		QUITTER;

		CAS sf::EVENEMENT::BOUTON_SOURIS_RELACHE: // bouton relache
		{
			Bougeable *o = contexte->obtenirObjetBougeableSelectionne();
			SI(trouveObjetEnInteractionAvecObjetSelectionne())
			{
				SI(interactionObjets())
				{
					SI(o != nullptr)
					{
						o->relache();
						contexte->retirerAffichableSceneChargee(o);
						SUPPRIMER o;
					}
				}
				SINON
				{
					SI(o != nullptr)
					o->relache();
				}
			}
			SINON
			{
				SI(o != nullptr)
				o->relache();
			}
			QUITTER;
		}
	DEFAUT:
		QUITTER;
	}
}

RIEN Gestionnaire::initScene()
{
	// MENU
	ENTIER_NON_SIGNE scene = 0;

	BoutonChargerScene *piece = NOUVEAU BoutonChargerScene(sf::VECTEUR_NB_VIRGULE(210.0f, 30.0f),
														   sf::VECTEUR_NB_VIRGULE(1600.0f / 1920.0f, 1600.0f / 1920.0f),
														   2, VRAI, 1, "ressources/objets/piece_1_lobby.png");
	contexte->ajouterAffichable(scene, piece);

	piece = NOUVEAU BoutonChargerScene(sf::VECTEUR_NB_VIRGULE(210.0f, 360.0f),
									   sf::VECTEUR_NB_VIRGULE(1600.0f / 1920.0f, 1600.0f / 1920.0f),
									   2, VRAI, 2, "ressources/objets/piece_2_lobby.png");
	contexte->ajouterAffichable(scene, piece);

	// SCENE 1
	scene = 1;

	BoutonChargerScene *retour_1 = NOUVEAU BoutonChargerScene(sf::VECTEUR_NB_VIRGULE(0.0f, 0.0f),
															  sf::VECTEUR_NB_VIRGULE(0.15f, 0.15f),
															  100, VRAI, 0, "ressources/objets/bouton_retour.png");
	contexte->ajouterAffichable(scene, retour_1);

	Bougeable *inflammable = NOUVEAU Inflammable(sf::VECTEUR_NB_VIRGULE(1230.0f, 295.0f),
												 sf::VECTEUR_NB_VIRGULE(0.15f, 0.15f),
												 2, VRAI);
	std::ENSEMBLE<Bougeable *> _set = {inflammable};

	Objet *o = NOUVEAU Armoire(sf::VECTEUR_NB_VIRGULE(1100.0f, 200.0f),
							   sf::VECTEUR_NB_VIRGULE(0.7f, 0.7f),
							   1, VRAI, _set);
	contexte->ajouterAffichable(scene, o);

	o = NOUVEAU Prise(sf::VECTEUR_NB_VIRGULE(240.0f, 610.0f),
					  sf::VECTEUR_NB_VIRGULE(0.06f, 0.06f),
					  1, VRAI);
	contexte->ajouterAffichable(scene, o);

	o = NOUVEAU Corbeille(sf::VECTEUR_NB_VIRGULE(-50.0f, 600.0f),
						  sf::VECTEUR_NB_VIRGULE(0.40f, 0.40f),
						  1, VRAI);
	contexte->ajouterAffichable(scene, o);

	o = NOUVEAU Ciseaux(sf::VECTEUR_NB_VIRGULE(800.0f, 550.0f),
						sf::VECTEUR_NB_VIRGULE(0.10f, 0.10f),
						3, VRAI);
	contexte->ajouterAffichable(scene, o);

	o = NOUVEAU Allumette(sf::VECTEUR_NB_VIRGULE(600.0f, 600.0f),
						  sf::VECTEUR_NB_VIRGULE(0.10f, 0.10f),
						  4, VRAI);
	contexte->ajouterAffichable(scene, o);

	// SCENE 2
	scene = 2;

	BoutonChargerScene *retour_2 = NOUVEAU BoutonChargerScene(sf::VECTEUR_NB_VIRGULE(0.0f, 0.0f),
															  sf::VECTEUR_NB_VIRGULE(0.15f, 0.15f),
															  100, VRAI, 0, "ressources/objets/bouton_retour.png");
	contexte->ajouterAffichable(scene, retour_2);

	o = NOUVEAU Issue(sf::VECTEUR_NB_VIRGULE(1140.0f, 200.0f),
					  sf::VECTEUR_NB_VIRGULE(0.45f, 0.45f),
					  1, VRAI);
	contexte->ajouterAffichable(scene, o);

	o = NOUVEAU Canape(sf::VECTEUR_NB_VIRGULE(580.0f, 440.0f),
					   sf::VECTEUR_NB_VIRGULE(0.6f, 0.6f),
					   2, VRAI);
	contexte->ajouterAffichable(scene, o);

	o = NOUVEAU Neon(sf::VECTEUR_NB_VIRGULE(940.0f, -50.0f),
					 sf::VECTEUR_NB_VIRGULE(0.3f, 0.3f),
					 3, VRAI);
	contexte->ajouterAffichable(scene, o);

	o = NOUVEAU Neon(sf::VECTEUR_NB_VIRGULE(440.0f, -50.0f),
					 sf::VECTEUR_NB_VIRGULE(0.3f, 0.3f),
					 4, VRAI);
	contexte->ajouterAffichable(scene, o);

	o = NOUVEAU Marteau(sf::VECTEUR_NB_VIRGULE(1140.0f, 310.0f),
						sf::VECTEUR_NB_VIRGULE(0.1f, 0.1f),
						5, VRAI);
	contexte->ajouterAffichable(scene, o);

	o = NOUVEAU Marteau(sf::VECTEUR_NB_VIRGULE(1140.0f, 310.0f),
						sf::VECTEUR_NB_VIRGULE(0.1f, 0.1f),
						6, VRAI);
	contexte->ajouterAffichable(scene, o);
}

/// @brief Lance le clic sur l'objet sur lequel la souris est.
/// @return VRAI si un objet est cliquee
BOOLEEN Gestionnaire::checkSourisSurObjet()
{
	// Pas le bouton gauche appuye
	SI(!sf::SOURIS::EST_BOUTON_PRESSE(sf::SOURIS::Button::Left))
	{
		RETOUR FAUX;
	}

	// Recup position souris
	sf::VECTEUR_NB_VIRGULE sourisPosition = (sf::VECTEUR_NB_VIRGULE)contexte->obtenirSourisPosition();

	// Recup tous les objets de la scene chargee
	std::ENSEMBLE_MULTIPLE<Objet *, CompareObjetPointeur> &scene = contexte->obtenirObjetSceneChargee();

	// Parcours tous les objets pour savoir si la souris est dedans
	Objet *objetTouche = nullptr;
	POUR(auto rit = scene.rbegin(); rit != scene.rend(); ++rit)
	{

		SI((*rit)->obtenirVisible() && (*rit)->obtenirRectangle().contains(sourisPosition))
		{
			objetTouche = (*rit);
			QUITTER;
		}
	}

	SI(objetTouche == nullptr)
	{
		RETOUR FAUX;
	}

	objetTouche->clic();
	RETOUR VRAI;
}

BOOLEEN Gestionnaire::objetSelectionneSuivreSouris()
{
	Bougeable *objetSelectionne = contexte->obtenirObjetBougeableSelectionne();
	SI(objetSelectionne != nullptr)
	{
		objetSelectionne->definirPositionCentreSprite((sf::VECTEUR_NB_VIRGULE)contexte->obtenirSourisPosition());
	}
	RETOUR VRAI;
}

/// @brief Set l'objet qui est en interaction avec le selectionne
/// @return
BOOLEEN Gestionnaire::trouveObjetEnInteractionAvecObjetSelectionne()
{
	// Pas le bouton gauche relache
	SI(sf::SOURIS::EST_BOUTON_PRESSE(sf::SOURIS::Button::Left))
	RETOUR FAUX;

	// Recup tous les objets de la scene chargee
	std::ENSEMBLE_MULTIPLE<Objet *, CompareObjetPointeur> &scene = contexte->obtenirObjetSceneChargee();

	Bougeable *objetSelectionne = contexte->obtenirObjetBougeableSelectionne();
	SI(objetSelectionne == nullptr)
	{
		RETOUR FAUX;
	}

	// Parcours tous les objets pour savoir si la souris est dedans
	POUR(Objet * x : scene)
	{
		SI(x == objetSelectionne)
		CONTINUER;

		SI(x->obtenirRectangle().INTERSECTE(objetSelectionne->obtenirRectangle()))
		{
			contexte->definirObjetEnInteractionAvecObjetBougeableSelectionne(x);
			RETOUR VRAI;
		}
	}
	RETOUR FAUX;
}

BOOLEEN Gestionnaire::interactionObjets()
{
	Objet *o1 = contexte->obtenirObjetBougeableSelectionne();
	Objet *o2 = contexte->obtenirObjetEnInteractionAvecObjetBougeableSelectionne();

	// Rajout les elements dans l'autre objet
	ajouteType(o1, o2->obtenirMateriaux());
	ajouteType(o2, o1->obtenirMateriaux());

	// Test la casssabilite et la consommabilite des objets
	o2->estIphone();

	RETOUR o1->estIphone();
}

RIEN Gestionnaire::ajouteType(Objet *o, std::VECTEUR<Type> listMat)
{
	POUR(auto &mat : listMat)
	{
		o->ajouterMateriaux(mat);
	}
}
