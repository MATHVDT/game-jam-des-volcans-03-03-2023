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
            interactionObjets();
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
    std::string img = "ressources/prise.png";
    sf::Texture *t = new sf::Texture();
    std::cerr << "load from file : " << t->loadFromFile(img) << "\n";

    /* Objet *o = new Bougeable(sf::Vector2f(0.0f, 0.0f),
                              sf::Vector2f(1.0f, 1.0f),
                              *t, 0, true);
    */
    Objet *o = new Ciseaux(sf::Vector2f(0.0f, 0.0f),
                           sf::Vector2f(1.0f, 1.0f),
                           0, true);

    // Objet *a = new Armoire(sf::Vector2f(20.0f, 0.0f),
    //                        sf::Vector2f(1.0f, 1.0f),
    //                        0, true);
    // contexte->ajouterAffichable(scene, a);

    Objet *p = new Prise(sf::Vector2f(100.0f, 0.0f),
                         sf::Vector2f(1.0f, 1.0f),
                         0, true);
    contexte->ajouterAffichable(scene, p);

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
    std::set<Objet *> &scene = contexte->obtenirObjetSceneChargee();

    // Parcours tous les objets pour savoir si la souris est dedans
    Objet *objetTouche = nullptr;
    for (Objet *x : scene)
    {
        if (x->obtenirVisible() &&
            x->obtenirRectangle().contains(sourisPosition))
        {
            objetTouche = x;
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
        objetSelectionne->definirPosition((sf::Vector2f)sf::Mouse::getPosition());
    }
}

/// @brief Set l'objet qui est en interaction avec le selectionne
/// @return
bool Gestionnaire::trouveObjetEnInteractionAvecObjetSelectionne()
{
    // Pas le bouton gauche relache
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        return false;

    // Recup tous les objets de la scene chargee
    std::set<Objet *> &scene = contexte->obtenirObjetSceneChargee();

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
    ajouteType(o1, o2->obtenirListeMateriaux());
    ajouteType(o2, o1->obtenirListeMateriaux());

    // Test la casssabilite et la consommabilite des objets
    o1->estIphone();
    o2->estIphone();

    return true;
}

void Gestionnaire::ajouteType(Objet *o, std::vector<Type> listMat)
{
    for (auto &mat : listMat)
    {
        o->ajouterMateriaux(mat);
    }
}
