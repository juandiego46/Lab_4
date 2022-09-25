#ifndef RED_H
#define RED_H
#include "nodo.h"
#include <ctime>

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

    void imprimirRed();

    void eliminarNodo(string _nombre);

    void saberCostoEnvio(string partida, string destino);

    void optimizacionDelEnvio();

    void generarRedAleatoria();

    void redCreadaUsuario();

    void cambiarCostoEnvio(string inicial, string destino);

    void saberCosto(string nombreInicial, string nombreDestino);
};

#endif // RED_H
