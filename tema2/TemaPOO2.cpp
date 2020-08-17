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
    cout << "Verificam operatorii + si *: " << c << endl;
    cout << "Verificam getterii: " << a.getReal() << endl;
    cout << b.getImaginar() << endl;

    cout << "Verificam operatorii == si !=: ";
    if (a == b)
        cout << a;
    if (a != b)
        cout << b;
    cout << endl;
    
    cout << "Verificam operatorul * cu int: ";
    int x;
    f >> x;
    Complex d;
    d = x * c;
    cout << d << endl;

    cout << "Gata testarea." << endl;

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
