#include <iostream>
#include "Complex.h"
#include "Matrice.h"
#include "Matrice_patratica.h"

int main() {
    Matrice_patratica* m = new Matrice_patratica();
    std::cin >> *m;
    std::cout << *m;
    delete m;
    return 0;
}
