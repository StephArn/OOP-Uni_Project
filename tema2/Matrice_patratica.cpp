#include "Matrice_patratica.h"
#include <cmath>

/*Matrice_patratica::Matrice_patratica(int dim) : dim(dim) {
    v = new Complex * [dim];
    for (int i = 0; i < dim; i++)
        v[i] = new Complex[dim];
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            v[i][j] = Complex(0, 0);
}
void swap(Matrice_patratica &a, Matrice_patratica& b) {
    using std::swap;
    swap(a.dim, b.dim);
    swap(a.v, b.v);
}
Matrice_patratica Matrice_patratica:: operator=(Matrice_patratica ob) {
    swap(*this, ob);
    return *this;
}
 */

Matrice_patratica::Matrice_patratica(int dim, Complex nr) : dim{ dim } {
    v = new Complex * [dim];
    for (int i = 0; i < dim; i++)
        v[i] = new Complex[dim];
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < lin; j++)
            v[i][j] = nr;
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

std::ostream& operator <<(std::ostream& output, Matrice_patratica& mat) {
    for (int i = 0; i < mat.dim; i++) {
        for (int j = 0; j < mat.dim; j++)
            output << mat.v[i][j] << " ";
        output << '\n';
    }
    Complex d = det(mat, mat.dim);
    output << "Determinantul este: ";
    output << d;
    output << '\n';
    return output;
}

int Matrice_patratica::verifica_triunghiulara() {
    int i, j, ok1 = 1, ok2 = 1, rez;
    for (i = 1; i < dim; i++) {
        if (ok1 == 0) break;
        for (j = 0; j < i; j++) {
            if (ok1 == 0) break;
            if (v[i][j] != Complex(0, 0)) {
                ok1 = 0;
                //break;
            }
            
        }
    }

    for (i = 0; i < dim - 1; i++) {
        if (ok2 == 0) break;
        for (j = i + 1; j < col; j++) {
            if (ok2 == 0) break;
            if (v[i][j] != Complex(0, 0)) {
                ok2 = 0;
                //break;
            }
            
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
    int triunghiulara;
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

Complex det(Matrice_patratica& matrix, int n)
{
    int rez = matrix.verifica_triunghiulara();
    if (rez > 0) {
        Complex diag_princip(1, 0);
        int i;
        for (i = 0; i < n; i++)
        {
            diag_princip = diag_princip * matrix.v[i][i];
        }
        return diag_princip;
    }

    Complex determinant;
    Matrice_patratica submatrix;
    submatrix.dim = n - 1;
    if (n == 2) {
        Complex a = (-1) * matrix.v[1][0];
        Complex b = a * matrix.v[0][1];
        Complex c = matrix.v[0][0] * matrix.v[1][1];
        return b + c;

    }
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
            determinant = determinant + Complex((std::pow(-1, x), 0) * matrix.v[0][x] * det(submatrix, n - 1));
        }
    }
    return determinant;
}
