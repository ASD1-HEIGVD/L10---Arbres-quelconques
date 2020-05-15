#include <vector>
#include <sstream>
#include <utility>

#include "arbre.h"

namespace ASD1 {

    // pré-déclaration des fonctions annexes non exportées dans
    // le fichier header

    bool read_label(std::istringstream& s, std::string& label);
    Noeud* from_string(std::istringstream& s, Noeud* p);


    // mise en oeuvre des fonctions publiques

    // Itérateurs en pré et post ordre

    Arbre::iterator Arbre::begin() const noexcept {
        return iterator(racine);
    }

    Arbre::iterator Arbre::end() const noexcept {
        return iterator(nullptr);
    }

    Arbre::post_iterator Arbre::pbegin() const noexcept {
        return post_iterator(post_iterator::debut(racine));
    }

    Arbre::post_iterator Arbre::pend() const noexcept {
        return post_iterator(nullptr);
    }

    // Constructeurs

    Arbre::Arbre() : racine(nullptr) {
    }

    Arbre::Arbre(std::string const& imbriquees) {
        std::istringstream s(imbriquees);
        racine = from_string(s, nullptr);
    }

    Arbre::~Arbre() {
        // a écrire proprement même si pas testé par codecheck
/****
*
*  AJOUTEZ ICI VOTRE CODE
*
****/
    }

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