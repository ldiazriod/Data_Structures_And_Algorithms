#ifndef GRAPH_H
#define GRAPH_H

#include "nodo.h"

class Graph
{
public:
    Graph(Nodo* entryPoint = nullptr);
    
    void printAll(void); //Imprime todos los nodos
    void link(Nodo* n1, Nodo* n2, bool twoWay = false); //Crear arista
    //twoWay a 0 arista dirigida
    //twoWay a 1 arista no dirigida
    void printPath(Nodo* dest); //Imprime el camino entre dos nodos
    
    void setEntry(Nodo* in){entryPoint = in;}
private:
    Nodo* entryPoint;
    bool computePath(Nodo* dest);
};

#endif // GRAPH_H
