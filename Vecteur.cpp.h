//
// Created by deekay on 02/04/19.
//

#ifndef LABO4_VECTEUR_CPP_H
#define LABO4_VECTEUR_CPP_H

#include "Vecteur.h"
#include "Exceptions.h"


template<typename T>
Vecteur<T>::Vecteur(size_t size) {
    try {
        this->data = std::vector<T>(size);
    } catch (const std::bad_alloc &e) {
        throw;
    } catch (const std::length_error &e) {
        throw;
    }
}

template<typename T>
Vecteur<T>::Vecteur(std::vector<T> v)
        :data(v) {}
        :data(v) {}

template<typename T>
size_t Vecteur<T>::size() const {
    return data.size();
}

template<typename T>
T Vecteur<T>::at(size_t pos) const {
    try {
        return this->data.at(pos);
    } catch (const std::out_of_range &e) {
        std::string msg = "Vecteur::at() - ERROR : Position " + std::to_string(pos) + " is out of bounds";
        throw OutOfBounds(msg);
    }
}

template<typename T>
T &Vecteur<T>::at(size_t pos) {
    try {
        return this->data.at(pos);
    } catch (const std::out_of_range &e) {
        std::string msg = "Vecteur::at() - ERROR : Position " + std::to_string(pos) + " is out of bounds";
        throw OutOfBounds(msg);
    }
}

template<typename T>
void Vecteur<T>::resize(size_t newSize) {
    try {
        this->data.resize(newSize);
    } catch (const std::length_error &e) {
        throw;
    }
}

template<typename T>
T Vecteur<T>::somme() const {
    if (data.size() == 0) {
        throw NullLength("Vecteur::somme() - ERROR : Impossible to sum an empty Vecteur");
    }

    T somme = T();
    for (T elem : data) {
        somme = add(somme, elem);
    }
}

template<typename T>
Vecteur<T> Vecteur<T>::operator+(const Vecteur &rhs) {

    if (this->size() != rhs.size()) {
        throw SizeMismatch("Vecteur::+() - ERROR : Vecteur sizes don't match");
    }

    Vecteur<T> _this = *this;

    for (size_t i = 0; i < _this.size(); ++i) {
        try {
            _this.at(i) = add(_this.at(i), rhs.at(i));
        } catch (const std::length_error &e) {
            throw ArithmeticLengthError("Vecteur::+() - ERROR : Values used for operation caused were to long");
        }
    }

    return _this;
}

template<typename T>
Vecteur<T> Vecteur<T>::operator-(const Vecteur &rhs) {

    if (this->size() != rhs.size()) {
        throw SizeMismatch("Vecteur::-() - ERROR : Vecteur sizes don't match");
    }

    Vecteur<T> _this = *this;

    for (size_t i = 0; i < _this.size(); ++i) {
        try {
            _this.at(i) = subtract(_this.at(i), rhs.at(i));
        }
        catch (const std::length_error &e) {
            throw ArithmeticLengthError("Vecteur::-() - ERROR : Values used for operation caused were to long");
        }
    }

    return _this;
}

template<typename T>
Vecteur<T> Vecteur<T>::operator*(const Vecteur &rhs) {

    if (this->size() != rhs.size()) {
        throw SizeMismatch("Vecteur::*() - ERROR : Vecteur sizes don't match");
    }

    Vecteur<T> _this = *this;

    for (size_t i = 0; i < _this.size(); ++i) {
        _this.at(i) = multiply(this->at(i), rhs.at(i));
    }

    return _this;
}

template<typename T>
Vecteur<T> Vecteur<T>::operator*(T value) {
    if (data.size() == 0) {
        throw NullLength("Vecteur::*() - ERROR : Impossible to multiply an empty Vecteur");
    }

    Vecteur<T> _this = *this;

    for (T &elem : _this.data) {
        elem = multiply(elem, value);
    }

    return _this;
}


#endif //LABO4_VECTEUR_CPP_H
