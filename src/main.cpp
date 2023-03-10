#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/Gestionnaire.hpp"
#include "../include/objet.hpp"
#include "../include/Fond.hpp"

int main()
{

		Objet::initialisationTexture();
    Fond::initialisationTexture();
    
    Gestionnaire *manager = Gestionnaire::obtenirInstance();

		manager->initScene();
    manager->run();

    // sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);

    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     window.clear();
    //     window.draw(shape);
    //     window.display();
    // }

    delete manager;

    return 0;
}
