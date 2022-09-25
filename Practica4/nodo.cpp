#include "nodo.h"
#include <map>
#include <vector>


map<string, int> Nodo::getTabla()
{
    return tabla;
}

void Nodo::setTabla(string _nombre, int _costo)
{
    tabla.insert(make_pair(_nombre, _costo));
    //tabla = newTabla;
}



void Nodo::cambiarCosto(string nombre, int nuevoCosto)
{
    for(auto i = tabla.begin(); i != tabla.end(); i++){
        if(nombre == i->first){
            i->second = nuevoCosto;
        }
    }
}



void Nodo::imprimirTabla()
{
    cout << "Nodo " << nombre << endl;
    cout << "Conec" << "|" << "Costo" << endl;
    for(auto i = tabla.begin(); i != tabla.end(); i++){
        cout << i->first << "    |    " << i->second << endl;
    }

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



