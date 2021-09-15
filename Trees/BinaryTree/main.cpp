#include <iostream>
#include <arbolabb.h>

using namespace std;

int main()
{
    cout << "Ejemplo de un arbol binario..." << endl;
    
    //Usamos métodos static
    NodoArbolBin* n1 = ArbolBin::crearHoja(10);
    NodoArbolBin* n2 = ArbolBin::crearHoja(20);
    NodoArbolBin* n3 = ArbolBin::crearNodo(30, n1, n2);
    
    NodoArbolBin* m1 = ArbolBin::crearHoja(40);
    NodoArbolBin* m2 = ArbolBin::crearHoja(50);
    NodoArbolBin* m3 = ArbolBin::crearNodo(60, m1, m2);
    
    NodoArbolBin* z1 = ArbolBin::crearHoja(70);
    NodoArbolBin* z2 = ArbolBin::crearHoja(80);
    NodoArbolBin* z3 = ArbolBin::crearNodo(90, z1, z2);
    
    NodoArbolBin* x1 = ArbolBin::crearHoja(100);
    NodoArbolBin* x2 = ArbolBin::crearHoja(110);
    NodoArbolBin* x3 = ArbolBin::crearNodo(120, x1, x2);
    
    ArbolBin arbol = ArbolBin(200, n3, m3);
    
    //Recorremos el arbol de varias formas
    vector<int> rp = {arbol.preorder()};
    vector<int> ri = {arbol.inorder()};
    vector<int> rpo = {arbol.postorder()};
    
    //Mostramos los recorridos
    arbol.imprimir(rp, "Recorrido preorder");
    arbol.imprimir(ri, "Recorrido inorder");
    arbol.imprimir(rpo, "Recorrido postorder");
    
    //Comprobamos si existe el nodo 22
    if(arbol.existe(22)){
        cout << "Existe" << endl;
    }else{
        cout << "No existe" << endl;
    }
    
    //Recorremos el arbol con recorrer y mostramos con for moderno
    vector<NodoArbolBin*> r1;
    r1 = arbol.recorrer();
    for(auto i : r1){
        cout << i->getDato() << " ";
    }
    cout << endl;
    
    //Añadimos nodos a una posicion dada
    NodoArbolBin* punt = arbol.buscar(20);
    punt->setIzquierda(x3);
    punt->setDerecha(z3);
    
    //Recorremos el nuevo arbol con recorrer y mostramos con for moderno
    vector<NodoArbolBin*> r2;
    r2 = arbol.recorrer();
    for(auto elem : r2){
        cout << elem->getDato() << " ";
    }
    cout << endl;
    
    return 0;
}
