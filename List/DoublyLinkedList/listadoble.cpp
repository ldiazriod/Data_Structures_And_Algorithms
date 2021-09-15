#include "listadoble.h"

ListaDoble::ListaDoble()
{
    MiLista->Primero=nullptr;
    MiLista->Ultimo = nullptr;
    MiLista->tamano = 0;
}

bool ListaDoble::InsertarNodoEnListaVacia(nodo *n){
    if(MiLista->Primero == nullptr){
        nodo *NuevoNodo = new nodo;

        *NuevoNodo = *n;

        NuevoNodo->SiguienteElemento = nullptr;
        NuevoNodo->AnteriorElemento = nullptr;

        MiLista->Primero = NuevoNodo;
        MiLista->Ultimo = NuevoNodo;

        MiLista->tamano++;

        return true;
    }else{
        return false;
    }
}

bool ListaDoble::InsertarNodoInicioLista(nodo *n)
{
    if(MiLista->Primero != nullptr){
        nodo *NuevoNodo = new nodo;

        *NuevoNodo = *n;

        NuevoNodo->SiguienteElemento = MiLista->Primero;
        NuevoNodo->AnteriorElemento = nullptr;

        MiLista->Primero->AnteriorElemento = NuevoNodo;

        MiLista->Primero = NuevoNodo;
        MiLista->tamano++;

        return true;
    }else{
        return false;
    }
}

bool ListaDoble::InsertarNodoFinLista(nodo *n)
{
    if(MiLista->Primero != nullptr){
        nodo *NuevoNodo = new nodo;

        *NuevoNodo = *n;

        NuevoNodo->SiguienteElemento = nullptr;
        NuevoNodo->AnteriorElemento = MiLista->Ultimo;

        MiLista->Ultimo->SiguienteElemento = NuevoNodo;
        MiLista->Ultimo = NuevoNodo;

        MiLista->tamano++;

        return true;
    }else{
        return false;
    }
}

bool ListaDoble::SuprimirInicioLista()
{
    if(MiLista->tamano == 0){
        return 0;
    }

    nodo *ASuprimir;

    ASuprimir = MiLista->Primero;

    MiLista->Primero = ASuprimir->SiguienteElemento;

    if(MiLista->tamano == 1){
        MiLista->Ultimo = nullptr;
        MiLista->Primero = nullptr;
    }else{
        MiLista->Primero->AnteriorElemento = nullptr;
    }

    delete ASuprimir;

    MiLista->tamano--;

    return 1;
}

bool ListaDoble::SuprimirFinLista()
{
    if(MiLista->tamano == 0){
        return 0;
    }

    nodo *ASuprimir;

    ASuprimir = MiLista->Ultimo;

    MiLista->Ultimo = ASuprimir->AnteriorElemento;

    if(MiLista->tamano == 1){
        MiLista->Ultimo = nullptr;
        MiLista->Primero = nullptr;
    }else{
        MiLista->Ultimo->SiguienteElemento = nullptr;
    }

    delete ASuprimir;

    MiLista->tamano--;

    return 1;
}

bool ListaDoble::SuprimirNodoPosicion(int pos)
{
    if(MiLista->tamano <= 0 || pos < 0 || pos>MiLista->tamano){
        return 0;
    }

    if(MiLista->tamano == pos){
        nodo *Suprimir;

        Suprimir = MiLista->Ultimo;

        MiLista->Ultimo->AnteriorElemento->SiguienteElemento = nullptr;
        MiLista->Ultimo = MiLista->Ultimo->AnteriorElemento;

        delete Suprimir;
        MiLista->tamano--;

    }else{
        nodo *Suprimir, *temporal;

        temporal = MiLista->Primero;
        for(int i{0}; i < pos; i++){
            temporal = temporal->SiguienteElemento;
        }

        Suprimir = temporal;
        temporal->SiguienteElemento->AnteriorElemento = Suprimir->AnteriorElemento;
        temporal->AnteriorElemento->SiguienteElemento = Suprimir->SiguienteElemento;

        delete Suprimir;
        MiLista->tamano--;
        return 1;
    }
}

