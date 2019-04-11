//
// Created by deekay on 02/04/19.
//

#ifndef LABO4_MATRICE_H
#define LABO4_MATRICE_H

#include "Vecteur.h"
#include <vector>

template<typename T>
class Matrice;

template<typename T>
std::ostream &operator<<(std::ostream &os, const Matrice<T> &m) {
    os << "[";
    for (size_t i = 0; i < m.size(); i++) {
        os << m.at(i);
    }
    os << "]";
    return os;
}

template<typename T>
Matrice<T> operator*(const T& value, const Matrice<T> rhs)
{
    return rhs*value;
}

template<typename T>
class Matrice {
private:
    Vecteur<Vecteur<T>> data;

    friend std::ostream &operator<<(std::ostream &os, const Matrice<T> &m);

public:
    Matrice() = default;

    Matrice(size_t rows);//Erreur de longueur potentielle
    Matrice(size_t rows, size_t c);//Erreur de longueur potentiellle
    Vecteur<T> &at(size_t pos);
    Vecteur<T> at(size_t pos) const;
    size_t size() const;

    void resize(size_t l);//Erreur de longueur potentielle
    void resize(size_t l, size_t c);//Erreur de longueur potentielle
    bool estVide() const;

    bool estCarree() const;//Une matrice carrée est-elle forcément régulière ?
    bool estReguliere() const;

    Vecteur<T> sommeLigne() const;//Erreur à jeter pour matrice de taille nulle ?
    Vecteur<T> sommeColonne() const;//Erreur à jeter pour matrice de taille nulle ?
    T sommeDiagonaleGD() const;//Erreur d'accès à jeter pour matrice de taille nulle ? Ou non carrée ?
    T sommeDiagonaleDG() const;//Erreur d'accès à jeter pour matrice de taille nulle ? Ou non carrée ?
    Matrice operator*(T val) const;//Erreur pour matrice de taille nulle ?
    Matrice operator*(const Matrice &rhs) const;//Erreur pour matrice de taille nulle ?
    Matrice operator+(const Matrice &rhs) const;//Erreur pour matrice de taille nulle ?
};

#include "Matrice.cpp.h"

#endif //LABO4_MATRICE_H
