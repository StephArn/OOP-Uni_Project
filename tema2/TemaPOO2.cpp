#include <iostream>
#include "Matrice_patratica.h"
#include "Matrice_oarecare.h"

using namespace std;

int main() {
   auto *m = new Matrice_patratica();
   auto* n = new Matrice_oarecare();
   cout << "Matricea patratica:" << endl;;
   cin >> *m;
   cout << *m;
   cout << endl;
   cout << "Matricea oarecare:" << endl;;
   cin >> *n;
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
