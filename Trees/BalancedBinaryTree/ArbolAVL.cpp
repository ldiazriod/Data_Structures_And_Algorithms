#include "arbolavl.h"
#include<queue>
#include<iostream>

using namespace std;

ArbolAVL::ArbolAVL()
{
    raiz = nullptr;
    act = nullptr;
}

ArbolAVL::~ArbolAVL()
{
    Eliminar(raiz);
}

NodoArbol *ArbolAVL::getRaiz()
{
    return raiz;
}

NodoArbol *ArbolAVL::getAct()
{
    return act;
}

void ArbolAVL::MovemosAraiz()
{
    act = raiz;
}

int ArbolAVL::NumNodos()
{
    counter = 0;
    CuentaNodos(raiz);
    return counter;
}

bool ArbolAVL::EstaVacio(NodoArbol *r)
{
    if(r == nullptr){
        return true;
    }
    return false;
}

bool ArbolAVL::EsHoja(NodoArbol *n)
{
    if(n->der == nullptr && n->izq == nullptr){
        return true;
    }
    return false;
}

bool ArbolAVL::Insertar(int v)
{
    NodoArbol *padre = nullptr;

    act = raiz;

    while(!EstaVacio(act) && v != act->dato){
        padre = act;
        if(v > act->dato){
            act = act->der;
        }else if(v < act->dato){
            act = act->izq;
        }
    }
    if(EstaVacio(padre)){
        raiz = new NodoArbol;
        raiz->dato = v;
        raiz->padre = nullptr;
        raiz->der = nullptr;
        raiz->izq = nullptr;
        raiz->FE = 0;
    }else if(v < padre->dato){
        padre->izq = new NodoArbol;
        padre->izq->dato = v;
        padre->izq->padre = padre;
        padre->izq->der = nullptr;
        padre->izq->izq = nullptr;
        padre->izq->FE = 0;

        Equilibrar(padre, 2, true);
    }else if(v > padre->dato){
        padre->der = new NodoArbol;

        padre->der->dato = v;
        padre->der->padre = padre;
        padre->der->der = nullptr;
        padre->der->izq = nullptr;
        padre->der->FE = 0;

        Equilibrar(padre, 1, true);
    }else if(!EstaVacio(act)){
        return false;
    }
    return true;
}

int ArbolAVL::Borrar(int v)
{
    NodoArbol *padre = nullptr;
    NodoArbol *nodo = nullptr;
    int aux{0}, val_ret{0};

    act = raiz;
    while(!EstaVacio(act)){
        if(v == act->dato){
            if(EsHoja(act)){
                if(padre != nullptr){
                    if(padre->der == act){
                        padre->der = nullptr;
                    }else if(padre->izq == act){
                        padre->izq = nullptr;
                    }
                }
                val_ret = act->dato;
                delete act;
                act = nullptr;
                if((padre->der == nullptr && padre->FE == 1) || (padre->izq == act && padre->FE == -1)){
                    padre->FE = 0;
                    act = padre;
                    padre = act->padre;
                }
                if(padre != nullptr){
                    if(padre->der == act){
                        Equilibrar(padre, 1, false);
                    }else{
                        Equilibrar(padre, 2, false);
                    }
                    return val_ret;
                }
            }else{
                padre = act;
                if(act->der != nullptr){
                    nodo = act->der;
                    while(nodo->izq != nullptr){
                        padre = nodo;
                        nodo = nodo->izq;
                    }
                }else{
                    nodo = act->izq;
                    while(nodo->der != nullptr){
                        padre = nodo;
                        nodo = nodo->der;
                    }
                }
                aux = act->dato;
                act->dato = nodo->dato;
                nodo->dato = aux;
                act = nodo;
            }
        }else{
            padre = act;
            if(v > act->dato){
                act = act->der;
            }else if(v < act->dato){
                act = act->izq;
            }
        }
    }
    return 0;
}

