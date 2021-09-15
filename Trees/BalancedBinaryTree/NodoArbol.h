#ifndef NODOARBOL_H
#define NODOARBOL_H

#include <iostream>

struct NodoArbol{
    int dato;
    int FE; //Factor de equilibrio

    NodoArbol *izq;
    NodoArbol *der;

    NodoArbol *padre;

    friend class ArbolAVL;
};

#endif // NODOARBOL_H
