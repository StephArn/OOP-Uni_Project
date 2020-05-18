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
    for (int i = 0; i < lin; i++)
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

Matrice& Matrice::operator =(const Matrice&  ob) {

    if (this == &ob) return *this;

    for (int i = 0; i < col; i++)
        delete[] this->v[i];
    delete[] this->v;

    this->lin = ob.lin;
    this->col = ob.col;
    for(int i = 0; i < col; i++)
        for (int j = 0; j < lin; j++)
            this->v[i][j] = ob.v[i][j];
    return *this;
}

std::istream& operator >>(std::istream& input, Matrice& mat) {

    for (int i = 0; i < mat.col; i++)
        delete[] mat.v[i];
    delete[] mat.v;

    input >> mat.col >> mat.lin;
    mat.v = new Complex * [mat.col];
    for (int i = 0; i < mat.col; i++)
        mat.v[i] = new Complex[mat.lin];
    for (int i = 0; i < mat.col; i++)
        for (int j = 0; j < mat.lin; j++)
            input >> mat.v[j][i];
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
