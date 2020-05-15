#ifndef ASD1_LABS_2020_ARBRE_H
#define ASD1_LABS_2020_ARBRE_H

#include <string>

#include "noeud.h"

namespace ASD1 {

    class Arbre {

    private:
        Noeud *racine;

    public:
        // constructeurs et destructeur
        Arbre();
        Arbre(std::string const &imbriquees);
        ~Arbre();

        // représentations
        std::string listes_imbriquees() const;
        std::string representation_indentee() const;
    };
}

#endif //ASD1_LABS_2020_ARBRE_H
