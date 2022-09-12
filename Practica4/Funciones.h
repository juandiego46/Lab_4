#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

class nodo{
private:
    string nombre;
public:
    nodo(string _nombre){
        nombre = _nombre;
    }
    vector <string> conecDirecto;
    vector <int> costo;
    const string &getNombre() const;
    void setNombre(const string &newNombre);
    const vector<string> &getConecDirecto() const;
    void setConecDirecto(const vector<string>);
    const vector<int> &getCosto() const;
    void setCosto(const vector<int> &newCosto);
    void agregarConectados(string _nombre);
};


#endif // FUNCIONES_H