bool ArbolAVL::Buscar(int v)
{
    act = raiz;

    while(!EstaVacio(act)){
        if(v == act->dato){
            return true;
        }else if(v > act->dato){
            act = act->der;
        }else if(v < act->dato){
            act = act->izq;
        }
    }
    return false;
}

int ArbolAVL::AturaArbol()
{
    altura = 0;
    Altura(raiz, 0);
    return altura;
}

int ArbolAVL::AlturaNodo(int v)
{
    int altura{0};
    act = raiz;

    while(!EstaVacio(act)){
        if(v == act->dato){
            return altura;
        }else{
            altura++;
            if(v > act->dato){
                act = act->der;
            }else if(v < act->dato){
                act = act->izq;
            }
        }
    }
    return -1;
}

void ArbolAVL::InOrder(NodoArbol *n)
{
    if(n != nullptr){
        InOrder(n->izq);
        cout << n->dato << " ";
        InOrder(n->der);
    }
}

void ArbolAVL::PreOrder(NodoArbol *n)
{
    if(n != nullptr){
        cout << n->dato << " ";
        PreOrder(n->izq);
        PreOrder(n->der);
    }
}

void ArbolAVL::PostOrder(NodoArbol *n)
{
    if(n != nullptr){
        PostOrder(n->izq);
        PostOrder(n->der);
        cout << n->dato << " ";
    }
}

void ArbolAVL::RecorrerAnchura(NodoArbol *n)
{
    if(n != nullptr){
        NodoArbol *aux = n;
        queue<NodoArbol*> cola_aux;

        cola_aux.push(n);
        while(cola_aux.size() != 0){
            aux = cola_aux.front();
            cola_aux.pop();
            cout << aux->dato << " ";
            if(aux->izq != nullptr){
                cola_aux.push(aux->izq);
            }
            if(aux->der != nullptr){
                cola_aux.push(aux->der);
            }
        }
    }
}

void ArbolAVL::Equilibrar(NodoArbol *n, int rama, bool nuevo)
{
    bool salir = false;

    while(n != nullptr && !salir){
        if(nuevo){
            if(rama == 2){
                n->FE--;
            }else{
                n->FE++;
            }
        }else{
            if(rama == 2){
                n->FE++;
            }else{
                n->FE--;
            }
        }
        if(n->FE == 0 && nuevo == 1){
            salir = true;
        }else if(n->FE == -2){
            if(n->izq->FE == 1){
                RDD(n); //doble derecha
            }else{
                RSD(n); //simple derecha
            }
            salir = true;
        }else if(n->FE == 2){
            if(n->der->FE == -1){
                RDI(n); //Doble izquierda
            }else{
                RSI(n); //Simple izquierda
            }
            salir = true;
        }
        if(n->padre != nullptr){
            rama = 1;
        }else{
            rama = 2;
        }
        n = n->padre;
    }
}

void ArbolAVL::RSI(NodoArbol *n)
{
    bool aux = 0;

    NodoArbol *padre = n->padre;
    NodoArbol *P = n;
    NodoArbol *Q = P->der;
    NodoArbol *B = Q->izq;

    if(Q->der != nullptr && Q->izq != nullptr){
        if(AlturaNodo(Q->der->dato) == AlturaNodo(Q->izq->dato)){
            aux = true;
        }else{
            aux = false;
        }
    }else{
        if(Q->izq == nullptr){
            if(Q->der == nullptr){

            }else{
                aux = false;
            }
        }else{
            if(Q->izq == nullptr){

            }else{
                aux = false;
            }
        }
    }
    if(padre != nullptr){
        if(padre->der == P){
            padre->der = Q;
        }else{
            padre->izq = Q;
        }
    }else{
        raiz = Q;
    }

    P->der = B;
    Q->izq = P;

    P->padre = Q;
    if(B != nullptr){
        B->padre = P;
    }
    Q->padre = padre;

    if(aux){
        P->FE = 1;
        Q->FE = -1;
    }else{
        P->FE = 0;
        Q->FE = 0;
    }
}

