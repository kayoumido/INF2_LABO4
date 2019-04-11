//
// Created by deekay on 02/04/19.
//

#ifndef LABO4_MATRICE_CPP_H
#define LABO4_MATRICE_CPP_H

#include "Matrice.h"
#include "Vecteur.h"
#include "Exceptions.h"

template<typename T>
Matrice<T>::Matrice()
        :data(0) {}

template<typename T>
Matrice<T>::Matrice(size_t l) {
    try {
        data(l);
    }
    catch (const std::length_error &e) {
        throw;
    }
    catch (const std::bad_alloc &e) {
        throw;
    }
}

template<typename T>
Matrice<T>::Matrice(size_t l, size_t c) {
    try {
        data(l, c);
    }
    catch (const std::length_error &e) {
        throw;
    }
    catch (const std::bad_alloc &e) {

    }
    //TODO : récupérer les erreurs pouvant être jetées par le constructeur de Vecteur
}

template<typename T>
Vecteur<T> Matrice<T>::at(size_t n) {
    try {
        return data.at(n);
    }
    catch (const std::out_of_range &e) {
        throw;
    }
}

template<typename T>
size_t Matrice<T>::size() {
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
    //TODO : récupérer les erreurs pouvant être jetées par le constructeur de Vecteur
}

template<typename T>
bool Matrice<T>::estVide() {
    return data.empty();
}

template<typename T>
bool Matrice<T>::estCarree() {
    return (estReguliere() and data.size() == data.at(0).size());
}

template<typename T>
bool Matrice<T>::estReguliere() {
    bool regulier = true;
    for (size_t i = 1; i < data.size(); ++i) {
        regulier = regulier and data.at(1).size() == data.at(i - 1).size();
    }
    return regulier;
}

template <typename T>
Vecteur<T> Matrice<T>::sommeLigne()
{
    Vecteur<T> vecteurSomme(data.size());
    for(size_t i=0; i<data.size(); ++i)
    {
        T somme;
        for (size_t j=0; j<data.at(i).size(); ++j)
        {
            somme += data.at(i).at(j);
        }
        vecteurSomme.at(i) = somme;
    }
    return vecteurSomme;
}

template <typename T>
Vecteur<T> Matrice<T>::sommeColonne()
{
    Vecteur<T> vecteurSomme(data.at(0).size());
    for(size_t i=0; i<data.at(0).size(); ++i)
    {
        T somme;
        for(size_t j=0; j<data.size(); ++j)
        {
            somme += data.at(j).at(i);
        }
        vecteurSomme.at(i) = somme;
    }
    return vecteurSomme;
}

template <typename T>
T Matrice<T>::sommeDiagonaleGD()
{
    T somme;
    for (size_t i=0; i<data.size(); ++i)
    {
        somme += data.at(i).at(i);
    }
    return somme;
}

template <typename T>
T Matrice<T>::sommeDiagonaleDG()
{
    T somme;
    for (size_t i=0; i<data.size(); ++i)
    {
        somme += data.at(data.size()-i-1).at(i);
    }
    return somme;
}

template <typename T>
Matrice<T> Matrice<T>::operator*(T val)
{
    Matrice<T> produit(data.size());
    for(size_t i=0; i<data.size(); ++i)
    {
        produit.at(i) = data.at(i)*val;
    }
    return produit;
}

template <typename T>
Matrice<T> Matrice<T>::operator*(Matrice otherMatrice)
{
    Matrice<T> MatriceProduit;
    for(size_t i=0; i<data.size(); ++i)
    {
        Vecteur<T> VecteurProduit = data.at(i)*otherMatrice.at(i);
        MatriceProduit.at(i) = VecteurProduit;
    }
    return MatriceProduit;
}

template <typename T>
Matrice<T> Matrice<T>::operator+(Matrice otherMatrice)
{
    Matrice<T> MatriceSomme;
    for(size_t i=0; i<data.size(); ++i)
    {
        Vecteur<T> VecteurSomme = data.at(i)+otherMatrice.at(i);
        MatriceSomme.at(i) = VecteurSomme;
    }
    return MatriceSomme;
}

#endif //LABO4_MATRICE_CPP_H
