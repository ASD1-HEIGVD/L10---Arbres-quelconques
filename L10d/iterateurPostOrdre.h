#ifndef ASD1_LABS_2020_ITERATEURPOSTORDRE_H
#define ASD1_LABS_2020_ITERATEURPOSTORDRE_H

#include "noeud.h"
#include <iterator>

namespace ASD1 {

    class IterateurEnPostOrdre : public std::iterator<std::forward_iterator_tag, std::string> {

        friend class Arbre; // pour laisser accèder au constructeur privé
                            // et à éa fonction debut

    private:
        Noeud const* m;

        IterateurEnPostOrdre(Noeud const* _m);

        static Noeud const* debut(Noeud const* r) noexcept;

    public:
        IterateurEnPostOrdre();

        IterateurEnPostOrdre &operator++() noexcept;

        IterateurEnPostOrdre operator++(int) noexcept;

        bool operator==(const IterateurEnPostOrdre &i) const noexcept;

        bool operator!=(const IterateurEnPostOrdre &i) const noexcept;

        std::string const& operator*() const noexcept;
    };
}

#endif //ASD1_LABS_2020_ITERATEURPOSTORDRE_H
