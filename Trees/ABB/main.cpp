#include <iostream>
#include <arbolabb.h>

using namespace std;

int main()
{
    cout << "Ejemplo arbol ABB..." << endl;
    ArbolABB MiArbol;
    
    MiArbol.Insertar(25);
    MiArbol.Insertar(17);
    MiArbol.Insertar(32);
    MiArbol.Insertar(13);
    MiArbol.Insertar(21);
    MiArbol.Insertar(18);
    MiArbol.Insertar(23);
    MiArbol.Insertar(19);
    
    cout << "Recorremos en anchura el arbol ABB" << endl;
    MiArbol.RecorrerAnchura(MiArbol.getRaiz());
    
    cout << endl;
    
    cout << "Recorremos arbol ABB en PreOrder" << endl;
    MiArbol.PreOrder(MiArbol.getRaiz());
    
    cout << endl;
    
    cout << "Recorremos arbol ABB en PostOrder" << endl;
    MiArbol.PostOrder(MiArbol.getRaiz());
    
    cout << endl;
    
    cout << "Recorremos arbol ABB en InOrder" << endl;
    MiArbol.InOrder(MiArbol.getRaiz());
    
    cout << endl;
    
    cout << "Buscamos valor 17" << endl;
    cout << MiArbol.Buscar(17) << endl;
    
    cout << endl;
    
    cout << "Eliminamos valor 17"<< endl;
    cout << MiArbol.Borrar(17) << endl;
    
    cout << endl;
    
    cout << "Buscamos valor 17" << endl;
    cout << MiArbol.Buscar(17) << endl;
    
    cout << endl;
    
    cout << "Recorremos en anchura el arbol ABB" << endl;
    MiArbol.RecorrerAnchura(MiArbol.getRaiz());
    
    cout << endl;
    
    cout << "Terminando..." << endl;
    
    return 0;
}
