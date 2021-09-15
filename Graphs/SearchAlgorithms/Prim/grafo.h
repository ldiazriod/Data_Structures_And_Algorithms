#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Arista
{
    int info; //int o lo que sea, struct, objeto, etc...
    bool existe;
};
struct Nodo
{
    int info; //int o lo que sea, struct, objeto, etc…
    bool existe;
    bool visitado;
    int distancia;

    std::vector<Nodo*> Vecinos;
};

class Grafo
{
public:
    Grafo();
    Grafo(int nodos);

    bool insertarNodo(Nodo n);
    bool crearArista(Nodo orig,Nodo dest,Arista a);

    void imprimirMatriz();
    void imprimirNodos();

    //Implementación 1 (C++ Moderno)
    vector<vector<int>> prim();

    //Implementación 2 (C++ antiguo)
    void primMST();
    int PesoMinimo(int PesoMin[], bool SinIncluir[]);
private:
    int nNodos; //Cantidad de nodos

    vector<Nodo> ListaNodos;
    vector<vector<Arista>> MatrizAdyacencia;
};


#endif // GRAFO_H
