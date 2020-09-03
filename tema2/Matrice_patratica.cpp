#include "Matrice_patratica.h"
#include <cmath>

template <class T>

std::ostream& operator <<(std::ostream& output, Matrice_patratica<T>& mat)
{
    Matrice<T>& ob = mat;
    output << ob;

    Complex<T> d = det(mat, mat.lin);
    output << "Determinantul este: ";
    output << d;
    output << '\n';
    return output;
}

template <class T>

int Matrice_patratica<T>::verifica_triunghiulara() {
    int i, j, ok1 = 1, ok2 = 1, rez;
    for (i = 1; i < col; i++) {
        if (ok1 == 0) break;
        for (j = 0; j < i; j++) {
            if (ok1 == 0) break;
            if (v[i][j] != Complex<T>(0, 0)) {
                ok1 = 0;
            }

        }
    }

    for (i = 0; i < col - 1; i++) {
        if (ok2 == 0) break;
        for (j = i + 1; j < col; j++) {
            if (ok2 == 0) break;
            if (v[i][j] != Complex<T>(0, 0)) {
                ok2 = 0;
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

template <class T>

void Matrice_patratica<T>::verifica_diagonala() {
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

template <class T>

Complex<T> det(Matrice_patratica<T>& matrix, int n)
{
    int rez = matrix.verifica_triunghiulara();
    if (rez > 0) {
        Complex<T> diag_princip(1, 0);
        int i;
        for (i = 0; i < n; i++)
        {
            diag_princip = diag_princip * matrix.v[i][i];
        }
        return diag_princip;
    }

    Complex<T> determinant;
    Matrice_patratica<T> submatrix(n - 1, n - 1);

    if (n == 2) {
        Complex<T> a = (-1) * matrix.v[1][0];
        Complex<T> b = a * matrix.v[0][1];
        Complex<T> c = matrix.v[0][0] * matrix.v[1][1];
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
            determinant = determinant + Complex<T>((std::pow(-1, x), 0) * matrix.v[0][x] * det(submatrix, n - 1));
        }
    }
    return determinant;
}
