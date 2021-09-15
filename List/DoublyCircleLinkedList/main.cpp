#include <iostream>

using namespace std;

struct elemento{
    string nombre;
    elemento *SiguienteElemento;
    elemento *AnteriorElemento;
};

struct IdentificadorLista{
    elemento *Primero;
    int tamano;
};

class ListaDoble{
private:
    IdentificadorLista *MiLista = new IdentificadorLista;
public:
    ListaDoble();
    bool InsertarNodoEnListaVacia(string info);
    bool InsertarNodoPosicion(string info, int posicion);
    bool SuprimirNodoPosicion(int posicion);
    void Destruir(void);
    void ImprimirLista(void);
};

int main()
{
    cout << "Empezamos..." << endl;
    
    ListaDoble MiLista;
    
    elemento N1 = {"Primer nodo", nullptr, nullptr};
    elemento N2 = {"Segundo nodo", nullptr, nullptr};
    elemento N3 = {"Tercer nodo", nullptr, nullptr};
    elemento N4 = {"Cuarto nodo", nullptr, nullptr};
    elemento N5 = {"Quinto nodo", nullptr, nullptr};
    elemento N6 = {"Sexto nodo", nullptr, nullptr};
    
    cout << "Nodo en lista vacia" << endl;
    MiLista.InsertarNodoEnListaVacia(N1.nombre);
    MiLista.ImprimirLista();
    
    cout << endl;
    
    cout << "Nodo en posicion 0(empezamos en 0)" << endl;
    MiLista.InsertarNodoPosicion("Nodo 0", 0);
    MiLista.ImprimirLista();
    
    cout << endl;
    
    cout << "Nodo en posicion 1(empezamos en 0)" << endl;
    MiLista.InsertarNodoPosicion(N2.nombre, 1);
    MiLista.ImprimirLista();
    
    cout << endl;
    
    cout << "Nodo en posicion 2(Empezamos en 0)" << endl;
    MiLista.InsertarNodoPosicion(N3.nombre, 2);
    MiLista.ImprimirLista();
    
    cout << endl;
    
    cout << "Nodo en posicion 3(Empezamos en 0)" << endl;
    MiLista.InsertarNodoPosicion(N4.nombre, 3);
    MiLista.ImprimirLista();
    
    cout << endl;
    
    cout << "Suprimimos nodo posicion 2(Empezamos en 0)" << endl;
    MiLista.SuprimirNodoPosicion(2);
    MiLista.ImprimirLista();
    
    cout << endl;
    
    cout << "Destruimos lista" << endl;
    MiLista.Destruir();
    
    cout << "Hemos terminado..." << endl;
    return 0;
}

ListaDoble::ListaDoble()
{
    MiLista->Primero=nullptr;
    MiLista->tamano = 0;
}

bool ListaDoble::InsertarNodoEnListaVacia(string info)
{
    if(MiLista->tamano==0){
        elemento *NodoNuevo;
        NodoNuevo = new elemento; //Reserva en memoria dinamica para un nuevo nodo
        
        NodoNuevo->nombre = info; //Actualizamos punteros del nuevo nodo, al ser el primero apuntan a null los 2
        
        NodoNuevo->SiguienteElemento = nullptr;
        NodoNuevo->AnteriorElemento = nullptr;
        
        MiLista->Primero = NodoNuevo; //Actualizamos nuestro identificador de lista
        
        MiLista->tamano++;
        return 1;
    }else{
        return 0;
    }
}

bool ListaDoble::InsertarNodoPosicion(string info, int posicion)
{
    //Comprobaciones iniciales
    if(MiLista->tamano < posicion || MiLista->tamano == 0){
        return 0;
    }
    
    elemento *NodoNuevo, *temporal, *aux;
    NodoNuevo = new elemento;
    
    NodoNuevo->nombre = info;
    
    if(MiLista->tamano == 1){
        MiLista->Primero->SiguienteElemento = NodoNuevo;
        MiLista->Primero->AnteriorElemento = NodoNuevo;
        NodoNuevo->SiguienteElemento = MiLista->Primero;
        NodoNuevo->AnteriorElemento = MiLista->Primero;
        MiLista->Primero = NodoNuevo;
    }else{
        if(posicion == 0){
            temporal = MiLista->Primero->AnteriorElemento;
            aux = MiLista->Primero;
            
            temporal->SiguienteElemento = NodoNuevo;
            NodoNuevo->SiguienteElemento = aux;
            
            aux->AnteriorElemento = NodoNuevo;
            NodoNuevo->AnteriorElemento = temporal;
            
            MiLista->Primero = NodoNuevo;
        }else if(posicion > 0){
            temporal = MiLista->Primero;
            for(int i{1}; i < posicion; i++){
                temporal = temporal->SiguienteElemento;
            }
            aux = temporal->SiguienteElemento;
            
            temporal->SiguienteElemento = NodoNuevo;
            NodoNuevo->SiguienteElemento = aux;
            
            aux->AnteriorElemento = NodoNuevo;
            NodoNuevo->AnteriorElemento = temporal;
        }
    }
    
    MiLista->tamano++;
    return 1;
}

bool ListaDoble::SuprimirNodoPosicion(int posicion)
{
    if(MiLista->tamano <= 0 || MiLista->tamano < posicion){
        return 0;
    }
    elemento *Suprimir, *temporal, *aux;
    
    if(posicion == 0){
        temporal = MiLista->Primero->AnteriorElemento;
        Suprimir = MiLista->Primero;
        aux = MiLista->Primero->SiguienteElemento;
        
        temporal->SiguienteElemento = aux;
        aux->AnteriorElemento = temporal;
        
        MiLista->Primero = aux;
        MiLista->tamano--;
    }else{
        temporal = MiLista->Primero;
        for(int i{1}; i < posicion; i++){
            temporal = temporal->SiguienteElemento;
        }
        aux = temporal->SiguienteElemento->SiguienteElemento;
        
        Suprimir = temporal->SiguienteElemento;
        aux->AnteriorElemento = temporal;
        
        delete Suprimir;
        MiLista->tamano--;
    }
    return 1;
}

void ListaDoble::Destruir()
{
    while(MiLista->tamano > 0) {
        cout << "Borramos primer nodo..." << endl;
        SuprimirNodoPosicion(0);
        ImprimirLista();
    }
}

void ListaDoble::ImprimirLista()
{
    elemento *temporal;
    
    temporal = MiLista->Primero;
    int elementos = MiLista->tamano;
    
    cout << "--Inicio de la lista--" << endl;
    while(elementos != 0){
        cout << "Dir nodo: " << temporal << "|| Anterior nod: " << temporal->AnteriorElemento << " " << "|| Siguiente nodo: " << temporal->SiguienteElemento << " " << "|| Nombre nodo: " << temporal->nombre << endl;
        temporal = temporal->SiguienteElemento;
        elementos--;
    }
   cout << "--Fin de la lista--" << endl;
}
