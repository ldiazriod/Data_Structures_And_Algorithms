#include "grafo.h"

Grafo::Grafo()
{
    nNodos=0;
}

Grafo::Grafo(int nodos)
{
    this->nNodos = nodos;
    this->ListaNodos.resize(nNodos,{0,false,false,0});
    //this->MatrizAdyacencia.resize(nNodos);

    std::vector<Arista> temp;
    temp.resize(nNodos, {std::numeric_limits<int>::max(),false});
    this->MatrizAdyacencia.resize(nNodos,temp);
}

bool Grafo::insertarNodo(Nodo n)
{
    for(auto i:ListaNodos)
    {
        if(i.info==n.info)
        {//Existe nodo, no lo añadimos
            return false;
        }
    }

    ListaNodos.push_back(n);
    ListaNodos.at(ListaNodos.size()-1).existe=true;
    ListaNodos.at(ListaNodos.size()-1).visitado=false;
    ListaNodos.at(ListaNodos.size()-1).distancia=0;
    this->nNodos++;

    //También tenemos que aumentar la Matriz de adyacencia
    if(MatrizAdyacencia.size()==0)
    {//esta vacia->creamos primera arista
        MatrizAdyacencia.resize(1,{{std::numeric_limits<int>::max(),false}});
    }
    else
    {
        for(auto &i:MatrizAdyacencia)
        {//Incrementamos columna
            i.resize(i.size()+1,{std::numeric_limits<int>::max(),false});
        }
        std::vector<Arista> temp=MatrizAdyacencia.at(0);
        MatrizAdyacencia.resize(MatrizAdyacencia.size()+1,temp); //Incrementamos fila
    }
    return true;
}

bool Grafo::crearArista(Nodo orig,Nodo dest,Arista a)
{
    unsigned long i_aux=0, j_aux=0;

    while ( (i_aux < ListaNodos.size()) && (ListaNodos[i_aux].existe) && (ListaNodos[i_aux].info != orig.info) )
    {//Buscamos el indice con la info de N1 (origen de la arista)
        i_aux++;
    }

    if (i_aux == ListaNodos.size())
    {//El Nodo1 no está en la lista de nodos->no podemos crear arista
        return false;
    }
    else
    {
        j_aux = 0;
         while ( (j_aux < ListaNodos.size()) && (ListaNodos[j_aux].existe) && (ListaNodos[j_aux].info != dest.info) )
         {//Buscamos el indice con la info de N2 (destino de la arista)
            j_aux++;
         }

        if (j_aux == ListaNodos.size())
        {//El Nodo2 no está en la lista de nodos->no podemos crear arista
            return false;
        }
        else
        {
            if (MatrizAdyacencia[i_aux][j_aux].existe)
            {//Ya existía la arista (relación) entre N1 y N2
                return false;
            }
            else
            {//Guardamos la info de la nueva arista
                MatrizAdyacencia[i_aux][j_aux].existe = true;
                MatrizAdyacencia[i_aux][j_aux].info = a.info;

                ListaNodos[i_aux].Vecinos.push_back(&ListaNodos[j_aux]); //añadimos el nodo destino como vecino del origen

                return true;
            }

        }//else de j_aux==NmaxNodos
    }//else de i_aux==NmaxNodos
}

void Grafo::imprimirMatriz()
{
    for(int i=0;i<ListaNodos.size();i++)
    {
        for(int j=0;j<ListaNodos.size();j++)
        {
            std::cout<<MatrizAdyacencia[i][j].existe;
        }
        std::cout<<std::endl;
    }
}

