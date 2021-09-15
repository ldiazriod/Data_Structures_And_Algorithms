#include "arbolabb.h"
#include <queue>

ArbolABB::ArbolABB()
{
    raiz->der = nullptr;
    raiz->izq = nullptr;
    raiz->valor = 0;
}

ArbolABB::~ArbolABB()
{
    Eliminar(raiz);
}

bool ArbolABB::Insertar(int v)
{
    NodoArbol *ultimo = nullptr;
    NodoArbol *actual = raiz;
    
    int resultadoComparacion{0};
    int ComparacionAnterior{0};
    
    while(actual != nullptr) {
        ComparacionAnterior = resultadoComparacion;
        if(v == actual->valor){
            //Si son iguales guardará 1, si son distintos 0
            resultadoComparacion = 0;
        }else if(v < actual->valor){
            resultadoComparacion = -1;
        }else{
            resultadoComparacion = 1;
        }
        
        if(resultadoComparacion == 0){
            //Hemos encontrado el nodo
            break;
        }else{
            //Seguimos buscando
            ultimo = actual; //Actualizamos ultimo
            //Buscamos el camino a seguir(El árbol está ordenado!!)
            if(resultadoComparacion < 0){
                actual = actual->izq;
            }else if(resultadoComparacion > 0){
                actual = actual->der;
            }
        }
    }//while(actual != nullptr)
    
    if(actual == nullptr){
        //No hemos encontado el nodo -> Lo añadimos
        //Creamos nodo
        NodoArbol *nuevo = new NodoArbol;
        
        //Actualizamos sus valores
        nuevo->valor = v;
        nuevo->izq = nullptr;
        nuevo->der = nullptr;
        
        //if(ultimo == nullptr)
        if(ultimo->der == nullptr && ultimo->izq == nullptr && ultimo->valor == 0){
            //El árbol estaba vacio
            raiz = nuevo;
        }else if(resultadoComparacion < 0){
            //Lo colocamos en la rama izquieda para seguir con el orden establecido en el arbol
            ultimo->izq = nuevo;
        }else{
            ultimo->der = nuevo;
        }
        return true; //Lo hemos podido insertar
    }
    return false; //No lo hemos podido insertar porque ya existia ese valor
}

int ArbolABB::Borrar(int v)
{
    NodoArbol *actual = raiz;
    NodoArbol *ultimo = nullptr;
    NodoArbol *marcador = nullptr;
    NodoArbol *sucesor = nullptr;
    
    int datoDeNodoBorrador = 0; //Lo que vamos a devolvver
    
    int ComparacionAnterior = 0;
    int resultadoComparacion = 0;
    
    while(actual != nullptr){
        //Vamos recorriendo
        ComparacionAnterior = resultadoComparacion;
        
        if(v == actual->valor){
            //Si son iguales guardará 1, si son distintos 0
            resultadoComparacion = 0;
        }else if(v < actual->valor){
            resultadoComparacion = -1;
        }else{
            resultadoComparacion = 1;
        }
        
        if(resultadoComparacion == 0){
            //Hemos encontrado el nodo
            break;
        }else{
            ultimo = actual;
            if(resultadoComparacion < 0){
                //Continuamos por la izquierda
                actual = actual->izq;
            }else{
                //Continuamos por la derecha
                actual = actual->der;
            }
        }
    }//While(actual != nullptr)
    
    if(actual != nullptr){
        //Hemos encontrado el nodo
        marcador = actual; //"Marcamos" el nodo que queremos borrar
        //Opciones que podemos tener
        if(actual->izq == nullptr && actual->der == nullptr){
            //Estamos en una hoja, sin hijos :)
            sucesor = nullptr;
        }else if(actual->izq == nullptr){
            //Tiene 1 hijo por la derecha
            sucesor = actual->der;
        }else if(actual->der == nullptr){
            //Tiene 1 hijo por la izquierda
            sucesor = actual->izq;
        }else{
            //Tiene 2 hijos
            //Apuntamos al subarbol derecho del nodo que queremos borrar
            actual = actual->der;
            sucesor = actual;
            
            //Descendemos al nodo más a la izquierda en el subarbol que estamos apuntando(El derecho del nodo a borrar)
            //(Será el valor más pequeño)
            //Hacemos que el subarbol izquierdo del nodo a borrar sea ahora el subarbol izquierdo de este nodo
            while(actual->izq != nullptr) {
                actual = actual->izq;
            }
            actual->izq = marcador->izq;
        }
        //Eliminamos el nodo y rehacemos los enlaces
        if(ultimo != nullptr){
            if(ComparacionAnterior < 0){
                ultimo->izq = sucesor;
            }else{
                ultimo->der = sucesor;
            }
        }else{
            raiz = sucesor;
        }
        datoDeNodoBorrador = marcador->valor;
        delete marcador;
        
        return datoDeNodoBorrador;
    }else{
        //El nodo buscado no está en el árbol
        return 0;
    }
}

NodoArbol *ArbolABB::Buscar(int v)
{
    NodoArbol *actual = raiz;
    
    while(actual != nullptr) {
        //Recorremos arbol hasta llegar a una hoja o encontrar el valor
        if(v == actual->valor){
            //Hemos encontrado el nodo
            return actual;
        }else if(v < actual->valor){
            //Continuamos por la izquierda
            actual = actual->izq;
        }else{
            //Continuamos por la derecha
            actual = actual->der;
        }
    }
    return nullptr; //No esta el valor en el arbol
}

void ArbolABB::InOrder(NodoArbol *n)
{
    if(n != nullptr){
        InOrder(n->izq);
        //Procesamos los datos, en nuestro caso los mostramos por pantalla
        cout << n->valor << " ";
        InOrder(n->der);
    }
}

void ArbolABB::PreOrder(NodoArbol *n)
{
    if(n != nullptr){
        //Procesamos los datos, en nuestro caso los mostramos por pantalla
        cout << n->valor << " ";
        PreOrder(n->izq);
        PreOrder(n->der);
    }
}

void ArbolABB::PostOrder(NodoArbol *n)
{
    if(n != nullptr){
        PostOrder(n->izq);
        PostOrder(n->der);
        //Procesamos los datos, en nuestro caso los mostramos por pantalla
        cout << n->valor << " ";
    }
}

void ArbolABB::RecorrerAnchura(NodoArbol *n)
{
    if(n != nullptr){
        //Si hay nodo
        NodoArbol *aux = n;
        queue<NodoArbol*> cola_aux; //Es una cola
        
        cola_aux.push(n);
        while(cola_aux.size() != 0){
            aux = cola_aux.front();
            cola_aux.pop();
            cout << aux->valor << " " << endl;
            
            if(aux->izq != nullptr){
                cola_aux.push(aux->izq);
            }
            if(aux->der != nullptr){
                cola_aux.push(aux->der);
            }
            //Cuando la cola aux esté vacía habremos visitado todos los nodos del árbol
        }
    }
}

NodoArbol *ArbolABB::getRaiz()
{
    return raiz;
}

void ArbolABB::Eliminar(NodoArbol *n)
{
    //Vamos borrando nodos haciendo recorrido en PosOrder
    if(n != nullptr){
        Eliminar(n->izq); //Lado izquierdo
        Eliminar(n->der); //Lado derecho
        
        delete n;     //Eliminar Nodo
        n = nullptr;
    }
    
}
