#ifndef ARBOLABB_H
#define ARBOLABB_H

#include<NodoArbol.h>
#include <vector>
#include<string>
#include<iostream>
#include <queue>

using namespace std;

class ArbolBin
{
public:
    ArbolBin();
    ArbolBin(int valor, NodoArbolBin *izq, NodoArbolBin *der);
    ~ArbolBin();

    NodoArbolBin* insertarHoja(int valor, NodoArbolBin *n);
    NodoArbolBin* insertarNodo(NodoArbolBin *nuevoNodo, NodoArbolBin *n);

    static NodoArbolBin* crearHoja(int valor);
    static NodoArbolBin* crearNodo(int valor, NodoArbolBin* izq, NodoArbolBin* der);

    NodoArbolBin *getRaiz() const;

    bool existe(int valor);
    NodoArbolBin* buscar(int valor);

    void imprimir(vector<int> t, string cab);

    vector<int> preorder();
    vector<int> inorder();
    vector<int> postorder();

    vector<NodoArbolBin*> recorrer();

private:
    NodoArbolBin* raiz;
    bool existe(NodoArbolBin* n, int valor);
    void preorder(NodoArbolBin* n, vector<int>* res);
    void inorder(NodoArbolBin* n, vector<int>* res);
    void postorder(NodoArbolBin* n, vector<int>* res);

    void recorrer(NodoArbolBin* n, vector<NodoArbolBin*>* res);
    void recorrerBorrando(NodoArbolBin* n, vector<NodoArbolBin*>* res);


};

#endif // ARBOLABB_H
