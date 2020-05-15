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

Matrice& Matrice::operator =(const Matrice&  ob) {
    if (this == &ob) return *this;
    for (int i = 0; i < col; i++)
        delete[] this->v[i];
    delete[] this->v;
    this->col = 0;
    this->lin = 0;
    this->lin = ob.lin;
    this->col = ob.col;
    for(int i = 0; i < col; i++)
        for (int j = 0; j < lin; j++)
            this->v[i][j] = ob.v[i][j];
    return *this;
}

std::istream& operator >>(std::istream& input, Matrice& mat) {
    for (int i = 0; i < mat.lin; i++)
        delete[] mat.v[i];
    delete[] mat.v;
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
