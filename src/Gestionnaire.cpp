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
        break;

    case sf::Event::MouseButtonPressed:
        // bouton pressed
        checkSourisSurObjet();
        break;

        // case sf::Event:: :
        //     // bouton pressed

        //     break;

    case sf::Event::MouseButtonReleased:
        // bouton relache
        break;

    default:
        break;
    }
}

void Gestionnaire::initScene()
{
    uint scene = 0;
    std::string img = "ressources/prise.png";
    sf::Texture *t = new sf::Texture();
    std::cerr << "load from file : " << t->loadFromFile(img) << "\n";

    Objet *o = new Armoire(sf::Vector2f(0.0f, 0.0f),
                           sf::Vector2f(1.0f, 1.0f),
                           *t, 0, true);

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
    sf::Vector2f sourisPosition = (sf::Vector2f)sf::Mouse::getPosition();

    // Recup tous les objets de la scene chargee
    std::set<Objet *> &scene = contexte->obtenirObjetSceneChargee();

    // Parcours tous les objets pour savoir si la souris est dedans
    Objet *objetTouche = nullptr;
    for (Objet *x : scene)
    {
        objetTouche = x;
        if (objetTouche->obtenirVisible() &&
            objetTouche->obtenirRectangle().contains(sourisPosition))
            break;
    }

    if (objetTouche == nullptr)
        return false;

    objetTouche->clic();
    return true;
}
