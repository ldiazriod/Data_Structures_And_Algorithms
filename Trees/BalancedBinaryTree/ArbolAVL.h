#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include "NodoArbol.h"

class ArbolAVL
{
public:
    ArbolAVL();
    ~ArbolAVL();

    NodoArbol* getRaiz();
    NodoArbol* getAct();

    void MovemosAraiz(void);

    int NumNodos(void);
    bool EstaVacio(NodoArbol *r);
    bool EsHoja(NodoArbol *n);

    bool Insertar(int v);
    int Borrar(int v);
    bool Buscar(int v);

    int AturaArbol();
    int AlturaNodo(int v);

    void InOrder(NodoArbol *n);
    void PreOrder(NodoArbol *n);
    void PostOrder(NodoArbol *n);
    void RecorrerAnchura(NodoArbol *n);

private:
    NodoArbol *raiz;
    NodoArbol *act;

    int counter;
    int altura;

    void Equilibrar(NodoArbol *n, int rama, bool nuevo);

    void RSI(NodoArbol *n);
    void RSD(NodoArbol *n);
    void RDI(NodoArbol *n);
    void RDD(NodoArbol *n);

    void Eliminar(NodoArbol* nodo);
    void CuentaNodos(NodoArbol *n);
    void Altura(NodoArbol *n, int a);

};

#endif // ARBOLAVL_H
