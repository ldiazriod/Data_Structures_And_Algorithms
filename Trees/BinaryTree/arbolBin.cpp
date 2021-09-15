#include "arbolabb.h"

using namespace std;

ArbolBin::ArbolBin()
{
    raiz = new NodoArbolBin;
}

ArbolBin::ArbolBin(int valor, NodoArbolBin *izq, NodoArbolBin *der)
{
    raiz = new NodoArbolBin;
    
    raiz->setDato(valor);
    raiz->setDerecha(der);
    raiz->setIzquierda(izq);
}

ArbolBin::~ArbolBin()
{
    vector<NodoArbolBin*> eliminar;
    eliminar = recorrer();
    for(auto elem : eliminar){
        delete elem;
    }
}

NodoArbolBin *ArbolBin::insertarHoja(int valor, NodoArbolBin *n)
{
    if(n->getIzquierda() == nullptr || n->getDerecha() == nullptr){
        NodoArbolBin* hoja = new NodoArbolBin;
        hoja->setDato(valor);
        if(n->getIzquierda() == nullptr){
            n->setIzquierda(hoja);
        }else{
            n->setDerecha(hoja);
        }
        return hoja;
    }
    return nullptr;
}

NodoArbolBin *ArbolBin::insertarNodo(NodoArbolBin *nuevoNodo, NodoArbolBin *n)
{
    if(raiz == nullptr){
        NodoArbolBin* nuevo = new NodoArbolBin;
        
        nuevo->setDato(nuevoNodo->getDato());
        nuevo->setDerecha(nuevoNodo->getDerecha());
        nuevo->setIzquierda(nuevoNodo->getIzquierda());
        
        raiz = nuevo;
        return nuevo;
    }else{
        if(n->getIzquierda() == nullptr){
            n->setIzquierda(nuevoNodo);
        }else if(n->getDerecha() == nullptr){
            n->setDerecha(nuevoNodo);
        }
        return nullptr;
    }
}

NodoArbolBin *ArbolBin::crearHoja(int valor)
{
    NodoArbolBin* NuevaHoja = new NodoArbolBin;
    
    NuevaHoja->setDato(valor);
    return NuevaHoja;
}

NodoArbolBin *ArbolBin::crearNodo(int valor, NodoArbolBin *izq, NodoArbolBin *der)
{
    NodoArbolBin* NuevoNodo = new NodoArbolBin;
    
    NuevoNodo->setDato(valor);
    NuevoNodo->setDerecha(der);
    NuevoNodo->setIzquierda(izq);
    
    return NuevoNodo;
}

NodoArbolBin *ArbolBin::getRaiz() const
{
    return raiz;
}

bool ArbolBin::existe(int valor)
{
    return existe(raiz, valor);
}

NodoArbolBin *ArbolBin::buscar(int valor)
{
    vector<NodoArbolBin*> vec = recorrer();
    
    for(NodoArbolBin* elem : vec){
        if(elem->getDato() == valor){
            return elem;
        }
    }
    return nullptr;
}

void ArbolBin::imprimir(vector<int> t, string cab)
{
    if(cab.size() != 0){
        cout << cab << endl;
    }
    
    for(auto elem : t){
        cout << elem << " ";
    }
    cout << endl;
}

vector<int> ArbolBin::preorder()
{
    vector<int> resultado;
    
    preorder(raiz, &resultado);
    return resultado;
    
}

vector<int> ArbolBin::inorder()
{
    vector<int> resultado;
    
    preorder(raiz, &resultado);
    return resultado;
}

vector<int> ArbolBin::postorder()
{
    vector<int> resultado;
    
    preorder(raiz, &resultado);
    return resultado;
}

vector<NodoArbolBin *> ArbolBin::recorrer()
{
    vector<NodoArbolBin *> resultado;
    recorrer(raiz, &resultado);
    return resultado;
}

bool ArbolBin::existe(NodoArbolBin *n, int valor)
{
    vector<int> res;
    
    preorder(n, &res);
    for(auto elem : res){
        if(elem == (char)valor){
            return 1;
        }
    }
    return 0;
}

void ArbolBin::preorder(NodoArbolBin *n, vector<int> *res)
{
    if(n != nullptr){
        res->push_back(n->getDato());
        preorder(n->getIzquierda(), res);
        preorder(n->getDerecha(), res);
    }
}

void ArbolBin::inorder(NodoArbolBin *n, vector<int> *res)
{
    if(n != nullptr){
        inorder(n->getIzquierda(), res);
        res->push_back(n->getDato());
        inorder(n->getDerecha(), res);
    }
}

void ArbolBin::postorder(NodoArbolBin *n, vector<int> *res)
{
    if(n != nullptr){
        postorder(n->getIzquierda(),res);
        postorder(n->getDerecha(),res);
        res->push_back(n->getDato());
    }
}

void ArbolBin::recorrer(NodoArbolBin *n, vector<NodoArbolBin *> *res)
{
    if(n != nullptr){
        recorrer(n->getIzquierda(), res);
        recorrer(n->getDerecha(), res);
        res->push_back(n);
    }
}
