#include "../include/Gestionnaire.hpp"

Gestionnaire *Gestionnaire::_instance = nullptr;

Gestionnaire::Gestionnaire(/* args */)
{
	contexte = Contexte::obtenirInstance();
}

Gestionnaire::~Gestionnaire()
{
	delete contexte;
}

Gestionnaire *Gestionnaire::obtenirInstance()
{
	if (Gestionnaire::_instance == nullptr)
	{
		Gestionnaire::_instance = new Gestionnaire();
		if (Gestionnaire::_instance == nullptr)
		{
			std::cerr << "Erreur de new\n";
			return nullptr;
		}
		else
		{
			return Gestionnaire::_instance;
		}
	}
}

void Gestionnaire::run()
{
	sf::Event event;

	while (contexte->obtenirJeuEnCours())
	{

		while (contexte->obtenirSonderEvenement())
		{ // Actualise le contexte seulement quand il ya une evenement
			checkEvenment(contexte->obtenirEvenement());
		}
		contexte->dessiner();
		contexte->afficherFenetre();
	}
}

/// @brief Lance les actions suivant les evenements
/// @param evenement
void Gestionnaire::checkEvenment(const sf::Event &evenement)
{
	switch (evenement.type)
	{
	case sf::Event::Closed:
		contexte->definirJeuEnCours(false);
		break;

	case sf::Event::MouseMoved:
		// Souris bougee
		objetSelectionneSuivreSouris();
		break;

	case sf::Event::MouseButtonPressed:
		// bouton appuye
		checkSourisSurObjet();
		break;

	case sf::Event::MouseButtonReleased:
		// bouton relache
		if (trouveObjetEnInteractionAvecObjetSelectionne())
		{
			if (interactionObjets())
			{
				Bougeable *o = contexte->obtenirObjetBougeableSelectionne();
				if (o != nullptr)
				{
					o->relache();
					contexte->retirerAffichableSceneChargee(o);
					delete o;
				}
			}
			else
			{
				Bougeable *o = contexte->obtenirObjetBougeableSelectionne();
				if (o != nullptr)
					o->relache();
			}
		}
		else
		{
			Bougeable *o = contexte->obtenirObjetBougeableSelectionne();
			if (o != nullptr)
				o->relache();
		}
		break;

	default:
		break;
	}
}

void Gestionnaire::initScene()
{
	uint scene = 0;

	BoutonChargerScene * piece_1 = new BoutonChargerScene(sf::Vector2f(200.0f, 300.0f),
											 sf::Vector2f(1.0f, 1.0f),
											 2, true, 1, "ressources/objets/piece_1_lobby.png");
	contexte->ajouterAffichable(scene, piece_1);
	// SCENE 1
	scene = 1;

	BoutonChargerScene * retour_1 = new BoutonChargerScene(sf::Vector2f(0.0f, 0.0f),
											 sf::Vector2f(0.15f, 0.15f),
											 100, true, 0, "ressources/objets/bouton_retour.png");
	contexte->ajouterAffichable(scene, retour_1);

	Bougeable *inflammable = new Inflammable(sf::Vector2f(1230.0f, 295.0f),
											 sf::Vector2f(0.15f, 0.15f),
											 2, true);
	std::set<Bougeable *> _set = {inflammable};

	Objet *o = new Armoire(sf::Vector2f(1100.0f, 200.0f),
						   sf::Vector2f(0.7f, 0.7f),
						   1, true, _set);
	contexte->ajouterAffichable(scene, o);

	o = new Prise(sf::Vector2f(240.0f, 610.0f),
				  sf::Vector2f(0.06f, 0.06f),
				  1, true);
	contexte->ajouterAffichable(scene, o);

	o = new Corbeille(sf::Vector2f(-50.0f, 600.0f),
					  sf::Vector2f(0.40f, 0.40f),
					  1, true);
	contexte->ajouterAffichable(scene, o);

	o = new Ciseaux(sf::Vector2f(800.0f, 550.0f),
					sf::Vector2f(0.10f, 0.10f),
					3, true);
	contexte->ajouterAffichable(scene, o);

	o = new Allumette(sf::Vector2f(600.0f, 600.0f),
					  sf::Vector2f(0.10f, 0.10f),
					  4, true);
	contexte->ajouterAffichable(scene, o);
}

/// @brief Lance le clic sur l'objet sur lequel la souris est.
/// @return true si un objet est cliquee
bool Gestionnaire::checkSourisSurObjet()
{
	// Pas le bouton gauche appuye
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		return false;
	}

	// Recup position souris
	sf::Vector2f sourisPosition = (sf::Vector2f)contexte->obtenirSourisPosition();

	// Recup tous les objets de la scene chargee
	std::multiset<Objet *, CompareObjetPointeur> &scene = contexte->obtenirObjetSceneChargee();

	// Parcours tous les objets pour savoir si la souris est dedans
	Objet *objetTouche = nullptr;
	for (auto rit = scene.rbegin(); rit != scene.rend(); ++rit)
	{

		if ((*rit)->obtenirVisible() && (*rit)->obtenirRectangle().contains(sourisPosition))
		{
			objetTouche = (*rit);
			break;
		}
	}

	if (objetTouche == nullptr)
		return false;

	objetTouche->clic();
	return true;
}

bool Gestionnaire::objetSelectionneSuivreSouris()
{
	Bougeable *objetSelectionne = contexte->obtenirObjetBougeableSelectionne();
	if (objetSelectionne != nullptr)
	{
		objetSelectionne->definirPositionCentreSprite((sf::Vector2f)contexte->obtenirSourisPosition());
	}
	return true;
}

/// @brief Set l'objet qui est en interaction avec le selectionne
/// @return
bool Gestionnaire::trouveObjetEnInteractionAvecObjetSelectionne()
{
	// Pas le bouton gauche relache
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		return false;

	// Recup tous les objets de la scene chargee
	std::multiset<Objet *, CompareObjetPointeur> &scene = contexte->obtenirObjetSceneChargee();

	Bougeable *objetSelectionne = contexte->obtenirObjetBougeableSelectionne();
	if (objetSelectionne == nullptr)
		return false;

	// Parcours tous les objets pour savoir si la souris est dedans
	Objet *objetEnInteraction = nullptr;
	for (Objet *x : scene)
	{
		if (x == objetSelectionne)
			continue;

		if (x->obtenirRectangle().intersects(objetSelectionne->obtenirRectangle()))
		{
			contexte->definirObjetEnInteractionAvecObjetBougeableSelectionne(x);
			return true;
		}
	}
	return false;
}

bool Gestionnaire::interactionObjets()
{
	Objet *o1 = contexte->obtenirObjetBougeableSelectionne();
	Objet *o2 = contexte->obtenirObjetEnInteractionAvecObjetBougeableSelectionne();

	// Rajout les elements dans l'autre objet
	ajouteType(o1, o2->obtenirMateriaux());
	ajouteType(o2, o1->obtenirMateriaux());

	// Test la casssabilite et la consommabilite des objets
	o2->estIphone();

	return o1->estIphone();
}

void Gestionnaire::ajouteType(Objet *o, std::vector<Type> listMat)
{
	for (auto &mat : listMat)
	{
		o->ajouterMateriaux(mat);
	}
}
