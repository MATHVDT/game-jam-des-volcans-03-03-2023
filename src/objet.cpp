#include "../include/objet.hpp"
#include <SFML/Graphics/Rect.hpp>

const sf::Rect<int>& Objet::obtenirRectangle() const{
				return rectangle;
}


void Objet::definirRectangle(int gauche, int haut) {
				rectangle.left = gauche;
				rectangle.top = haut;
}

void Objet::definirRectangle(int gauche, int haut, 	int largeur , int hauteur) {
				definirRectangle(gauche,haut);
				rectangle.width = largeur;
				rectangle.height = hauteur;
}
