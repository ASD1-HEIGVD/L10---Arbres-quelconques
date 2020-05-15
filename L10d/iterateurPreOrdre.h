#ifndef ASD1_LABS_2020_ITERATEURPREORDRE_H
#define ASD1_LABS_2020_ITERATEURPREORDRE_H

#include <iterator>
#include "noeud.h"

#endif //ASD1_LABS_2020_ITERATEURPREORDRE_H
namespace ASD1 {

    class IterateurEnPreOrdre : public std::iterator<std::forward_iterator_tag,std::string> {

        friend class Arbre; // pour laisser accèder au constructeur privé

    private:
        Noeud const* m;

        IterateurEnPreOrdre(Noeud const* _m);

    public:

        IterateurEnPreOrdre();

        IterateurEnPreOrdre &operator++() noexcept;

        IterateurEnPreOrdre operator++(int) noexcept;

        bool operator==(const IterateurEnPreOrdre &i) const noexcept;

        bool operator!=(const IterateurEnPreOrdre &i) const noexcept;

        std::string const& operator*() const noexcept;
    };
}