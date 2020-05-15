#ifndef ASD1_LABS_2020_ARBREIMPL_H
#define ASD1_LABS_2020_ARBREIMPL_H

#include "noeud.h"
#include "arbre.h"

// vous pouvez placer ici toute inclusion / définition dont vous
// auriez besoin

/****
*
*  AJOUTEZ ICI VOTRE CODE
*
****/

namespace ASD1 {

    // vous pouvez placer ici toute fonction générique annexe dont
    // dont vous auriez besoin
/****
*
*  AJOUTEZ ICI VOTRE CODE
*
****/

    template<typename Function>
    void Arbre::preordre(Function f) {
/****
*
*  AJOUTEZ ICI VOTRE CODE
*
****/
        f("pre-ordre a mettre en oeuvre");
    }

    template<typename Function>
    void Arbre::postordre(Function f) {
/****
*
*  AJOUTEZ ICI VOTRE CODE
*
****/
        f("post-ordre a mettre en oeuvre");
    }

    template<typename Function>
    void Arbre::largeur(Function f) {
/****
*
*  AJOUTEZ ICI VOTRE CODE
*
****/
        f("largeur a mettre en oeuvre");
    }
}

#endif //ASD1_LABS_2020_ARBREIMPL_H