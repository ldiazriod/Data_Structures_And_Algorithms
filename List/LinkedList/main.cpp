#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo* siguiente;
};

class Lista{
public:
    Lista();
    ~Lista();
    bool listaVacia(void);
    bool insertarInicioLista(Nodo* p);
    void insertarFinalLista(Nodo* p);
    void insertarInicioListaValor(int valor);
    void insertarFinalListaValor(int valor);
    bool insertarListaVacia(Nodo* p);
    
    bool existe(int dato);
    int numElementos(void);
    
    int eliminarInicio(void);
    int eliminarFinal(void);
    int eliminar(int valor);
    
    void imprimir(void);
private:
    Nodo *primero, *ultimo;
    Nodo* buscar(int v);
    void eliminar(Nodo* p);
};

int main()
{
    cout << "Hello World!" << endl;
    
    Nodo n1 = {1, nullptr};
    Nodo n2 = {2, nullptr};
    Nodo n3 = {3, nullptr};
    Nodo n4 = {4, nullptr};
    
    Lista MiLista;
    
    MiLista.insertarInicioLista(&n1);
    MiLista.insertarInicioLista(&n3);
    MiLista.insertarInicioLista(&n2);
    MiLista.insertarFinalLista(&n4);
    
    MiLista.imprimir();
    
    MiLista.eliminar(3);
    
    MiLista.imprimir();
    
    int numDElementos = MiLista.numElementos();
    
    cout << numDElementos << endl;
    
    MiLista.insertarInicioLista(&n3);
    MiLista.imprimir();
    
    MiLista.eliminarInicio();
    MiLista.imprimir();
    
    MiLista.eliminarFinal();
    MiLista.imprimir();
    
    if(MiLista.existe(2)){
        cout << "Existe" << endl;
    }else{
        cout << "No existe" << endl;
    }
    
    if(MiLista.existe(5)){
        cout << "Existe" << endl;
    }else{
        cout << "No existe" << endl;
    }
    
    return 0;
}

Lista::Lista()
{
    primero = nullptr;
    ultimo = nullptr;
}

Lista::~Lista()
{
    while(primero != nullptr){
        eliminarFinal();
    }
}

bool Lista::listaVacia()
{
    return (primero == nullptr);
}

bool Lista::insertarInicioLista(Nodo *p)
{
    if(listaVacia()){
        insertarListaVacia(p);
    }else{
        Nodo *NuevoNodo = new Nodo;
        *NuevoNodo = *p;
        NuevoNodo->siguiente = primero;
        primero = NuevoNodo;
    }
    return 0;
}

void Lista::insertarFinalLista(Nodo *p)
{
    if(listaVacia()){
        insertarListaVacia(p);
    }else{
        Nodo *NuevoNodo = new Nodo;
        *NuevoNodo = *p;
        NuevoNodo->siguiente = nullptr;
        ultimo->siguiente = NuevoNodo;
        ultimo = NuevoNodo;
    }
}

void Lista::insertarInicioListaValor(int valor)
{
    Nodo *NuevoNodo = new Nodo;
    NuevoNodo->dato = valor;
    
    if(listaVacia()){
        insertarListaVacia(NuevoNodo);
    }else{
        insertarInicioLista(NuevoNodo);
    }
}

void Lista::insertarFinalListaValor(int valor)
{
    Nodo *NuevoNodo = new Nodo;
    NuevoNodo->dato = valor;
    if(listaVacia()){
        insertarListaVacia(NuevoNodo);
    }else{
        insertarFinalLista(NuevoNodo);
    }
}

bool Lista::insertarListaVacia(Nodo *p)
{
    if(listaVacia()){
        Nodo *NuevoNodo = new Nodo;
        *NuevoNodo = *p;
        primero = NuevoNodo;
        ultimo = NuevoNodo;
        NuevoNodo->siguiente = nullptr;
        return true;
    }else{
        return false;
    }
}

bool Lista::existe(int dato)
{
    Nodo *aux = primero;
    if(listaVacia()){
        return false;
    }else{
        while(aux != nullptr){
            if(aux->dato == dato){
                return true;
            }else{
                aux = aux->siguiente;
            }
        }
    }
    return false;
}

int Lista::numElementos()
{
    Nodo *aux = primero;
    int counter{0};
    if(listaVacia()){
        return 0;
    }else{
        while(aux != nullptr){
            counter++;
            aux = aux->siguiente;
        }
    }
    return counter;
}

int Lista::eliminarInicio()
{
    Nodo *aux = primero;
    if(listaVacia()){
        throw string {"La lista esta vacia"};
    }
    int valor = aux->dato;
    if(primero == ultimo){
        primero = nullptr;
        ultimo = nullptr;
    }else{
        primero = primero->siguiente;
    }
    delete aux;
    return valor;
}

int Lista::eliminarFinal()
{
    Nodo *aux = ultimo;
    if(listaVacia()){
        throw string {"Lista vacia"};
    }
    
    int v = aux->dato;
    if(primero == ultimo){
        primero = nullptr;
        ultimo = nullptr;
    }else{
        Nodo *aux2 = primero;
        while(aux2->siguiente != ultimo){
            aux2 = aux2->siguiente;
        }
        aux2->siguiente = nullptr;
        ultimo = aux2;
    }
    delete aux;
    return v;
}

int Lista::eliminar(int valor)
{
    if(listaVacia()){
        throw string {"Lista vacia"};
    }
    Nodo *aux = primero;
    while((aux != nullptr) && (aux->dato != valor)){
        aux = aux->siguiente;
    }
    int v = aux->dato;
    eliminar(aux);
    return v;
}

void Lista::imprimir()
{
    if(listaVacia()){
        throw string {"Lista vacia"};
    }
    Nodo *aux = primero;
    while(aux != nullptr){
        cout << aux->dato << " - ";
        aux = aux->siguiente;
    }
    cout << endl;
}

void Lista::eliminar(Nodo *p)
{
    if(listaVacia()){
        throw string {"Lista vacia"};
    }
    if(p == primero){
        eliminarInicio();
    }else if(p == ultimo){
        eliminarFinal();
    }else{
        Nodo *aux = primero;
        while((aux != nullptr) && (aux->siguiente != p)){
            aux = aux->siguiente;
        }
        aux->siguiente = p->siguiente;
        p->siguiente = nullptr;
    }
    delete p;
}
