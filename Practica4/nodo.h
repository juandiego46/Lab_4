#ifndef NODO_H
#define NODO_H
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Nodo
{
private:
    string nombre;
    map<string, int> tabla;

public:
    Nodo();
    Nodo(string _nombre, map<string, int> _tabla);

    string getNombre();
    void setNombre(string _nombre);

    map<string, int> getTabla();
    void setTabla(string _nombre, int _costo);

    void cambiarCosto(string nombre, int nuevoCosto);

    void imprimirTabla();


};





#endif // NODO_H
