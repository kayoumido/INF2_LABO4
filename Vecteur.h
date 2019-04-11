//
// Created by deekay on 02/04/19.
//

#ifndef LABO4_VECTEUR_H
#define LABO4_VECTEUR_H

#include <vector>
#include <iostream>

template<typename T>
class Vecteur;

template<typename T>
std::ostream &operator<<(std::ostream &os, const Vecteur<T> &v) {
    os << "[";
    if(v.size())
    {
        os << v.at(0);
    }    
    for (size_t i = 1; i < v.size(); i++) {
        os << ", " << v.at(i);
    }
    os << "]";
    return os;
}

template<typename T>
Vecteur<T> operator*(const T& value, const Vecteur<T>& rhs)
{
    return rhs*value;
}

template<typename T>
class Vecteur {

private:
    std::vector<T> data;

    friend std::ostream &operator<<<T>(std::ostream &os, const Vecteur<T> &v);

public:

    Vecteur() = default;

    Vecteur(size_t size);

    Vecteur(std::vector<T> v);

    T &at(size_t pos);

    T at(size_t pos) const;

    size_t size() const;

    void resize(size_t newSize);

    T somme() const;

    Vecteur operator+(const Vecteur &rhs)const;

    Vecteur operator-(const Vecteur &rhs)const;

    Vecteur operator*(T value)const;

    Vecteur operator*(const Vecteur &rhs)const;
};


#include "Vecteur.cpp.h"

#endif //LABO4_VECTEUR_H
