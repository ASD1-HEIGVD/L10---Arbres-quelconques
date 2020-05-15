//IN A(B(D,E),C(F))
//IN A(B(F,G(L,M)),C,D(H),E(I,J,K))
//IN 13(8(5(3(2(1,1),1),2(1,1)),3(2(1,1),1)),5(3(2(1,1),1),2(1,1)))
//IN Hominidae(Ponginae(Orang-Outan),Homininae(Gorillini(Gorille),Hominini(Panini(Pan(Bonobo,Chimpanze)),Hominina(Humain))))

#include <iostream>
#include <iomanip>
#include <string>

#include "arbre.h"

using namespace std;

void afficher(string const& s) {
    cout << s << " ";
}

int main() {

    // Entrées possibles :
    //
    // A(B(D,E),C(F))
    // A(B(F,G(L,M)),C,D(H),E(I,J,K))
    // 13(8(5(3(2(1,1),1),2(1,1)),3(2(1,1),1)),5(3(2(1,1),1),2(1,1)))
    // Hominidae(Ponginae(Orang-Outan),Homininae(Gorillini(Gorille),Hominini(Panini(Pan(Bonobo,Chimpanze)),Hominina(Humain))))

    int const W{18};

    cout << "Entrez l'arbre sous forme de liste imbriquee : \n";
    string input;
    getline(cin, input);

    ASD1::Arbre a(input);

    cout << "\n\nImbriquees : ";
    cout << a.listes_imbriquees();

    cout << "\n\nIndentee :";
    cout << "\n\n" << a.representation_indentee();

    cout << "\n";
}