bool ListaDoble::ImprimirLista(bool sentido)
{
    if(MiLista->Primero != nullptr){
        nodo *temporal;

        if(sentido){
            temporal = MiLista->Primero;
            cout << "--Inicio de la lista--" << endl;
            while(temporal != nullptr){
                cout << "Dir nodo: " << temporal << "|| Anterior nodo: "<< temporal->AnteriorElemento << " " << "|| Siguiente nodo: " << temporal->SiguienteElemento << " " << "|| Nombre nodo: " << temporal->nombre << endl;
                temporal = temporal->SiguienteElemento;
            }
            cout << "--Final de la lista--" << endl;
        }else{
            temporal = MiLista->Ultimo;
            cout << "--Final de la lista--" << endl;
            while(temporal != nullptr){
                cout << "Dir nodo: " << temporal << "<|| Siguiente nodo: " << temporal->SiguienteElemento << " " << "|| Anterior nodo: " <<  temporal->AnteriorElemento << " " << "|| Nombre nodo: " << temporal->nombre << endl;
                temporal = temporal->AnteriorElemento;
            }
            cout << "--Inicio de la lista--" << endl;
        }
        return true;
    }else{
        cout << "La lista esta vacia." << endl;
        return false;
    }
}

nodo *ListaDoble::getNodoInicio()
{
    return MiLista->Primero;
}

nodo *ListaDoble::getNodoFin()
{
    return MiLista->Ultimo;
}

int ListaDoble::Buscar(int valor)
{
    nodo* aux = MiLista->Primero;
    int pos{0};

    while(aux != nullptr) {
        if(aux->valor == valor){
            return pos;
        }else{
            aux = aux->SiguienteElemento;
            pos++;
        }
    }

    return -1;
}

bool ListaDoble::SuprimirNodo(int v)
{
    int pos = Buscar(v);

    if(pos != -1){
        if(pos == 0){
            return SuprimirInicioLista();
        }else{
            return SuprimirNodoPosicion(pos);
        }
    }else{
        cout << "Nodo no encontrado" << endl;
        return 0;
    }
}

nodo *ListaDoble::BusquedaRecursiva(int v, nodo *inicio)
{
    if(inicio->SiguienteElemento != nullptr){
        if(inicio->valor == v){
            return inicio;
        }else{
            BusquedaRecursiva(v, inicio->SiguienteElemento);
        }
    }else{
        return nullptr;
    }
}

void ListaDoble::RecorrerRecursvio(bool sentido, nodo *inicio)
{
    if(sentido == true){
        if(inicio->SiguienteElemento != nullptr){
            cout << inicio->valor << " ";
            RecorrerRecursvio(sentido, inicio->SiguienteElemento);
        }else{
            cout << inicio->valor << endl;
        }
    }else{
        if(inicio->AnteriorElemento != nullptr){
            cout << inicio->valor << " ";
            RecorrerRecursvio(sentido, inicio->AnteriorElemento);
        }
    }
}

int ListaDoble::SumaListaRecursiva(nodo *inicio)
{
    int resultado{0};

    if(inicio->SiguienteElemento != nullptr){
        resultado = inicio->valor + SumaListaRecursiva(inicio->SiguienteElemento);
        return resultado;
    }else{
        return resultado+inicio->valor;
    }
}

bool ListaDoble::EliminaRecusivo(int v, nodo *inicio)
{
    if(inicio->SiguienteElemento != nullptr){
        if(inicio->valor == v){
            return SuprimirNodo(inicio->valor);
        }
        EliminaRecusivo(v, inicio->SiguienteElemento);
    }else{
        return 0;
    }
}

void ListaDoble::DestruirRecursivo(nodo *inicio)
{
    if(inicio->SiguienteElemento != nullptr){
        SuprimirInicioLista();
        DestruirRecursivo(inicio->SiguienteElemento);
    }else{
        SuprimirInicioLista();
    }
}
