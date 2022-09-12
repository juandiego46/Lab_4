#include "nodo.h"
#include <map>
#include <vector>


map<string, int> Nodo::getTabla()
{
    return tabla;
}

void Nodo::setTabla(map<string, int> newTabla)
{
    tabla = newTabla;
}



void Nodo::imprimirTabla()
{
    for(auto i = tabla.begin(); i != tabla.end(); i++){
        cout << "Nodo: "<< getNombre() << " Conectado: " << i->first << " Costo: " << i->second << "|";
    }
    cout << endl;
}



string Nodo::getNombre()
{
    return nombre;
}

void Nodo::setNombre(string _nombre)
{
    nombre = _nombre;
}

Nodo::Nodo()
{

}

Nodo::Nodo(string _nombre, map<string, int> _tabla)
{
     nombre = _nombre;
     tabla = _tabla;
}



