#include "../include/objet.hpp"

std::map<std::CHAINE, sf::Texture *> Objet::textureCarte = {};

Objet::Objet(sf::VECTEUR_NB_VIRGULE position,
			 sf::VECTEUR_NB_VIRGULE scale,
			 ENTIER_NON_SIGNE couche,
			 BOOLEEN visible)
	: _visible(visible),
	  _rectangle(), _materiaux({})
{
	_affichable.definirCouche(couche);
	_affichable.definirScale(scale);
	_affichable.definirSpritePosition(position);

	definirRectangle(position.x, position.y);
}

Objet::~Objet() {}

CONSTANT sf::RECTANGLE<NB_VIRGULE> &Objet::obtenirRectangle()
{
	NB_VIRGULE haut = _affichable.obtenirLutin()->OBTENIR_EXTREMITES_GLOBAL().top;
	NB_VIRGULE gauche = _affichable.obtenirLutin()->OBTENIR_EXTREMITES_GLOBAL().left;
	NB_VIRGULE hauteur = _affichable.obtenirLutin()->OBTENIR_EXTREMITES_GLOBAL().height;
	NB_VIRGULE largeur = _affichable.obtenirLutin()->OBTENIR_EXTREMITES_GLOBAL().width;
	definirRectangle(gauche, haut, hauteur, largeur);
	RETOUR _rectangle;
}

RIEN Objet::definirRectangle(NB_VIRGULE gauche, NB_VIRGULE haut)
{
	_rectangle.left = gauche;
	_rectangle.top = haut;
}

RIEN Objet::definirRectangle(NB_VIRGULE gauche,
							 NB_VIRGULE haut,
							 NB_VIRGULE largeur,
							 NB_VIRGULE hauteur)
{
	definirRectangle(gauche, haut);
	_rectangle.width = largeur;
	_rectangle.height = hauteur;
}

RIEN Objet::initialisationTexture()
{
	CONSTANT std::filesystem::path chemin{"ressources/objets/"};
	POUR (auto &file : std::filesystem::directory_iterator{chemin}) // loop through the current folder
	{
		// std::SORTIE_ERREUR << file << std::RETOUR_CHARIOT;
		sf::Texture *texture = NOUVEAU sf::Texture();
		texture->loadFromFile(file.path());
		textureCarte.insert(std::make_pair(file.path().CHAINE(), texture));
	}
}

std::map<std::CHAINE, sf::Texture *> &Objet::obtenirTextureMap()
{
	RETOUR textureCarte;
}

RIEN Objet::ajouterMateriaux(Type type)
{
	_materiaux.AJOUTER_FIN(type);
}

CONSTANT std::VECTEUR<Type> Objet::obtenirMateriaux() CONSTANT
{
	RETOUR _materiaux;
}

/***************************************************/
/*               Fonctions Operateurs              */
/***************************************************/
BOOLEEN operator<(CONSTANT Objet &r1, CONSTANT Objet &r2)
{
	RETOUR r1.obtenirCouche() < r2.obtenirCouche();
}
BOOLEEN operator>(CONSTANT Objet &r1, CONSTANT Objet &r2)
{
	RETOUR r1.obtenirCouche() > r2.obtenirCouche();
}
BOOLEEN operator==(CONSTANT Objet &r1, CONSTANT Objet &r2)
{
	RETOUR r1.obtenirCouche() == r2.obtenirCouche();
}
BOOLEEN operator<=(CONSTANT Objet &r1, CONSTANT Objet &r2)
{
	RETOUR r1 < r2 || r1 == r2;
}
BOOLEEN operator>=(CONSTANT Objet &r1, CONSTANT Objet &r2)
{
	RETOUR r1 > r2 || r1 == r2;
}
