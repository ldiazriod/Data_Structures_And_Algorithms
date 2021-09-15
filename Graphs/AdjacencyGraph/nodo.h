#ifndef NODO_H
#define NODO_H

#include "data.h"
#include <set>

using namespace std;

class Nodo
{
    friend bool operator == (Nodo const & n1, Nodo const & n2);
    //Sobrecarga de operador igual, para poder comparar Nodo.
    friend ostream & operator << (ostream & os, Nodo const & n);
    //Sobrecarga de operador <<, para podr imprimir NOdo
    
    friend class Graph;
    //friend es un modificardor que inhibe el sistema de protección.
    //Nodo puede acceder a todos los miembros de Graph.
    
public:
    Nodo(Dato *d);
    
    set<Nodo *> getVecinos() const;
    void setVecinos(const set<Nodo *> &value);
    
    Dato *getDato() const;
    void setDato(Dato *value);
    
protected:
    
    void printAll(void); //Imprimir nodo y sus vecinos
    void resetVisited(void); //Reseatamos flag visitado de nodo y sus vecinos
    void nuevoVecino(Nodo *n);
    Nodo *computePath(Nodo* dest);
    void printPath(void);
    
private:
    set<Nodo *> vecinos; //Set para evitar duplicados
    Dato *Dato;
    bool visitado; //Flag que indica si el nodo ha sido visitado o no
    Nodo *next;
};

#endif // NODO_H
