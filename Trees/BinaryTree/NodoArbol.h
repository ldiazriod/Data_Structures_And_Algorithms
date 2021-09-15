#ifndef NODOARBOL_H
#define NODOARBOL_H

class NodoArbolBin{
public:
    NodoArbolBin(){
        dato = 0;
        izquierda = nullptr;
        derecha = nullptr;
    }
    
    NodoArbolBin(int valor){
        dato = valor;
        izquierda = nullptr;
        derecha = nullptr;
    }
    
    
    int getDato() const{return dato;}
    void setDato(int value){dato = value;}
    
    NodoArbolBin *getIzquierda() const{return izquierda;}
    void setIzquierda(NodoArbolBin *value){izquierda = value;}
    
    NodoArbolBin *getDerecha() const{return derecha;}
    void setDerecha(NodoArbolBin *value){derecha = value;}
    
private:
    int dato;
    NodoArbolBin* izquierda, *derecha;
};

#endif // NODOARBOL_H
