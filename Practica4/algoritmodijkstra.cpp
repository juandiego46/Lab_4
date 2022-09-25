#include "algoritmodijkstra.h"

#include<iostream>
#include<string>

using namespace std;

// constructor
AlgoritmoDijkstra::Graph_DG(int vexnum, int edge) {
    // Inicializa el número de vértices y aristas
    this->vexnum = vexnum;
    this->edge = edge;
    // Abrir el espacio y asignar valores iniciales para la matriz de adyacencia
    arc = new int*[this->vexnum];
    dis = new Dis[this->vexnum];
    for (int i = 0; i < this->vexnum; i++) {
        arc[i] = new int[this->vexnum];
        for (int k = 0; k < this->vexnum; k++) {
            // La matriz de adyacencia se inicializa al infinito
                arc[i][k] = INT_MAX;
        }
    }
}
// Destructor
Graph_DG::~Graph_DG() {
    delete[] dis;
    for (int i = 0; i < this->vexnum; i++) {
        delete this->arc[i];
    }
    delete arc;
}
// juzga si la información del borde que ingresamos es legal cada vez
// Los vértices están numerados de 1
bool Graph_DG::check_edge_value(int start, int end, int weight) {
    if (start<1 || end<1 || start>vexnum || end>vexnum || weight < 0) {
        return false;
    }
    return true;
}
void Graph_DG::createGraph() {
    cout << "Ingrese el punto de inicio y el punto final de cada borde (el número de vértice comienza desde 1) y su peso" << endl;
    int start;
    int end;
    int weight;
    int count = 0;
    while (count != this->edge) {
        cin >> start >> end >> weight;
        // Primero determine si la información de borde es legal
        while (!this->check_edge_value(start, end, weight)) {
            cout << "La información ingresada es ilegal, vuelva a ingresar" << endl;
            cin >> start >> end >> weight;
        }
        // Asigna los puntos correspondientes en la matriz de adyacencia
        arc[start - 1][end - 1] = weight;
        // Agregue esta línea de código al gráfico no dirigido
        //arc[end - 1][start - 1] = weight;
        ++count;
    }
}
void Graph_DG::print() {
    cout << "La matriz de adyacencia del gráfico es:" << endl;
    int count_row = 0; // Imprime la etiqueta de la línea
    int count_col = 0; // Imprime la etiqueta de la columna
    // Comienza a imprimir
    while (count_row != this->vexnum) {
        count_col = 0;
        while (count_col != this->vexnum) {
            if (arc[count_row][count_col] == INT_MAX)
                cout << "∞" << " ";
            else
            cout << arc[count_row][count_col] << " ";
            ++count_col;
        }
        cout << endl;
        ++count_row;
    }
}
void Graph_DG::Dijkstra(int begin){
    // Primero inicializa nuestra matriz
    int i;
    for (i = 0; i < this->vexnum; i++) {
        // Establecer la ruta actual
        dis[i].path = "v" + to_string(begin) + "-->v" + to_string(i + 1);
        dis[i].value = arc[begin - 1][i];
    }
    // Establece la ruta desde el punto de partida hasta el punto de partida en 0
    dis[begin - 1].value = 0;
    dis[begin - 1].visit = true;

    int count = 1;
    // Calcule la ruta más corta de los vértices restantes (este-> vexnum-1 vértices restantes)
    while (count != this->vexnum) {
        // temp se usa para guardar el subíndice más pequeño en la matriz de distribución actual
        // El valor mínimo actual registrado por min
        int temp=0;
        int min = INT_MAX;
        for (i = 0; i < this->vexnum; i++) {
            if (!dis[i].visit && dis[i].value<min) {
                min = dis[i].value;
                temp = i;
            }
        }
        //cout << temp + 1 << "  "<<min << endl;
        // Agregue el vértice correspondiente a temp al conjunto de rutas más cortas que se han encontrado
        dis[temp].visit = true;
        ++count;
        for (i = 0; i < this->vexnum; i++) {
            // Tenga en cuenta la condición aquí arc [temp] [i]! = INT_MAX debe agregarse, de lo contrario se producirá un desbordamiento, lo que dará como resultado una excepción del programa
            if (!dis[i].visit && arc[temp][i]!=INT_MAX && (dis[temp].value + arc[temp][i]) < dis[i].value) {
                // Si el borde recién obtenido puede afectar a otros vértices para el acceso, actualice su ruta y longitud más cortas
                dis[i].value = dis[temp].value + arc[temp][i];
                dis[i].path = dis[temp].path + "-->v" + to_string(i + 1);
            }
        }
    }

}
void Graph_DG::print_path(int begin) {
    string str;
    str = "v" + to_string(begin);
    cout << "A"<<str<<"La ruta más corta del gráfico como punto de partida es:" << endl;
    for (int i = 0; i != this->vexnum; i++) {
        if(dis[i].value!=INT_MAX)
        cout << dis[i].path << "=" << dis[i].value << endl;
        else {
            cout << dis[i].path << "No hay camino más corto" << endl;
        }
    }
}
