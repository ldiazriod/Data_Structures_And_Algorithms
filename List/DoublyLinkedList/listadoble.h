#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include<iostream>

using namespace std;

struct nodo{
    string nombre;
    int valor;
    nodo *SiguienteElemento;
    nodo *AnteriorElemento;
};

struct IdentificadorLista{
    nodo *Primero;
    nodo *Ultimo;
    int tamano;
};

class ListaDoble{
private:
    IdentificadorLista *MiLista = new IdentificadorLista;

public:
    ListaDoble();
    bool InsertarNodoEnListaVacia(nodo*);
    bool InsertarNodoInicioLista(nodo *);
    bool InsertarNodoFinLista(nodo *);
    bool SuprimirInicioLista(void);
    bool SuprimirFinLista(void);
    bool SuprimirNodoPosicion(int);
    bool ImprimirLista(bool sentido);

    nodo* getNodoInicio();
    nodo* getNodoFin();

    int Buscar(int valor);
    bool SuprimirNodo(int);

    nodo* BusquedaRecursiva(int v, nodo* inicio);
    void RecorrerRecursvio(bool sentido, nodo* inicio);
    int SumaListaRecursiva(nodo* inicio);

    bool EliminaRecusivo(int v, nodo* inicio);
    void DestruirRecursivo(nodo* inicio);

};

#endif // LISTADOBLE_H