void Grafo::imprimirNodos()
{
    for(unsigned long i=0;i<ListaNodos.size();i++)
    {
        std::cout<<ListaNodos[i].info;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
}


vector<vector<int>> Grafo::prim()
{
    //Usamos una copia de la matriz porque vamos a "trastearla" y no queremos perder la original
    vector<vector<Arista>> adyacencia = this->MatrizAdyacencia;
    vector<vector<int>> MatrArbol(nNodos); //4filas y 0columnas
    vector<int> marcas;

    //Inicializo las distancias de la matriz arbol a "infinito"
    for(int i=0;i<nNodos;i++)
    {//Inicializo cada fila de la MatrArbol con un vector de nNodos elementos inicializados a "infinito"
        MatrArbol[i] = vector<int>(nNodos, std::numeric_limits<int>::max());
    }

    int padre = 0;
    int hijo = 0;
    while(marcas.size() + 1 < nNodos)
    {
        padre = hijo;
        //Marco la fila y pongo a infinito la columna del nodo padre.
        marcas.push_back(padre);
        for(int i = 0; i < nNodos; i++)
        {
            adyacencia[i][padre].info = std::numeric_limits<int>::max();
        }

        //Encuentro la menor distancia entre las filas marcadas.
        //El nodo padre es la linea marcada y el nodo hijo es la columna del minimo.
        int min = std::numeric_limits<int>::max();

        for(int i=0;i<marcas.size();i++)
        {
            for(int j = 0; j < nNodos; j++)
            {
                if(min > adyacencia[i][j].info)
                {
                    min = adyacencia[i][j].info;
                    padre = i;
                    hijo = j;
                }
            }
        }

        MatrArbol[padre][hijo] = min;
        MatrArbol[hijo][padre] = min;
    }
    return MatrArbol;
}

void Grafo::primMST()
{//MinimumSpanningTree
    vector<vector<Arista>> mat=MatrizAdyacencia;

    // Array para guardar el árbol
    int padre[nNodos];

    //Para guardar el peso mínimo
    int PesoMin[nNodos];

    //Conjunto de nodos que aún no hemos incluido en el árbol
    bool SinIncluir[nNodos];

    //Inicializamos
    for (int i=0;i<nNodos;i++)
    {
        padre[i]=0;
        PesoMin[i] = std::numeric_limits<int>::max();
        SinIncluir[i] = false;
    }

    //Empezamos por el primer Nodo, distancia a si mismo 0
    PesoMin[0] = 0;
    padre[0] = -1; //Será el nodo raizdel árbol (no tiene padre)

    //El árbol mínimo tendrá el mismo número de nodos que el grafo
    for (int i = 0;i<nNodos-1;i++)
    {
        //Buscamos el Nodo con la arista de menor peso que aún no ha sido incluido en el árbol
        int u = PesoMinimo(PesoMin, SinIncluir);

        //Incluimos el Nodo
        SinIncluir[u] = true;

        //Actualizamo el peso mínimos y el índice padre de los nodos adyacentes
        //Tenemos en cuenta sólo los nodos que aún no se han incluido al árbol
        for (int v=0;v<nNodos;v++)
        {
            //Si existe la arista, su nodo aún no ha sido incluido y su peso es menor que el mínimo
            if (mat[u][v].existe && SinIncluir[v] == false && mat[u][v].info < PesoMin[v])
            {
                padre[v] = u;
                PesoMin[v] = mat[u][v].info;
            }
        }
    }

    //Mostramos aristas del árbol mínimo y su peso
    cout<<"Arista"<<"||"<<"Peso"<<endl;
    for (int i=1;i<nNodos;i++)
    {
        cout<<padre[i]<<" - "<<i<<" \t"<<mat[i][padre[i]].info<<" \n";
    }
}

int Grafo::PesoMinimo(int PesoMin[], bool SinIncluir[])
{
    //inicializamos min a "infinito"
    int min = std::numeric_limits<int>::max(), min_indice;

    for (int v=0;v<ListaNodos.size();v++)
    {
        if (SinIncluir[v]==false && PesoMin[v] < min)
        {//No ha sido incluido y
            min = PesoMin[v];
            min_indice = v;
        }
    }
    return min_indice;
}
