#ifndef NODOARBOL_H
#define NODOARBOL_H

struct NodoArbol{
    int valor;
    NodoArbol *izq;  //Nodos más pequeños que el nodo padre
    NodoArbol *der;  //Nodos más grandes que el nodo padre
};

#endif // NODOARBOL_H
