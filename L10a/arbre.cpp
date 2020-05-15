#include <vector>
#include <sstream>
#include <utility>

#include "arbre.h"

namespace ASD1 {

    // pré-déclaration des fonctions annexes non exportées dans
    // le fichier header

    bool read_label(std::istringstream& s, std::string& label);
    Noeud* from_string(std::istringstream& s, Noeud* p);

    // pré-déclarez ici les vôtres si nécessaire

/***
*
*  AJOUTEZ ICI VOTRE CODE
*
****/

    // Constructeurs

    Arbre::Arbre() : racine(nullptr) {
    }

    Arbre::Arbre(std::string const& imbriquees) {
        std::istringstream s(imbriquees);
        racine = from_string(s, nullptr);
    }

    Arbre::Arbre(Arbre const& other) : Arbre() {
        // doit idéalement offrir une garantie de base, même si pas
        // testé par codecheck.
        //
        // Pour cela, il faut qu'avant d'allouer un nouveau noeud,
        // les noeuds déjà alloués soient tous déjà accrochés
        // à l'arbre pour que l'on puisse les détruire depuis
        // la racine.
/****
*
*  AJOUTEZ ICI VOTRE CODE
*
****/
    }

    Arbre& Arbre::operator= (Arbre const& other) {
        // doit offrir une garantie forte. peut utiliser copy and swap
/****
*
*  AJOUTEZ ICI VOTRE CODE
*
****/
        return *this;
    }

    Arbre::~Arbre() {
        // a écrire proprement même si pas testé par codecheck
/****
*
*  AJOUTEZ ICI VOTRE CODE
*
****/
    }

    // placez ici la définition des fonctions récursives déclarées
    // en début de fichier

/****
*
*  AJOUTEZ ICI VOTRE CODE
*
****/

    // fonctions utilisées par le constructeur prenant en entrée
    // des listes imbriquées

    bool read_label(std::istringstream& s, std::string& label) {
        static std::string const separators{"(,)"};
        std::ostringstream o;
        char c;
        while(s.get(c) and separators.find(c) == std::string::npos)
            o << c;
        if(s) s.putback(c);
        label = o.str();
        return not label.empty();
    }

    Noeud* from_string(std::istringstream& s, Noeud* p) {
        std::string label;
        if(not read_label(s,label)) return nullptr;

        Noeud* aine = new Noeud{label, p, nullptr, nullptr};
        Noeud* n = aine;

        char c;
        while(s.get(c)) {
            if(c == ',') {
                read_label(s,label);
                n->puine = new Noeud{label,p, nullptr, nullptr};
                n = n->puine;
            } else if (c == '(') {
                n->aine = from_string(s,n);
            } else { // c == ')'
                break;
            }
        }

        return aine;
    }
}