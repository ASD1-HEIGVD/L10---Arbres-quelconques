#include "iterateurPreOrdre.h"

namespace ASD1 {

    IterateurEnPreOrdre &IterateurEnPreOrdre::operator++() noexcept {
        // doit remplacer m par suivant(m) selon l'algorithme vu à la
        // video 5.05
/****
*
*  AJOUTEZ ICI VOTRE CODE
*
****/
        m = nullptr; // à retirer, mais il permet de ne pas boucler à l'infini avant d'écrire cette fonction
        return *this;
    }

    IterateurEnPreOrdre IterateurEnPreOrdre::operator++(int) noexcept {
        auto tmp{*this};
        operator++();
        return tmp;
    }

    IterateurEnPreOrdre::IterateurEnPreOrdre(Noeud const* _m)
            : m(_m) {}

    IterateurEnPreOrdre::IterateurEnPreOrdre()
            : IterateurEnPreOrdre(nullptr) {}

    bool IterateurEnPreOrdre::operator==(const IterateurEnPreOrdre &other) const noexcept {
        return m == other.m;
    }

    bool IterateurEnPreOrdre::operator!=(const IterateurEnPreOrdre &other) const noexcept {
        return m != other.m;
    }

    std::string const& IterateurEnPreOrdre::operator*() const noexcept {
        return m->etiquette;
    }

}