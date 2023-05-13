#ifndef __MANAGER_HPP__
#define __MANAGER_HPP__

// #include "FRsupEN.hpp"

#include <iostream>

#include <SFML/Graphics/Texture.hpp>

#include "Contexte.hpp"
#include "armoire.hpp"
#include "ciseaux.hpp"
#include "prise.hpp"
#include "bougeable.hpp"
#include "fixe.hpp"
#include "objet.hpp"
#include "prise.hpp"
#include "inflammable.hpp"
#include "corbeille.hpp"
#include "allumette.hpp"
#include "BoutonChargerScene.hpp"
#include "issue.hpp"
#include "canape.hpp"
#include "neon.hpp"
#include "marteau.hpp"

#include <SFML/Audio.hpp>

class Gestionnaire
{
private:
	Contexte *contexte;

private: // Statique
	static Gestionnaire *_instance;

public: // Statique
	static Gestionnaire *obtenirInstance();

public:
	Gestionnaire();
	~Gestionnaire();

	void enCours();
	void initScene();

	bool objetSelectionneSuivreSouris();
	void checkEvenement(const sf::Event &evenement);
	bool checkSourisSurObjet();
	bool trouveObjetEnInteractionAvecObjetSelectionne();
	bool interactionObjets();

	void ajouteType(Objet *o, const std::vector<Type> listMat);
};

/***************************************************/
/*               Méthodes en ligne                 */
/***************************************************/

#endif
