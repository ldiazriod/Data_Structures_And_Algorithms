#include <iostream>
#include <array>

using namespace std;

const int NmaxNodos = 30;

struct Arista{
    int info;
    bool existe;
};

struct Nodo{
    int info;
    bool existe;
    bool visitado;
};

class GrafoMatrizAdy{
public:
    GrafoMatrizAdy(void);
    
    bool GrafoVacio(void){
        if(numNodos == 0){
            return true;
        }else return false;
    }
    
    int numeroNodos(void){return  numNodos;}
    int numeroArcos(void){
        int nArcos{0};
        for(int i{0}; i < NmaxNodos; i++){
            for(int j{0}; j < NmaxNodos; j++){
                if(MatrizAdyaciencia.at(i).at(j).existe){
                    nArcos++;
                }
            }
        }
        return nArcos;
    }
    
    bool insertarNodo(Nodo n);
    bool crearArista(Nodo n1, Nodo n2, Arista);
    
    void imprimirMat(void);
    void imprimirNodos(void);
    
    bool explorar(Nodo inicio);
    
    bool suprimirNodo(int valor);
    bool suprimirArista(int n1, int n2);
    
private:
    array<Nodo, NmaxNodos> ListaNodos;
    array<array<Arista, NmaxNodos>, NmaxNodos> MatrizAdyaciencia;
    int numNodos;
    
    void resetVisitados(void){
        for(auto &elem : ListaNodos){
            elem.visitado = false;
        }
    }
};

GrafoMatrizAdy::GrafoMatrizAdy()
{
    for(unsigned long i{0}; i < NmaxNodos; i++){
        ListaNodos.at(i).info = false;
        ListaNodos.at(i).existe = false;
        for(unsigned long j{0}; j < NmaxNodos; j++){
            MatrizAdyaciencia.at(i).at(j).info = 0;
            MatrizAdyaciencia.at(i).at(j).existe = false;
        }
    }
    numNodos = 0;
}

bool GrafoMatrizAdy::insertarNodo(Nodo n)
{
    unsigned long aux{0};
    while((ListaNodos.at(aux).existe == true) && (aux < NmaxNodos)){
        aux++;
    }
    if(aux == NmaxNodos){
        return false;
    }else{
        ListaNodos.at(aux).existe = true;
        ListaNodos.at(aux).info = n.info;
        numNodos++;
        return true;
    }
}

bool GrafoMatrizAdy::crearArista(Nodo n1, Nodo n2, Arista A)
{
    unsigned long i{0}, j{0};
    while((i < NmaxNodos) && (ListaNodos.at(i).existe) && (ListaNodos.at(i).info != n1.info)){
        i++;
    }
    if(i == NmaxNodos){
        return false;
    }else{
        j = 0;
        while((j < NmaxNodos) && (ListaNodos.at(j).existe) && (ListaNodos.at(j).info != n2.info)){
            j++;
        }
        if(j == NmaxNodos){
            return false;
        }else{
            if(MatrizAdyaciencia.at(i).at(j).existe){
                return false;
            }else{
                MatrizAdyaciencia.at(i).at(j).existe = true;
                MatrizAdyaciencia.at(i).at(j).info = A.info;
                return true;
            }
        }
    }
}

void GrafoMatrizAdy::imprimirMat()
{
    for(int i{0}; i < NmaxNodos; i++){
        for(int j{0}; i < NmaxNodos; j++){
            cout << MatrizAdyaciencia[i][j].existe;
        }
        cout << endl;
    }
}

void GrafoMatrizAdy::imprimirNodos()
{
    for(unsigned long i{0}; i < NmaxNodos; i++){
        cout << ListaNodos[i].info;
    }
    cout << endl;
    cout << endl;
}

