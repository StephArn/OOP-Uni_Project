#include <iostream>
#include <fstream>
#include "Matrice_patratica.h"
#include "Matrice_oarecare.h"

using namespace std;

ifstream f("intrare.txt");

int main() {

    Complex a, b;
    f >> a >> b;
    Complex c;
    c = a + b;
    c = a * b;
    cout << c << endl;
    cout << a.getReal() << endl;
    cout << b.getImaginar() << endl;

    auto* m = new Matrice_patratica();
    auto* n = new Matrice_oarecare();
    cout << "Matricea patratica:" << endl;
    f >> *m;
    cout << *m;
    cout << endl;
    cout << "Matricea oarecare:" << endl;
    f >> *n;
    cout << *n;
    cout << endl;
    cout << "Verificam daca matricea patratica e diagonala:" << endl;
    m->verifica_diagonala();
    cout << endl;
    cout << "Verificam daca matricea oarecare e diagonala:" << endl;
    n->verifica_diagonala();
    delete m;
    delete n;
    return 0;
}
