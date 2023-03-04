#ifndef __MANAGER_HPP__
#define __MANAGER_HPP__

#include <iostream>

#include "../include/Context.hpp"

class Manager
{
private:
    /* data */
    Context *context;

private: // Static
    static Manager *_instance;

public: // Static
    static Manager *getInstance();

public:
    Manager();
    ~Manager();

    void run();

    void checkEvent(sf::Event& event);
};

/***************************************************/
/*                 Méthodes inline                 */
/***************************************************/

#endif