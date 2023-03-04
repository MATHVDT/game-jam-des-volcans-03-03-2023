#ifndef __CONTEXT_HPP
#define __CONTEXT_HPP

#include <iostream>

#include <SFML/Graphics.hpp>

class Context
{
private:
    sf::RenderWindow _window;
    float _largeurFenetre;
    float _hauteurFenetre;

    sf::Event _event;

private: // Static
    static Context *_instance;

public:
    static Context *getInstance();

public:
    Context(/* args */);
    ~Context();

    bool getPollEvent();
    void dessiner(sf::Drawable* dessinable);

    void afficherFenetre();


};

#endif