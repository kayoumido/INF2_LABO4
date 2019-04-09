//
// Created by deekay on 02/04/19.
//

#ifndef LABO4_MATRICE_CPP_H
#define LABO4_MATRICE_CPP_H

#include "Matrice.h"
#include "Vecteur.h"

template <typename T>
Matrice<T>::Matrice()
:data(0)
{}

template <typename T>
Matrice<T>::Matrice(size_t l)
{
    data(l);
}

template <typename T>
Matrice<T>::Matrice(size_t l, size_t c)
{
    data(l, c);
}

template <typename T>
Vecteur<T> Matrice<T>::at(size_t n)
{
    return data.at(n);
}

template <typename T>
size_t Matrice<T>::size()
{
    return data.size();
}

template <typename T>
void Matrice<T>::resize(size_t l)
{
    
}

template <typename T>
void Matrice<T>::resize(size_t l, size_t c)
{
    
}

template <typename T>
bool Matrice<T>::estVide()
{
    
}

template <typename T>
bool Matrice<T>::estCarree()
{
    
}

template <typename T>
bool Matrice<T>::estReguliere()
{
    
}

template <typename T>
Vecteur<T> Matrice<T>::sommeLigne()
{
    
}

template <typename T>
Vecteur<T> Matrice<T>::sommeColonne()
{
    
}

template <typename T>
T Matrice<T>::sommeDiagonaleGD()
{
    
}

template <typename T>
T Matrice<T>::sommeDiagonaleDG()
{
    
}

template <typename T>
Matrice<T> Matrice<T>::operator*(T val)
{
    
}

template <typename T>
Matrice<T> Matrice<T>::operator*(Matrice otherMatrice)
{
    
}

template <typename T>
Matrice<T> Matrice<T>::operator+(Matrice otherMatrice)
{
    
}

#endif //LABO4_MATRICE_CPP_H
