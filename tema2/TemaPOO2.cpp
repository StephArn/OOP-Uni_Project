#include <iostream>
#include "Matrice_patratica.h"
#include "Matrice_oarecare.h"

using namespace std;

int main() {
   auto *m = new Matrice_patratica();
   auto* n = new Matrice_oarecare();
   cin >> *m;
   cout << *m;
   cin >> *n;
   cout << *n;
   m->verifica_diagonala();
   delete m;
   delete n;

   return 0;
}
