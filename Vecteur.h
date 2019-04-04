//
// Created by deekay on 02/04/19.
//

#ifndef LABO4_VECTEUR_H
#define LABO4_VECTEUR_H

#include <vector>

template <typename T> class Vecteur;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vecteur<T>& v)
{
    os << "[";
    os << v.at(0);
    for(size_t i=1; i<v.size(); i++)
    {
        os << ", " << v.at(1);
    }
    os << "]";
    return os;
}

template <typename T>
class Vecteur {
    
private:
    std::vector<T> data;
    friend std::ostream& operator<< <T>(std::ostream& os, const Vecteur<T>& v);//Robin
    
public:
    Vecteur(size_t size);//Doran
    Vecteur(std::vector<T> v);//Robin
    T at(size_t pos) const;//Doran
    size_t size() const;//Robin
    void resize(size_t newSize);//Doran
    T somme() const;//Robin
    Vecteur operator+(Vecteur otherVecteur);//Doran
    Vecteur operator-(Vecteur otherVecteur);
    template <typename U>
    Vecteur operator*(U value);//Robin
    Vecteur operator*(Vecteur otherVecteur);//Doran

};



#include "Vecteur.cpp.h"

#endif //LABO4_VECTEUR_H
