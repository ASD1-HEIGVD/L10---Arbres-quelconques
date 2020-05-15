#include "iterateurPostOrdre.h"

namespace ASD1 {

    Noeud const* IterateurEnPostOrdre::debut(Noeud const* r) noexcept {
        // doit retourner le premier noeud d'un parcours post-ordonné,
        // comme dans l'algorithme vu à la video 5.05
/****
*
*  AJOUTEZ ICI VOTRE CODE
*
****/
        return r;  // a modifier, juste là pour compiler
    }

    IterateurEnPostOrdre& IterateurEnPostOrdre::operator++() noexcept {
        // doit remplacer m par suivant(m) selon l'algorithme vu à la
        // video 5.05
/****
*
*  AJOUTEZ ICI VOTRE CODE 
*
****/
        m = nullptr; // a modifier, juste là pour ne pas boucler infiniment
        return *this;
    }

    IterateurEnPostOrdre IterateurEnPostOrdre::operator++(int) noexcept
    {
        auto tmp{*this};
        operator++();
        return tmp;
    };

    IterateurEnPostOrdre::IterateurEnPostOrdre(Noeud const*_m)
            : m(_m)
    { }

    IterateurEnPostOrdre::IterateurEnPostOrdre()
            : IterateurEnPostOrdre(nullptr)
    { }

    bool IterateurEnPostOrdre::operator== (const IterateurEnPostOrdre &other) const noexcept {
        return m == other.m;
    }

    bool IterateurEnPostOrdre::operator!=(const IterateurEnPostOrdre &other) const noexcept {
        return m != other.m;
    }

    std::string const& IterateurEnPostOrdre::operator*() const noexcept {
        return m->etiquette;
    }
}