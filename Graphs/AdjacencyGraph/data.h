#ifndef DATA_H
#define DATA_H

#include <iostream>

using namespace std;

class Dato
{
    friend bool operator == (Dato const & d1, Dato const & d2);
    //Sobrecarga de operador igual, para poder comprar Dato
    friend ostream & operator << (ostream & os, Dato const & d);
    //Sobre carga de operador << Para poder imprimir Dato.
public:
    Dato(int v); //Constructor
    
    int getValue() const; //Getter para poder acceder a la parte privada
    void setValue(int value); //Setter para poder acceder a la parte privada
    
public:
    int value;
};

#endif // DATA_H
