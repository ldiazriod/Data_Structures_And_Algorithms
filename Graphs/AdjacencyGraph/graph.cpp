#include "graph.h"

Graph::Graph(Nodo *entryPoint):entryPoint{entryPoint}
{
    
}

void Graph::printAll()
{
    if(entryPoint == nullptr){
        throw string {"No hay entrada"};
    }else{
        entryPoint->resetVisited();
        entryPoint->printAll();
    }
}

void Graph::link(Nodo *n1, Nodo *n2, bool twoWay)
{
    if(!n1 || !n2){
        throw string{"Uno de los nodos no es valido"};
    }else{
        n1->nuevoVecino(n2);
        if(twoWay){ //Si es bidirrecional añadimos al segundo como vecino del primero
            n2->nuevoVecino(n1);
        }
    }
}

void Graph::printPath(Nodo *dest)
{
    if(computePath(dest)){
        entryPoint->printPath();
        cout << endl;
    }else{
        cout << "No hay camino" << endl;
    }
}

bool Graph::computePath(Nodo *dest)
{
    if(entryPoint == nullptr){
        throw string{"No hay entrada al grafo"};
    }else{
        entryPoint->resetVisited(); //Bajamos el flag
        if(entryPoint->computePath(dest)){ //Buscamos camino desde el nodo
            return true;
        }else{
            return false;
        }
    }
}
