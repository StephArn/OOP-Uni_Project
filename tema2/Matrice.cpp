#include <iostream>
#include "Matrice.h"
#include "Complex.h"

template <class T>

Matrice<T>::Matrice(int lin, int col, Complex<T> nr) : lin{ lin }, col{ col } {
    v = new Complex<T> * [lin];
    for (int i = 0; i < lin; i++)
        v[i] = new Complex<T>[col];
    for (int i = 0; i < lin; i++)
        for (int j = 0; j < col; j++)
            v[i][j] = nr;
}
template <class T>

Matrice<T> ::~Matrice() {
    for (int i = 0; i < lin; i++)
        delete[] v[i];
    delete[] v;
    col = 0;
    lin = 0;

}

template <class T>

Matrice<T>::Matrice(const Matrice<T>& mat) {

    lin = mat.lin;
    col = mat.col;

    v = new Complex<T> * [lin];
    for (int i = 0; i < lin; i++)
        v[i] = new Complex<T>[col];
    for (int i = 0; i < lin; i++)
        for (int j = 0; j < col; j++)
            v[i][j] = mat.v[i][j];

}

template <class T>

Matrice<T>& Matrice<T>::operator =(const Matrice<T>& ob) {

    if (this == &ob) return *this;

    for (int i = 0; i < lin; i++)
        delete[] this->v[i];
    delete[] this->v;

    this->lin = ob.lin;
    this->col = ob.col;
    for (int i = 0; i < lin; i++)
        for (int j = 0; j < col; j++)
            this->v[i][j] = ob.v[i][j];
    return *this;
}

template <class T>

std::istream& operator >>(std::istream& input, Matrice<T>& mat) {

    for (int i = 0; i < mat.lin; i++)
        delete[] mat.v[i];
    delete[] mat.v;

    input >> mat.col >> mat.lin;
    mat.v = new Complex<T> * [mat.lin];
    for (int i = 0; i < mat.lin; i++)
        mat.v[i] = new Complex<T>[mat.col];
    for (int i = 0; i < mat.lin; i++)
        for (int j = 0; j < mat.col; j++)
            input >> mat.v[i][j];
    return input;
}

template <class T>

std::ostream& operator <<(std::ostream& output, const Matrice<T>& mat) {
    for (int i = 0; i < mat.lin; i++) {
        for (int j = 0; j < mat.col; j++)
            output << mat.v[i][j] << " ";
        output << '\n';
    }
    return output;
}

template <class T>

int Matrice<T>::get_lin() {
    return lin;
}

template <class T>

int Matrice<T>::get_col() {
    return col;
}

template <class T>

Complex<T>** Matrice<T>::get_mat() {
    return v;
}

template <class T>

Complex<T> Matrice<T>::setElem(int i, int j, Complex<T> x)
{
    v[i][j] = x;
}
