#include <iostream>
#include "nodo.h"
#include "red.h"
#include <vector>
#include <map>
#include <list>

using namespace std;

int main()
{
    Red r1;
    Red r2;
    r2.porDefecto();

    map<string, int> table;
    table.insert(make_pair("B",180));
    table.insert(make_pair("C",130));
    table.insert(make_pair("D",40));

    Nodo n1("A", table);
    n1.imprimirTabla();
    r1.ingresar_nodo(n1);


    return 0;
}
