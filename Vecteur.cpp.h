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
    }
}

template<typename T>
Vecteur<T>::Vecteur(std::vector<T> v)
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
        throw;
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
        throw Null_length_error("Impossible de sommer les éléments d'un tableau vide");
    }

    T somme;//TODO à tester avec un cas quelconque
    for (T elem : data) {
        somme += elem;
    }
}

template<typename T>
Vecteur<T> Vecteur<T>::operator+(Vecteur otherVecteur) {

    if (this->size() != otherVecteur.size()) {
        // throw exception
        throw;
    }

    Vecteur<T> _this = *this;

    for (size_t i = 0; i < _this.size(); ++i)
        _this.at(i) += otherVecteur.at(i);

    return _this;
}

template<typename T>
Vecteur<T> Vecteur<T>::operator-(Vecteur otherVecteur) {

    if (this->size() != otherVecteur.size()) {
        // throw exception
        throw;
    }

    Vecteur<T> _this = *this;

    for (size_t i = 0; i < _this.size(); ++i)
    {
        try
        {
            T a=_this.at(i);
            T b=otherVecteur.at(i);
            T result = a-b;
            if(a>=T() and b>=T() and result > T())
            {
                throw Overflow("Dépassement de capacité");
            }
            
            if(a>=T() and b<T() and result < T())
            {
                throw Overflow("Dépassement de capacité");
            }
            
            if(a<T() and b>=T() and result > T())
            {
                throw Overflow("Dépassement de capacité");
            }
            
            _this.at(i) -= otherVecteur.at(i);
        }
        
        catch(std::length_error)
        {
            throw;
        }
    }

    return _this;
}

template<typename T>
Vecteur<T> Vecteur<T>::operator*(Vecteur otherVecteur) {

    if (this->size() != otherVecteur.size()) {
        // throw exception
        throw;
    }

    Vecteur<T> _this = *this;

    for (size_t i = 0; i < _this.size(); ++i)
        _this.at(i) *= otherVecteur.at(i);

    return _this;
}

template<typename T>
template<typename U>
Vecteur<T> Vecteur<T>::operator*(U value) {
    if (data.size() == 0) {
        throw Null_length_error("Impossible de sommer les éléments d'un tableau vide");
    }

    for (T elem : data) {
        elem *= value;
    }
}

#endif //LABO4_VECTEUR_CPP_H
