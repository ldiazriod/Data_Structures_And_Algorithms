#ifndef ARBOLABB_H
#define ARBOLABB_H

#include<NodoArbol.h>
#include<iostream>

using namespace std;

class ArbolABB
{
public:
    ArbolABB(); //Contructor
    ~ArbolABB(); //Destructor
    
    bool Insertar(int v); //Insertar Nodo
    int Borrar(int v); //Borrar Nodo
    NodoArbol* Buscar(int v); //Buscar Nodo
    
    void InOrder(NodoArbol*);
    void PreOrder(NodoArbol*);
    void PostOrder(NodoArbol*);
    
    void RecorrerAnchura(NodoArbol*);
    
    NodoArbol* getRaiz();
    
private:
    
    NodoArbol *raiz = new NodoArbol;
    
    void Eliminar(NodoArbol*); //Borrar todos los nodos a partit de uno, incluyendo el mismo
  
};

#endif // ARBOLABB_H
