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
    os << v.at(0);
    for (size_t i = 1; i < v.size(); i++) {
        os << ", " << v.at(i);
    }
    os << "]";
    return os;
}

template<typename T>
class Vecteur {

private:
    std::vector<T> data;

    friend std::ostream &operator<<<T>(std::ostream &os, const Vecteur<T> &v);

public:
    Vecteur(size_t size);

    Vecteur(std::vector<T> v);

    T at(size_t pos) const;

    size_t size() const;

    void resize(size_t newSize);

    T somme() const;

    Vecteur operator+(Vecteur otherVecteur);

    Vecteur operator-(Vecteur otherVecteur);

    Vecteur operator*(T value);

    Vecteur operator*(Vecteur otherVecteur);
};


#include "Vecteur.cpp.h"

#endif //LABO4_VECTEUR_H
