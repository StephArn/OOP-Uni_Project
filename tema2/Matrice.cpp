#include <iostream>
#include "Matrice.h"
#include "Complex.h"


Matrice::Matrice(int col, int lin, Complex nr) : col{col}, lin{lin} {
    v = new Complex * [col];
    for (int i = 0; i < col; i++)
        v[i] = new Complex[lin];
    for (int i = 0; i < col; i++)
        for (int j = 0; j < lin; j++)
            v[i][j] = nr;
}

Matrice ::~Matrice() {
    for (int i = 0; i < col; i++)
        delete[] v[i];
    delete[] v;
    col = 0;
    lin = 0;

}

Matrice::Matrice(const Matrice &mat) {
    col = mat.col;
    lin = mat.lin;
    v = new Complex * [col];
    for (int i = 0; i < col; i++)
        v[i] = new Complex[lin];
    for (int i = 0; i < col; i++)
        for (int j = 0; j < lin; j++)
            v[i][j] = mat.v[i][j];

}

void swap(Matrice& a, Matrice& b) {
    std::swap(a.lin, b.lin);
    std::swap(a.col, b.col);
    std::swap(a.v, b.v);
}

Matrice& Matrice::operator =(Matrice &ob) {
    swap(*this, ob);
    return *this;
}

std::istream& operator >>(std::istream& input, Matrice& mat) {

    input >> mat.lin >> mat.col;
    mat.v = new Complex* [mat.lin];
    for (int i = 0; i < mat.lin; i++)
        mat.v[i] = new Complex[mat.col];
    for (int i = 0; i < mat.lin; i++)
        for (int j = 0; j < mat.col; j++)
            input >> mat.v[i][j];
    return input;
}

std::ostream& operator <<(std::ostream& output, const Matrice& mat) {
    for (int i = 0; i < mat.lin; i++) {
        for (int j = 0; j < mat.col; j++)
            output << mat.v[i][j] << " ";
        output << '\n';
    }
    return output;
}

int Matrice::get_lin() {
    return lin;
}

int Matrice::get_col() {
    return col;
}

Complex** Matrice::get_mat() {
    return v;
}
