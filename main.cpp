#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include "Exceptions.h"
#include "Vecteur.h"
#include "Matrice.h"

using namespace std;

int main()
{
    //Test 1 : vecteurs d'entiers, utilisation normale
    cout << "TEST1 : Vecteur<int> (utilisation normale)" << endl << endl;
    Vecteur<int> v1(0);
    cout << "vecteur vide v1 : " << v1 << endl;
    v1.resize(5);
    v1.at(v1.size()-1) = 42;
    cout << "redimensionnement à la taille 5, puis affectation d'un élément : " << v1 << endl;
    Vecteur<int> v2(v1*2);
    cout << "copie du vecteur multiplié par 2  v2 : " << v2 << endl;
    Vecteur<int> v3(5);
    v3.at(3) = 41;
    v3.at(2) = 40;
    cout << "v3 : " << v3 << endl;
    cout << "somme avec v3 : " << v2 + v3 << endl;
    cout << "soustraction de v3 : " << v2 - v3 << endl;
    cout << "multiplication de v2 et v3" << v3 * v2 << endl << endl;
    
    //Test 2 : vecteurs d'entiers, erreurs
    cout << "TEST2 : Vecteur<int> (erreurs)" << endl << endl;
    cout << "Tentative de construction d'un vecteur trop grand : " << endl;
    Vecteur<int> v4(numeric_limits<size_t>::max());
    
    cout << "Tentative de redimensionnement avec une taille trop grande : " << endl;
    Vecteur<int> v5(0);
    v5.resize(numeric_limits<size_t>::max());
    
    cout << "Tentative d'accès à un élément inexistant : " << endl;
    Vecteur<int> v6(0);
    int testVal = v6.at(1);
    
    cout << "Tentative d'addition de vecteurs de tailles différentes : " << endl;
    Vecteur<int> v7(0);
    Vecteur<int> v8(3);
    v7 + v8;
    
    cout << "Tentative d'addition de vecteurs contenant des opérandes trop grands (overflow) : " << endl;
    Vecteur<int> v9(1);
    Vecteur<int> v10(1);
    v9.at(0) = numeric_limits<int>::max();
    v10.at(0) = numeric_limits<int>::max();
    v9 + v10;
    
    cout << "Tentative de sommage d'un vecteur nul : " << endl;
    Vecteur<int> v11(0);
    v11.somme();
    
    //Test 3 : vecteurs de strings
    cout << "TEST3 : Vecteur<string> (erreur de longueur)" << endl << endl;
    cout << "Tentative d'addition de vecteurs contenant des opérandes trop grands (erreur de longueur) : " << endl;
    Vecteur<string> v12(1);
    Vecteur<string> v13(1);
    string s;
    v12.at(0) = string(s.max_size(), 'a');
    v13.at(0) = string(s.max_size(), 'a');
    v12 + v13;
    cout << endl << endl;
    
    //Test 4 : matrices, utilisation normale
    
    cout << "TEST4 : Matrices<int> (utilisation normale)" << endl << endl;
    Matrice<int> m1(0);
    cout << "matrice vide m1 : " << m1 << endl;
    cout << "test de estVide() : " << m1.estVide() << endl;
    Matrice<int> m2(3, 5);
    cout << "matrice de 3 lignes, 5 colonnes : " << m2 << endl;
    m1.resize(2, 2);
    cout << "redimensionnage de la matrice 1 : " << m1 << endl;
    m1.at(0).at(0) = 2;
    m1.at(1).at(1) = 2;
    cout << "affectation d'éléments : " << v1 << endl;
    cout << "matrice m1 multipliée par 2 : " << m2*2 << endl;
    cout << "test de estReguliere() sur m2: " << m2.estReguliere() << endl;
    cout << "test de estCarree() sur m1: " << m1.estCarree() << endl;
    cout << "somme de la diagonale GD : " << m1.sommeDiagonaleGD();
    cout << "somme de la diagonale DG : " << m1.sommeDiagonaleDG();
    cout << endl;
    
    //Test 5 : matrices, erreurs
    cout << "TEST5 : Matrices<int> (erreurs)" << endl << endl;
    
    cout << "Tentative de construction d'une matrice trop grande : " << endl;
    Matrice<int> m3(numeric_limits<size_t>::max());
    Matrice<int> m4(1, numeric_limits<size_t>::max());
    
    cout << "Tentative de construction d'une matrice avec des colonnes mais pas de lignes : ";
    Matrice<int> m5(0, 3);
    
    cout << "Tentative de redimensionnement à une taille trop grande : ";
    Matrice<int> m6(0, 0);
    m6.resize(numeric_limits<size_t>::max());
    m6.resize(1, numeric_limits<size_t>::max());
    
    cout << "Tentative d'accès à un élément inexistant : " << endl;
    Matrice<int> m7(0);
    m6.at(1);
    
    cout << "Tentative de sommage de lignes avec des valeurs trop grandes : ";
    Matrice<int> m8(2, 2);
    m8.at(0).at(0) = numeric_limits<int>::max();
    m8.at(0).at(1) = numeric_limits<int>::max();
    m8.sommeLigne();
    
    cout << "Tentative de sommage de lignes vides : ";
    Matrice<int> m9(2, 0);
    m8.sommeLigne();
    
    cout << "Tentative de sommage de colonnes dans une matrice irrégulière : ";
    Matrice<int> m10(2, 2);
    m10.at(1).resize(3);
    m10.sommeColonne();
    
    cout << "Tentative de sommage de la diagonale GD d'une matrice non carrée : ";
    Matrice<int> m11(2, 3);
    m11.sommeDiagonaleGD();
    m11.sommeDiagonaleDG();
    
    cout << "Tentative de multiplication d'une matrice vide : ";
    Matrice<int> m12(0);
    m12*2;
    Matrice<int> m13(1,1);
    m12*m13;
    
    cout << "Tentative de multiplication d'une matrice contenant des éléments trop grands : ";
    Matrice<int> m14(1, 1);
    m14.at(0).at(0) = numeric_limits<int>::max();
    m14*2;
    Matrice<int> m15(1, 1);
    m15.at(0).at(0) = 2;
    m14*m15;
    
    cout << "Tentative d'addition de matrices incompatibles : ";
    Matrice<int> m16(2, 2);
    Matrice<int> m17(1, 1);
    m16+m17;
}
