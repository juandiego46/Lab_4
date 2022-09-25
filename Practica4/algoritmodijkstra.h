#ifndef ALGORITMODIJKSTRA_H
#define ALGORITMODIJKSTRA_H

#include<iostream>
#include<string>

using namespace std;



class AlgoritmoDijkstra
{
    /* Autor: Willam * /
    // Tiempo de finalización del programa: 2017/3/8
    // Si tiene alguna pregunta, comuníquese con: 2930526477@qq.com
    // Intenta escribir el programa perfecto
    #pragma once
    // # pragma una vez es un pragma C / C ++ de uso común,
    // Mientras este pragma se agregue al comienzo del archivo de encabezado,
    // Puede asegurarse de que el archivo de encabezado solo se compila una vez.

    //Este programa utiliza el algoritmo de Dijkstra para resolver el problema del camino más corto.
     Matriz de adyacencia utilizada para almacenar gráfico
    */
    // Registre la información de la ruta más corta desde el punto de partida hasta cada vértice

    struct Dis {
        string path;
        int value;
        bool visit;
        Dis() {
            visit = false;
            value = 0;
            path = "";
        }
    };
    class Graph_DG {
    private:
        int vexnum;   // Número de vértices del gráfico.
        int edge;     // Número de aristas del gráfico
        int **arc;   // matriz de adyacencia
        Dis * dis;   // Registre la información de la ruta más corta de cada vértice
    public:
        // constructor
        Graph_DG(int vexnum, int edge);
        // Destructor
        ~Graph_DG();
        // juzga si la información del borde que ingresamos es legal cada vez
        // Los vértices están numerados de 1
        bool check_edge_value(int start, int end, int weight);
        // Crear gráfico
        void createGraph();
        // imprimir matriz de adyacencia
        void print();
        // Encuentra el camino más corto
        void Dijkstra(int begin);
        // imprime el camino más corto
        void print_path(int);
    };
};

#endif // ALGORITMODIJKSTRA_H
