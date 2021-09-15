#include <iostream>

#include "nodo.h"
#include "data.h"
#include "graph.h"

using namespace std;


int main()
{
    Nodo* n1 = new Nodo(new Dato(1));
    Nodo* n2 = new Nodo(new Dato(2));
    Nodo* n3 = new Nodo(new Dato(3));
    Nodo* n4 = new Nodo(new Dato(4));
    Nodo* n5 = new Nodo(new Dato(5));
    Nodo* n6 = new Nodo(new Dato(6));
    Nodo* n7 = new Nodo(new Dato(7));
    
    Graph grafo{n1};
    
    grafo.link(n1,n2);
    grafo.link(n1,n3);
    grafo.link(n3,n4, true);
    grafo.link(n3,n7);
    grafo.link(n4,n5);
    grafo.link(n4,n1);
    grafo.link(n5,n6, true);
    grafo.link(n6,n7);
    grafo.link(n7,n2);
    
    grafo.printAll();
    
    cout << endl;
    
    cout << " ------------------------- " << endl;
    
    cout << "Camino del 1 al 5: ";
    grafo.printPath(n5);
    
    cout << "Camino del 1 al 7: ";
    grafo.printPath(n7);
    
    cout << "Camino del 1 al 2: ";
    grafo.printPath(n2);
    
    cout << "Cambiamos el punto de entrada al nodo 7" << endl;
    grafo.setEntry(n7);
    
    cout << "Camino del 7 al 3: ";
    grafo.printPath(n3);
    cout << "Camino del 7 al 6: ";
    grafo.printPath(n6);
    cout << "Camino del 7 al 2: ";
    grafo.printPath(n2);
    
    
    return 0;
}
