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
class Matrice {
private:
    std::vector<Vecteur<T>> data;

    friend std::ostream &operator<<(std::ostream &os, const Matrice<T> &m);

public:
    Matrice();

    Matrice(size_t l);//Erreur de longueur potentielle
    Matrice(size_t l, size_t c);//Erreur de longueur potentiellle
    Vecteur<T> at(size_t n);//Erreur d'accès potentielle
    size_t size();

    void resize(size_t l);//Erreur de longueur potentielle
    void resize(size_t l, size_t c);//Erreur de longueur potentielle
    bool estVide();

    bool estCarree();//Une matrice carrée est-elle forcément régulière ?
    bool estReguliere();

    Vecteur<T> sommeLigne();//Erreur à jeter pour matrice de taille nulle ?
    Vecteur<T> sommeColonne();//Erreur à jeter pour matrice de taille nulle ?
    T sommeDiagonaleGD();//Erreur d'accès à jeter pour matrice de taille nulle ? Ou non carrée ?
    T sommeDiagonaleDG();//Erreur d'accès à jeter pour matrice de taille nulle ? Ou non carrée ?
    Matrice operator*(T val);//Erreur pour matrice de taille nulle ?
    Matrice operator*(Matrice otherMatrice);//Erreur pour matrice de taille nulle ?
    Matrice operator+(Matrice otherMatrice);//Erreur pour matrice de taille nulle ?
};

#include "Matrice.cpp.h"

#endif //LABO4_MATRICE_H
