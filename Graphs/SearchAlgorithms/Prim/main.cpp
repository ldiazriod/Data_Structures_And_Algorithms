#include <iostream>
#include "grafo.h"

using namespace std;

int main()
{   
    Grafo MiGrafo;

    MiGrafo.insertarNodo({1, false, false, 0});
    MiGrafo.insertarNodo({2, false, false, 0});
    MiGrafo.insertarNodo({3, false, false, 0});
    MiGrafo.insertarNodo({4, false, false, 0});

    MiGrafo.crearArista({1},{2},{2});
    MiGrafo.crearArista({2},{1},{2});
    MiGrafo.crearArista({1},{3},{3});
    MiGrafo.crearArista({3},{1},{3});
    MiGrafo.crearArista({1},{4},{4});
    MiGrafo.crearArista({4},{1},{4});
    MiGrafo.crearArista({3},{4},{5});
    MiGrafo.crearArista({4},{3},{5});

    MiGrafo.imprimirNodos();
    MiGrafo.imprimirMatriz();

    vector< vector<int> > arbol = MiGrafo.prim();
        for(auto i:arbol)
        {
            for(auto j:i)
            {
                if(j!=std::numeric_limits<int>::max())
                {
                    std::cout<<j<<" \t";
                }
                else
                {
                    std::cout<<"-"<<" \t";
                }
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;

        MiGrafo.primMST();

    return 0;
}
