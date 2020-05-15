#ifndef ASD1_LABS_2020_ARBRE_H
#define ASD1_LABS_2020_ARBRE_H

#include <string>

#include "noeud.h"
#include "iterateurPreOrdre.h"
#include "iterateurPostOrdre.h"

namespace ASD1 {

    class Arbre {

    private:
        Noeud *racine;

    public:
        // constructeurs et destructeur
        Arbre();
        Arbre(std::string const &imbriquees);
        ~Arbre();

        // itération
        using iterator = IterateurEnPreOrdre;
        iterator begin() const noexcept;
        iterator end() const noexcept;

        using post_iterator = IterateurEnPostOrdre;
        post_iterator pbegin() const noexcept;
        post_iterator pend() const noexcept;
    };
}

#endif //ASD1_LABS_2020_ARBRE_H
