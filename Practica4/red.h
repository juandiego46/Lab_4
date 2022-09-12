#ifndef RED_H
#define RED_H
#include "nodo.h"

class Red
{
private:
    vector<Nodo> enrutadores;

public:
    Red();

    vector<Nodo> getEnrutadores();
    void setEnrutadores(vector<Nodo> newEnrutadores);

    void ingresar_nodo(Nodo n1);

    void porDefecto();



};

#endif // RED_H
