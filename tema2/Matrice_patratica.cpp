#include "Matrice_patratica.h"
Matrice_patratica::Matrice_patratica(int dim) : dim(dim) {
    v = new Complex * [dim];
    for (int i = 0; i < dim; i++)
        v[i] = new Complex[dim];
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            v[i][j] = Complex(0, 0);
}

Matrice_patratica::Matrice_patratica(const Matrice_patratica& ob) {
    dim = ob.dim;
    v = new Complex * [dim];
    for (int i = 0; i < dim; i++)
        v[i] = new Complex[dim];
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            v[i][j] = ob.v[i][j];

}

Matrice_patratica ::~Matrice_patratica() {
    std::cout << "destr";
    for (int i = 0; i < dim - 1; i++)
        delete[] v[i];
    delete[] v;
    dim = 0;
}

std::istream& operator >>(std::istream& input, Matrice_patratica& mat) {

    input >> mat.dim;
    mat.v = new Complex * [mat.dim];
    for (int i = 0; i < mat.dim; i++)
        mat.v[i] = new Complex[mat.dim];
    for (int i = 0; i < mat.dim; i++)
        for (int j = 0; j < mat.dim; j++)
            input >> mat.v[i][j];
    return input;
}

std::ostream& operator <<(std::ostream& output, const Matrice_patratica& mat) {
    for (int i = 0; i < mat.dim; i++) {
        for (int j = 0; j < mat.dim; j++)
            output << mat.v[i][j] << " ";
        output << '\n';
    }
    return output;
}

void Matrice_patratica::verifica(Matrice& matrice) {}