void ArbolAVL::RSD(NodoArbol *n)
{
    NodoArbol *padre = n->padre;
    NodoArbol *P = n;
    NodoArbol *Q = P->izq;
    NodoArbol *B = Q->der;

    bool aux = false;

    if(Q->der != nullptr && Q->izq != nullptr){
        if(AlturaNodo(Q->der->dato) == AlturaNodo(Q->izq->dato)){
            aux = true;
        }else{
            aux = false;
        }
    }else{
        if(Q->izq == nullptr){
            if(Q->der == nullptr){

            }else{
                aux = false;
            }
        }else{
            if(Q->izq == nullptr){

            }else{
                aux = false;
            }
        }
    }
    if(AlturaNodo(Q->der->dato) == AlturaNodo(Q->izq->dato)){
        aux = true;
    }else{
        aux = false;
    }

    if(padre != nullptr){
        if(padre->der == P){
            padre->der = Q;
        }else{
            padre->izq = Q;
        }
    }else{
        raiz = Q;
    }

    P->izq = B;
    Q->der = P;

    P->padre = Q;
    if(B != nullptr){
        B->padre = P;
    }
    Q->padre = padre;

    if(aux){
        P->FE = -1;
        Q->FE = 1;
    }else{
        P->FE = 0;
        Q->FE = 0;
    }
}

void ArbolAVL::RDI(NodoArbol *n)
{
    NodoArbol *padre = n->padre;
    NodoArbol *P = n;
    NodoArbol *Q = P->der;
    NodoArbol *R = Q->izq;
    NodoArbol *B = R->izq;
    NodoArbol *C = R->der;

    if(padre != nullptr){
        if(padre->der == n){
            padre->der = R;
        }else{
            padre->izq = R;
        }
    }else{
        raiz = R;
    }

    P->der = B;
    Q->izq = C;
    R->izq = P;
    R->der = Q;

    R->padre = padre;
    P->padre = Q->padre = R;
    if(B){
        B->padre = P;
    }
    if(C){
        C->padre = Q;
    }

    switch(R->FE){
    case -1:
        P->FE = 0;
        Q->FE = 1;
        break;
    case  0:
        P->FE = 0;
        Q->FE = 0;
        break;
    case 1:
        P->FE = -1;
        Q->FE = 0;
        break;
    }
    R->FE = 0;
}

void ArbolAVL::RDD(NodoArbol *n)
{
    NodoArbol *padre = n->padre;
    NodoArbol *P = n;
    NodoArbol *Q = P->der;
    NodoArbol *R = Q->izq;
    NodoArbol *B = R->izq;
    NodoArbol *C = R->der;

    if(padre != nullptr){
        if(padre->der == n){
            padre->der = R;
        }else{
            padre->izq = R;
        }
    }else{
        raiz = R;
    }

    Q->der = B;
    P->izq = C;
    R->izq = Q;
    R->der = P;

    R->padre = padre;
    P->padre = Q->padre = R;
    if(B){
        B->padre = Q;
    }
    if(C){
        C->padre = P;
    }

    switch(R->FE){
    case -1:
        Q->FE = 0;
        P->FE = -1;
        break;
    case 0:
        Q->FE = 0;
        P->FE = 1;
        break;
    case 1:
        Q->FE = -1;
        P->FE = 0;
        break;
    }
    R->FE = 0;
}

void ArbolAVL::Eliminar(NodoArbol *nodo)
{
    if(nodo != nullptr){
        Eliminar(nodo->izq);
        Eliminar(nodo->der);
        delete nodo;
        nodo = nullptr;
    }
}

void ArbolAVL::CuentaNodos(NodoArbol *n)
{
    counter++;
    if(n->izq != nullptr){
        CuentaNodos(n->izq);
    }
    if(n->der != nullptr){
        CuentaNodos(n->der);
    }
}

void ArbolAVL::Altura(NodoArbol *n, int a)
{
    if(n->izq){
        Altura(n->izq, a+1);
    }
    if(n->der){
        Altura(n->der, a+1);
    }
    if(EsHoja(n) && a > altura){
        altura = a;
    }
}
