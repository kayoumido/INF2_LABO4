//
// Created by deekay on 02/04/19.
//

#ifndef LABO4_MATRICE_CPP_H
#define LABO4_MATRICE_CPP_H

#include <string>
#include "Matrice.h"
#include "Vecteur.h"
#include "Exceptions.h"


template<typename T>
Matrice<T>::Matrice(size_t rows) : data(rows) {}

template<typename T>
Matrice<T>::Matrice(size_t rows, size_t cols) {

    if (rows == 0 and cols)
        throw SizeMismatch(
                "Matrice::Matrice(rows, cols) - ERROR : Their can't be a number of cols "
                "if the number of rows is set to 0"
        );

    for (size_t i = 0; i < rows; ++i) {
        this->data.at(i) = Vecteur<T>(cols);
    }
}

template<typename T>
Vecteur<T> &Matrice<T>::at(size_t pos) {
    try {
        return this->data.at(pos);
    }
    catch (const OutOfBounds &e) {
        std::string msg = "Matrice::at() - ERROR : Position " + std::to_string(pos) +
                          " is out of bounds\n" + e.what();
        throw OutOfBounds(msg);
    }
}


template<typename T>
Vecteur<T> Matrice<T>::at(size_t pos) const {
    try {
        return data.at(pos);
    }
    catch (const OutOfBounds &e) {
        std::string msg = "Matrice::at() - ERROR : Position " + std::to_string(pos) +
                          " is out of bounds\n" + e.what();
        throw OutOfBounds(msg);
    }
}


template<typename T>
size_t Matrice<T>::size() const {
    return data.size();
}

template<typename T>
void Matrice<T>::resize(size_t l) {
    try {
        data.resize(l, Vecteur<T>());
    }
    catch (const std::length_error &e) {
        throw;
    }
    catch (const std::bad_alloc &e) {
        throw;
    }
}

template<typename T>
void Matrice<T>::resize(size_t l, size_t c) {
    try {
        data.resize(l, Vecteur<T>(c));
    }
    catch (const std::length_error &e) {
        throw;
    }
    catch (const std::bad_alloc &e) {
        throw;
    }
}

template<typename T>
bool Matrice<T>::estVide() const {
    return data.empty();
}

template<typename T>
bool Matrice<T>::estCarree() const {
    return (estReguliere() and data.size() == data.at(0).size());
}

template<typename T>
bool Matrice<T>::estReguliere() const {
    for (size_t i = 1; i < data.size(); ++i) {

        if (data.at(i).size() != data.at(i - 1).size())
            return false;
    }
    return true;
}

template<typename T>
Vecteur<T> Matrice<T>::sommeLigne() const {
    if (estVide())
        throw NullLength("Matrice::someLigne() - ERROR : Impossible to sum an empty Matrice");

    Vecteur<T> result(this->data.size());
    for (size_t row = 0; row < this->data.size(); ++row) {
        try {
            result.at(row) = this->data.at(row).somme();
        } catch (const NullLength &e) {
            std::string msg = "Matrice::sommeLigne() - ERROR : Empty line\n" + e.what();
            throw NullLength(msg);
        } catch (const ArithmeticOverflow &e) {
            std::string msg = "Matrice::sommeLigne() - ERROR : Line n°"
            std::to_string(row)
            "caused an overflow\n"
            + e.what();
            throw ArithmeticOverflow(msg);
        }
    }

    return result;
}

template<typename T>
Vecteur<T> Matrice<T>::sommeColonne() const {
    if (estVide())
        throw NullLength("Matrice::someColonne() - ERROR : Impossible to sum an empty Matrice");

    Vecteur<T> result(this->data.size());

    for (size_t row = 0; row < this->data.size(); ++row) {

        for (size_t col = 0; col < this->data.at(row).size(); ++col) {
            try {
                result.at(row) = add(result.at(row), this->data.at(row).at(col));
            } catch (const ArithmeticOverflow &e) {
                std::string msg = "Matrice::sommeColonne() - ";
                msg += e.what();

                throw ArithmeticOverflow(msg);
            }
        }
    }

    return result;
}

template<typename T>
T Matrice<T>::sommeDiagonaleGD() const {
    if (estVide())
        throw NullLength("Matrice::sommeDiagonaleGD() - ERROR : Impossible to sum an empty Matrice");

    T somme = T();
    for (size_t i = 0; i < this->data.size(); ++i) {

        try {
            somme = add(somme, this->data.at(i).at(i));
        } catch (const ArithmeticOverflow &e) {
            std::string msg = "Matrice::sommeDiagonaleGD() - ";
            msg += e.what();

            throw ArithmeticOverflow(msg);
        }
    }
    return somme;
}

template<typename T>
T Matrice<T>::sommeDiagonaleDG() const {
    if (estVide())
        throw NullLength("Matrice::sommeDiagonaleDG() - ERROR : Impossible to sum an empty Matrice");


    T somme = T();
    for (size_t i = 0; i < data.size(); ++i) {
        try {
            somme = add(somme, this->data.at(this->data.size() - i - 1).at(i));
        } catch (const ArithmeticOverflow &e) {
            std::string msg = "Matrice::sommeDiagonaleDG() - ";
            msg += e.what();

            throw ArithmeticOverflow(msg);
        }
    }
    return somme;
}

template<typename T>
Matrice<T> Matrice<T>::operator*(T val) const {
    if (estVide())
        throw NullLength("Matrice::*() - ERROR : Impossible to sum an empty Matrice");

    Matrice<T> _this(data.size());

    for (T &elem : _this.data) {
        try {
            elem = elem * val;
        } catch (const ArithmeticOverflow &e) {
            std::string msg = "Matrice::*() - ";
            msg += e.what();

            throw ArithmeticOverflow(msg);
        }
    }

    return _this;
}

template<typename T>
Matrice<T> Matrice<T>::operator*(const Matrice &rhs) const {

    if (this->size() != rhs.size()) {
        throw SizeMismatch("Matrice::*() - ERROR : Matrice sizes don't match");
    }

    Matrice<T> _this = *this;

    for (size_t i = 0; i < _this.size(); ++i) {

        try {
            _this.at(i) = _this.at(i) * rhs.at(i);
        } catch (const ArithmeticOverflow &e) {
            std::string msg = "Matrice::*() - ERROR : Overflow happened.\n";
            msg += e.what();

            throw ArithmeticOverflow(msg);
        }
    }
    return _this;
}

template<typename T>
Matrice<T> Matrice<T>::operator+(const Matrice &rhs) const {


    if (this->size() != rhs.size()) {
        throw SizeMismatch("Matrice::+() - ERROR : Matrice sizes don't match");
    }

    Matrice<T> _this = *this;

    for (size_t i = 0; i < _this.size(); ++i) {

        try {
            _this.at(i) = _this.at(i) + rhs.at(i);
        } catch (const ArithmeticOverflow &e) {
            std::string msg = "Matrice::*() - ERROR : Overflow happened.\n";
            msg += e.what();

            throw ArithmeticOverflow(msg);
        }
    }
    return _this;
}

#endif //LABO4_MATRICE_CPP_H
