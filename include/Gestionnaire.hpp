#ifndef __MANAGER_HPP__
#define __MANAGER_HPP__

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

class Gestionnaire
{
private:
	/* data */
	Contexte *contexte;

private: // Static
	static Gestionnaire *_instance;

public: // Static
	static Gestionnaire *obtenirInstance();

public:
	Gestionnaire();
	~Gestionnaire();

	void run();
	void initScene();

	bool objetSelectionneSuivreSouris();
	void checkEvenment(const sf::Event &evenement);
	bool checkSourisSurObjet();
	bool trouveObjetEnInteractionAvecObjetSelectionne();
	bool interactionObjets();

	void ajouteType(Objet*o, const std::vector<Type> listMat);
};

/***************************************************/
/*                 Méthodes inline                 */
/***************************************************/

#endif
