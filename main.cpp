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
    cout << "affectation d'un élément : " << v1 << endl;
    Vecteur<int> v2(v1*2);
    cout << "copie du vecteur multiplié par 2  v2 : " << v2 << endl;
    Vecteur<int> v3(5);
    v3.at(3) = 41;
    v3.at(2) = 40;
    cout << "v3 : " << v3 << endl;
    cout << "somme avec v3 : " << v2 + v3 << endl;
    cout << "soustraction de v3 : " << v2 - v3 << endl;
    cout << "multiplication de v2 et v3" << v3 * v2 << endl << endl;
    
    //Test 1 : vecteurs d'entiers, erreurs
    cout << "TEST1 : Vecteur<int> (erreurs)" << endl << endl;
    try
    {
        cout << "Tentative de construction d'un vecteur trop grand : " << endl;
        Vecteur<int> v1(numeric_limits<size_t>::max());
    }
    catch(const std::length_error& e)
    {
        cerr << "Erreur 1.1 : ";
        cerr << e.what() << endl;
    }
    
    try
    {
        cout << "Tentative de redimensionnement avec une taille trop grande : " << endl;
        Vecteur<int> v1(0);
        v1.resize(numeric_limits<size_t>::max());
    }
    catch(const std::length_error& e)
    {
        cerr << "Erreur 1.2 : ";
        cerr << e.what() << endl;
    }
    
    try
    {
        cout << "Tentative d'accès à un élément inexistant : " << endl;
        Vecteur<int> v1(0);
        int testVal = v1.at(1);
    }
    catch(const OutOfBounds& e)
    {
        cerr << "Erreur 1.3 : ";
        cerr << e.what() << endl;
    }
    
    try
    {
        cout << "Tentative d'addition de vecteurs de tailles différentes : " << endl;
        Vecteur<int> v1(0);
        Vecteur<int> v2(3);
        v1 + v2;
    }
    catch(const SizeMismatch& e)
    {
        cerr << "Erreur 1.4 : ";
        cerr << e.what() << endl;
    }
    
    try
    {
        cout << "Tentative d'addition de vecteurs contenant des opérandes trop grands (overflow) : " << endl;
        Vecteur<int> v1(1);
        Vecteur<int> v2(1);
        v1.at(0) = numeric_limits<int>::max();
        v2.at(0) = numeric_limits<int>::max();
    }
    catch(const ArithmeticOverflow& e)
    {
        cerr << "Erreur 1.5 : ";
        cerr << e.what() << endl;
    }
    
    try
    {
        cout << "Tentative de sommage d'un vecteur nul : " << endl;
        Vecteur<int> v1(0);
        v1.somme();
    }
    catch(const NullLength& e)
    {
        cerr << "Erreur 1.6 : ";
        cerr << e.what() << endl;
    }
    
    //Test 2 : vecteurs de strings
    try
    {
        cout << "Tentative d'addition de vecteurs contenant des opérandes trop grands (erreur de longueur) : " << endl;
        Vecteur<string> v1(1);
        Vecteur<string> v2(1);
        v1.at(0) = string(numeric_limits<size_t>::max(), 'a');
        v2.at(0) = string(numeric_limits<size_t>::max(), 'a');
        v1 + v2;
    }
    catch(const ArithmeticLengthError e)
    {
        cerr << "Erreur 2 : ";
        cerr << e.what() << endl;
    }
    
    //Test 3 : vecteurs d'objets autres
    //TODO : à tester ? si oui avec quelle(s) classe(s) ?
    
    //Test 4 : matrices, utilisation normale
    
    
    
    cout << endl;
}
