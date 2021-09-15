#include "data.h"

Dato::Dato(int v):value{v}
{
    
}

int Dato::getValue() const
{
    return value;
}

void Dato::setValue(int v)
{
    value = v;
}

bool operator == (const Dato &d1, const Dato &d2){
    return (d1.value == d2.value);
}

ostream &operator << (ostream &os, const Dato &d){
    os << d.value;
    return os;
}
