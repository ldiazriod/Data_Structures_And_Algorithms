#include <iostream>
#include <vector>
#include "listadoble.h"

using namespace std;

int main(){

    cout << "Empezamos..." << endl;
    ListaDoble MiLista;

    nodo N0 = {"Nodo 0", 0, nullptr, nullptr};
    nodo N1 = {"Primer nodo", 1, nullptr, nullptr};
    nodo N2 = {"Segundo nodo", 2, nullptr, nullptr};
    nodo N3 = {"Tercer nodo", 3, nullptr, nullptr};
    nodo N4 = {"Cuarto nodo", 4, nullptr, nullptr};
    nodo N5 = {"Quinto nodo", 5, nullptr, nullptr};
    nodo N6 = {"Sexto nodo", 6, nullptr, nullptr};

    nodo N77 = {"Nodo77", 7, nullptr, nullptr};
    nodo N88 = {"Nodo88", 8, nullptr, nullptr};
    nodo N99 = {"Nodo99", 9, nullptr, nullptr};

    nodo N100 = {"Nodo100", 100, nullptr, nullptr};

    cout << "Montamos Lista" << endl;
    MiLista.InsertarNodoEnListaVacia(&N1);
    MiLista.InsertarNodoFinLista(&N2);
    MiLista.InsertarNodoFinLista(&N3);
    MiLista.InsertarNodoFinLista(&N4);
    MiLista.InsertarNodoFinLista(&N5);
    MiLista.InsertarNodoFinLista(&N6);
    MiLista.InsertarNodoFinLista(&N77);
    MiLista.InsertarNodoFinLista(&N88);
    MiLista.InsertarNodoFinLista(&N99);
    MiLista.InsertarNodoInicioLista(&N0);

    MiLista.ImprimirLista(1);

    cout << "Posicion de nodo 0: " << MiLista.Buscar(0) << endl;

    nodo* ptr = MiLista.getNodoInicio();

    cout << "Buscar el nodo con valor 6 de manera recursiva. Su direccion es:";
    cout << MiLista.BusquedaRecursiva(6, ptr) << endl;

    cout << "Lista recorrida de manera recursiva: ";
    MiLista.RecorrerRecursvio(1, ptr);

    cout << "La suma de los valores contenidos en la lista es de: ";
    cout << MiLista.SumaListaRecursiva(ptr) << endl;

    cout << "Eliminamos por valor el nodo con valor 78. Resultado?: " << MiLista.SuprimirNodo(8) << endl;
    cout << "Eliminamos por valor el nodo con valor 78. Resultado?: " << MiLista.SuprimirNodo(8) << endl;
    cout << "Eliminamos de manera recursiva el nodo con valor 7. Resultado?: " << MiLista.EliminaRecusivo(7, ptr) << endl;
    cout << "Eliminamos de manera recursiva eñ nodo con valor 7. Resultado?: " << MiLista.EliminaRecusivo(7, ptr) << endl;

    MiLista.ImprimirLista(1);
    MiLista.RecorrerRecursvio(1, ptr);

    cout << "Destruimos la lista entera...";
    MiLista.DestruirRecursivo(ptr);

    cout << "Hemos terminado..." << endl;
    return 0;
}
