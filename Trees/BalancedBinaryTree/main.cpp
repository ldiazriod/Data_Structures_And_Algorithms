#include <iostream>
#include "arbolavl.h"
#include "NodoArbol.h"

using namespace std;

int main()
{
    cout << "Prueba arbol AVL..." << endl;

    ArbolAVL MiArbol;

    MiArbol.Insertar(25);
    MiArbol.Insertar(17);
    MiArbol.Insertar(32);
    MiArbol.Insertar(13);
    MiArbol.Insertar(21);
    MiArbol.Insertar(18);
    MiArbol.Insertar(23);
    MiArbol.Insertar(19);

    cout << "Hemos insertado 25-17-32-13-21-18-23-19..." << endl;
    cout << endl;
    cout << "Recorremos InOrder..." << endl;
    MiArbol.InOrder(MiArbol.getRaiz());
    cout << endl;
    cout << "Recorremos en anchura..." << endl;
    MiArbol.RecorrerAnchura(MiArbol.getRaiz());
    cout << endl;
    cout << "El valor 17 esta en el arbol?: ";
    cout << MiArbol.Buscar(17) << endl;
    cout << "Borramos el valor 17..." << MiArbol.Borrar(17) << endl;
    cout << "El valor 17 esta en el arbol?: ";
    cout << MiArbol.Buscar(17) << endl;
    cout << "Recorremos en anchura..." << endl;
    MiArbol.RecorrerAnchura(MiArbol.getRaiz());
    cout << endl;

    cout << "Insertamos 14..." << endl;
    MiArbol.Insertar(14);
    MiArbol.RecorrerAnchura(MiArbol.getRaiz());
    cout << endl;
    cout << "Insertamos 15..." << endl;
    MiArbol.Insertar(15);
    MiArbol.RecorrerAnchura(MiArbol.getRaiz());
    cout << endl;
    cout << "Borramos 19..." << endl;
    MiArbol.Borrar(19);
    MiArbol.RecorrerAnchura(MiArbol.getRaiz());
    cout << endl;
    cout << "Insertamos 19..." << endl;
    MiArbol.Insertar(19);
    MiArbol.RecorrerAnchura(MiArbol.getRaiz());
    cout << endl;
    cout << "Insertamos 17..." << endl;
    MiArbol.Insertar(17);
    MiArbol.RecorrerAnchura(MiArbol.getRaiz());
    cout << endl;
    cout << "Insertamos 16..." << endl;
    MiArbol.Insertar(16);
    MiArbol.RecorrerAnchura(MiArbol.getRaiz());
    cout << endl;

    cout << "Recorremos In Order..." << endl;
    MiArbol.InOrder(MiArbol.getRaiz());
    cout << endl;

    cout << "Terminando..." << endl;
    return 0;
}
