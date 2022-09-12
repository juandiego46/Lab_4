#include "red.h"
#include "nodo.h"

vector<Nodo> Red::getEnrutadores()
{
    return enrutadores;
}

void Red::setEnrutadores(vector<Nodo> newEnrutadores)
{
    enrutadores = newEnrutadores;
}

void Red::ingresar_nodo(Nodo n1)
{
    enrutadores.push_back(n1);
}

void Red::porDefecto()
{
    Nodo n1;
    n1.setNombre("A");
    Nodo n2;
    n2.setNombre("B");
    Nodo n3;
    n3.setNombre("C");
    Nodo n4;
    n4.setNombre("D");

    map<string, int> tableA;
    tableA.insert(make_pair("B", 4));
    tableA.insert(make_pair("C", 10));
    n1.setTabla(tableA);

    map<string, int> tableB;
    tableB.insert(make_pair("A", 4));
    tableB.insert(make_pair("D", 1));
    n2.setTabla(tableB);

    map<string, int> tableC;
    tableC.insert(make_pair("A", 10));
    tableC.insert(make_pair("D", 2));
    n3.setTabla(tableC);

    map<string, int> tableD;
    tableD.insert(make_pair("C", 2));
    tableD.insert(make_pair("B", 1));
    n4.setTabla(tableD);

}




Red::Red()
{

}

