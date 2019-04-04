//
// Created by deekay on 02/04/19.
//

#ifndef LABO4_VECTEUR_CPP_H
#define LABO4_VECTEUR_CPP_H

#include "Vecteur.h"

template <typename T>
Vecteur<T>::Vecteur(std::vector<T> v)
:data(v)
{}

template <typename T>
size_t Vecteur<T>::size() const
{
    return data.size();
}

template <typename T>
T Vecteur<T>::somme() const
{
    if(data.size() == 0)
    {
        std::exception e; //TODO : Créer classe pour ce type d'exception
        throw e;
    }
        
    T somme(0);//TODO à tester avec un cas quelconque
    for (T elem : data)
    {
        somme += elem;
    }
}

template <typename T> template <typename U>
Vecteur<T> Vecteur<T>::operator*(U value)
{
    if(data.size() == 0)
    {
        std::exception e; //TODO : Créer classe pour ce type d'exception
        throw e;
    }

    //TODO : Erreur si tableau vide ?
    for(T elem : data)
    {
        elem *= value;
    }
}




#endif //LABO4_VECTEUR_CPP_H
