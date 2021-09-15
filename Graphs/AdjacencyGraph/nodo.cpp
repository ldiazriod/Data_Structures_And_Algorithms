#include "nodo.h"

Nodo::Nodo(class::Dato *d)
{
    setDato(d);
    visitado = false;
    next = nullptr;
}

set<Nodo *> Nodo::getVecinos() const
{
    return vecinos;
}

void Nodo::setVecinos(const set<Nodo *> &value)
{
    vecinos = value;
}

Dato *Nodo::getDato() const
{
    return Dato;
}

void Nodo::setDato(class::Dato *value)
{
    Dato = value;
}

void Nodo::printAll()
{
    if(visitado){
        return; //Salimos
    }else{
        visitado = true; //Marcamos como visitado
        cout << *Dato << endl; //Lo imprimimos
        for(auto elem : vecinos){
            elem->printAll();
        }
    }
}

void Nodo::resetVisited()
{
    if(!visitado){
        return;
    }else{
        visitado = false;
        for(auto elem : vecinos){
            elem->resetVisited();
        }
    }
}

void Nodo::nuevoVecino(Nodo *n)
{
    vecinos.insert(n);
}

Nodo *Nodo::computePath(Nodo *dest)
{
    if(visitado){
        return nullptr;
    }

    next = nullptr;
    visitado = true;

    if(dest == this){
        return this; //Devolvemos la direccion del nodo
    }

    for(auto elem : vecinos){
        Nodo* aux = elem->computePath(dest);
        if(aux){
            next = elem;
            return aux;
        }
    }
    return nullptr;
}

void Nodo::printPath()
{
    cout << *Dato << " - ";
    if(next){
        next->printPath();
    }
}

bool operator == (const Nodo &n1, const Nodo &n2){
    return (*(n1.Dato) == *(n2.Dato));
}

ostream &operator << (ostream &os, const Nodo &n){
    os << *(n.Dato);
    return os;
}
