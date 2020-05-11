#include <iostream>
#include "Matrice_patratica.h"
#include "Matrice_oarecare.h"

using namespace std;

int main() {
   auto *m = new Matrice_patratica();
   cin >> *m;
   cout << *m;
   delete m;
   return 0;
}
