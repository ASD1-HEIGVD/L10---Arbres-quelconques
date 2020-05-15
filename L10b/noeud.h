#ifndef ASD1_LABS_2020_NOEUD_H
#define ASD1_LABS_2020_NOEUD_H

#include <string>

namespace ASD1 {

    struct Noeud {
        std::string etiquette;
        Noeud *parent;
        Noeud *aine;
        Noeud *puine;
    };

}

#endif //ASD1_LABS_2020_NOEUD_H
