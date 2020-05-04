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

Matrice_patratica& Matrice_patratica:: operator=( Matrice_patratica& ob) {
    swap(*this, ob);
    return *this;
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

int Matrice_patratica::verifica_triunghiulara() {
    int i, j, ok1 = 1, ok2 = 1, rez;
    for (i = 1; i < dim; i++) {
        for (j = 0; j < i; j++) {
            if (v[i][j] != Complex(0, 0)) {
                ok1 = 0;
                break;
            }
            if (ok1 == 0) break;
        }
    }

    for (i = 0; i < dim - 1; i++) {
        for (j = i + 1; j < dim; j++) {
            if (v[i][j] != Complex(0, 0)) {
                ok2 = 0;
                break;
            }
            if (ok2 == 0) break;
        }
    }

    if (ok1 == 1) {
        if (ok2 == 1) rez = 3;
        else rez = 1;
    }
    else if (ok2 == 1) rez = 2;
    else rez = 0;

    return rez;
}

void Matrice_patratica::verifica_diagonala() {
    int triunghiulara, i, j;
    triunghiulara = verifica_triunghiulara();
    if (triunghiulara == 3)
    {
        std::cout << "Matricea este diagonala.";
        return;
    }
    else if (triunghiulara == 2 or triunghiulara == 1)
    {
        std::cout << "Matricea nu este diagonala.";
        return;
    }
    else std::cout << "Matricea nu este nici triunghiulara, nici diagonala.";
}

Complex Matrice_patratica:: det(Matrice_patratica matrix, int n)
{
    int rez = verifica_triunghiulara();
    if (rez > 0) return Complex(0, 0);

    Complex determinant;
    Matrice_patratica submatrix;
    if (n == 2)
        return ((matrix.v[0][0] * matrix.v[1][1]) + (-1)*matrix.v[1][0] * matrix.v[0][1]));
    else {
        for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == x)
                        continue;
                    submatrix.v[subi][subj] = matrix.v[i][j];
                    subj++;
                }
                subi++;
            }
            determinant = determinant + (pow(-1, x) * matrix.v[0][x] * det(submatrix, n - 1));
        }
    }
    return determinant;
