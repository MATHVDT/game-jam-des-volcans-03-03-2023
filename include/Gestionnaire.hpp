#ifndef __MANAGER_HPP__
#define __MANAGER_HPP__

#include <iostream>

#include "../include/Context.hpp"

class Gestionnaire
{
private:
    /* data */
    Contexte *context;

private: // Static
    static Gestionnaire *_instance;

public: // Static
    static Gestionnaire *obtenirInstance();

public:
    Gestionnaire();
    ~Gestionnaire();

    void run();
    void initScene();

    void checkEvenment(const sf::Event& evenement);
    
};

/***************************************************/
/*                 Méthodes inline                 */
/***************************************************/

#endif