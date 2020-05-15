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
        Arbre(Arbre const &other);
        Arbre &operator=(Arbre const &other);
        ~Arbre();

        // parcours
        template<typename Function> void preordre(Function f);
        template<typename Function> void postordre(Function f);
        template<typename Function> void largeur(Function f);

        // représentations
        std::string listes_imbriquees() const;
        std::string representation_indentee() const;

        // itération
        using iterator = IterateurEnPreOrdre;
        iterator begin() const noexcept;
        iterator end() const noexcept;

        using post_iterator = IterateurEnPostOrdre;
        post_iterator pbegin() const noexcept;
        post_iterator pend() const noexcept;
    };
}

#include "arbreImpl.h" // implementation of generic methods

#endif //ASD1_LABS_2020_ARBRE_H
