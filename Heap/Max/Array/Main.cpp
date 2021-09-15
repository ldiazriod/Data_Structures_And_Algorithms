#include <iostream>
#include <cmath>
#include <array>
#include <vector>

using namespace std;

const int Max = 50;

class Monticulo{
private:
    array<int, Max> MiArray;
    int CantidadMonticulo;
    
    void subir(int ind);
    void bajar(int ind);
    
public:
    Monticulo(){
        for(int i{0}; i < Max; i++){
            MiArray.at(i) = 0;
        }
        CantidadMonticulo = 0;
    }
    
    int getNodos(void){return  CantidadMonticulo;}
    
    void insertar(int valor);
    
    int suprimir(int pos);
    int borrarRaiz(void);
    
    void visualizar(void);
    
    vector<int> HeapSort(Monticulo);
};

vector<int> HeapSort(Monticulo mont){
    vector<int> retorno;
    while(mont.getNodos() != 0){
        retorno.push_back(mont.borrarRaiz());
    }
    return retorno;
}


void Monticulo::subir(int ind)
{
    if(ind > 0 && (MiArray.at(ind) > MiArray.at((ind-1)/2))){
        int aux = MiArray.at((ind-1)/2);
        MiArray.at((ind-1)/2) = MiArray.at(ind);
        MiArray.at(ind) = aux;
        
        subir((ind-1)/2);
    }
}

void Monticulo::bajar(int ind)
{
    int postemp = ind;
    
    if(((2*(ind+1)-1) < CantidadMonticulo) && (MiArray.at(2*(ind+1)-1) > MiArray.at(postemp))){
        postemp = 2*(ind+1)-1;
    }
    if(((2*(ind+1)) < CantidadMonticulo) && (MiArray.at(2*(ind+1)) > MiArray.at(postemp))){
        postemp = 2*(ind+1);
    }
    
    if(postemp != ind){
        int aux = MiArray.at(ind);
        MiArray.at(ind) = MiArray.at(postemp);
        MiArray.at(postemp) = aux;
        bajar(postemp);
    }
}

void Monticulo::insertar(int valor)
{
    MiArray.at(CantidadMonticulo) = valor;
    subir(CantidadMonticulo);
    
    CantidadMonticulo++;
}

int Monticulo::suprimir(int pos)
{
    int temp;
    temp = MiArray.at(pos);
    MiArray.at(pos) = MiArray.at(CantidadMonticulo-1);
    MiArray.at(CantidadMonticulo-1) = 0;
    CantidadMonticulo--;
    
    if(MiArray.at(pos) != temp){
        if(MiArray.at(pos) < temp){
            bajar(pos);
        }else{
            subir(pos);
        }
    }else{
        
    }
    return temp;
}

int Monticulo::borrarRaiz()
{
    return suprimir(0);
}

void Monticulo::visualizar()
{
    cout << "[ ";
    for(int i{0}; i < CantidadMonticulo; i++){
        cout << MiArray.at(i) << " ";
    }
    cout << " ]" << endl;
}

int main()
{
    cout << "Ejemplo monticulo" << endl;
    
    Monticulo MiMunticulito;
    
    cout << "Insertamos 8..." << endl;
    MiMunticulito.insertar(8);
    cout << "Insertamos 10..." << endl;
    MiMunticulito.insertar(10);
    cout << "Insertamos 2..." << endl;
    MiMunticulito.insertar(2);
    cout << "Insertamos 1..." << endl;
    MiMunticulito.insertar(1);
    cout << "Insertamos 8..." << endl;
    MiMunticulito.insertar(8);
    cout << "Insertamos 12..." << endl;
    MiMunticulito.insertar(12);
    cout << "Insertamos 20..." << endl;
    MiMunticulito.insertar(20);
    cout << "Insertamos 3..." << endl;
    MiMunticulito.insertar(3);
    
    cout << "Visualizamos..." << endl;
    MiMunticulito.visualizar();
    cout << "Borramos raiz(maximo)..." << MiMunticulito.borrarRaiz() << endl;
    MiMunticulito.visualizar();
    cout << "Borramos posicion 1..." << MiMunticulito.suprimir(1);
    MiMunticulito.visualizar();
    
    vector<int> desordenado{8,9,7,1,2,50,50,1,0};
    Monticulo ParaOrdenar;
    
    cout << "El vector desordenado es: ";
    for(auto elem : desordenado){
        ParaOrdenar.insertar(elem);
        cout << elem << " ";
    }
    cout << endl;
    
    vector<int> Ordenado = HeapSort(ParaOrdenar);
    cout << "El vector ordenado es:  ";
    for(auto elem2 : Ordenado){
        cout << elem2 << " ";
    }
    cout << endl;
    
    return 0;
}