bool GrafoMatrizAdy::explorar(Nodo inicio)
{
    resetVisitados();
    unsigned long i{0}, j{0};
    bool cambioFila{false}, fin{false};
    
    while ((i < NmaxNodos) && ListaNodos.at(i).info != inicio.info) {
        i++;
    }
    if(i >= NmaxNodos){
        cout << "Nodo inicio no valido" << endl;
        return false;
    }else{
        cout << ListaNodos.at(i).info << " ";
        while(!fin){
            cambioFila = false;
            if((MatrizAdyaciencia.at(i).at(j).existe == 1) && (ListaNodos.at(j).visitado == false) && (i < NmaxNodos) && (j < NmaxNodos)){
                cout << ListaNodos.at(j).info << " ";
                ListaNodos.at(j).visitado = true;
                i = j;
                j = 0;
                cambioFila = true;
            }
            if(!cambioFila){
                j++;
            }
            if(j > NmaxNodos){
                fin = true;
            }
        }
        return true;
    }
}

bool GrafoMatrizAdy::suprimirNodo(int valor)
{
    unsigned long auxi{0}, auxJ{0};
    while((auxi < NmaxNodos) && (ListaNodos.at(auxi).existe) && (ListaNodos.at(auxi).info != valor)){
        auxi++;
    }
    if(auxi == NmaxNodos){
        return false;
    }else{
        ListaNodos.at(auxi).info = 0;
        ListaNodos.at(auxi).existe = 0;
        ListaNodos.at(auxi).visitado = 0;
        
        for(auxJ = 0; auxJ < NmaxNodos; auxJ++){
            MatrizAdyaciencia.at(auxi).at(auxJ).existe = false;
            MatrizAdyaciencia.at(auxJ).at(auxi).existe = false;
            MatrizAdyaciencia.at(auxi).at(auxJ).info = 0;
            MatrizAdyaciencia.at(auxJ).at(auxi).info = 0;
        }
        return true;
    }
    
}

bool GrafoMatrizAdy::suprimirArista(int n1, int n2)
{
    unsigned long auxI{0}, auxJ{0};
    while((auxI < NmaxNodos) && (ListaNodos.at(auxI).existe) && (ListaNodos.at(auxI).info != n1)){
        auxI++;
    }
    if(auxI == NmaxNodos){
        return false;
    }else{
        auxJ = 0;
        while((auxJ < NmaxNodos) && (ListaNodos.at(auxJ).existe) && (ListaNodos.at(auxJ).info != n2)){
            auxJ++;
        }
        if(auxJ == NmaxNodos){
            return false;
        }else{
            MatrizAdyaciencia.at(auxI).at(auxJ).existe = 0;
            MatrizAdyaciencia.at(auxI).at(auxJ).info = 0;
        }
        return true;
    }
}

int main()
{
    cout << "Hello World!" << endl;
    
    GrafoMatrizAdy Grafo;
    
    cout << "El grafo esta vacio?: ";
    cout << Grafo.GrafoVacio() << endl;
    
    Grafo.insertarNodo({1,0,0});
    Grafo.insertarNodo({2,0,0});
    Grafo.insertarNodo({3,0,0});
    Grafo.insertarNodo({4,0,0});
    
    cout << "El grafo esta vacio?: ";
    cout << Grafo.GrafoVacio() << endl;
    cout << "El grafo tiene " << Grafo.numeroNodos() << " nodos." << endl;
    cout << "El grafo tiene " << Grafo.numeroArcos() << " arcos." << endl;
    cout << "*****************************" << endl;
    
    Grafo.crearArista({1,0,0},{2,0,0},{0,true});
    Grafo.crearArista({1,0,0},{3,0,0},{0,true});
    Grafo.crearArista({1,0,0},{4,0,0},{0,true});
    Grafo.crearArista({1,0,0},{4,0,0},{0,true});
    Grafo.crearArista({2,0,0},{4,0,0},{0,true});
    
    cout << "El grafo esta vacio?: ";
    cout << Grafo.GrafoVacio() << endl;
    cout << "El grafo tiene " << Grafo.numeroNodos() << " nodos." << endl;
    cout << "El grafo tiene " << Grafo.numeroArcos() << " arcos." << endl;
    cout << "*****************************" << endl;
    
    Grafo.imprimirNodos();
    Grafo.imprimirMat();
    
    Grafo.explorar({1, 0, 0});
    
    return 0;
}
