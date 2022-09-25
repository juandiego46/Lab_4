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
    Nodo *n1 = new Nodo;
    Nodo *n2 = new Nodo;
    Nodo *n3 = new Nodo;
    Nodo *n4 = new Nodo;

    n1->setNombre("A");
    n1->setTabla("B",4);
    n1->setTabla("C",10);
    n1->setTabla("D",0);

    n2->setNombre("B");
    n2->setTabla("A",4);
    n2->setTabla("C",0);
    n2->setTabla("D",1);

    n3->setNombre("C");
    n3->setTabla("A",7);
    n3->setTabla("B",0);
    n3->setTabla("D",2);

    n4->setNombre("D");
    n4->setTabla("A",0);
    n4->setTabla("B",1);
    n4->setTabla("C",2);

    ingresar_nodo(*n1);
    ingresar_nodo(*n2);
    ingresar_nodo(*n3);
    ingresar_nodo(*n4);
}

void Red::imprimirRed()
{
    for(auto i = enrutadores.begin(); i != enrutadores.end(); i++){
        auto j = *i;
        j.imprimirTabla();
    }
}

void Red::eliminarNodo(string _nombre)
{
    int pos = 0;
    for(auto i = enrutadores.begin(); i != enrutadores.end(); i++){
        string j = i->getNombre();
        if(_nombre == j){
            enrutadores.erase(i);
        }
        else{
            pos++;
        }
    }
}

void Red::saberCostoEnvio(string partida, string destino)
{
    Nodo nPartida;
    int costoEnvio = 0;
    for(auto i = enrutadores.begin(); i != enrutadores.end(); i++){
        if(partida == i->getNombre()){
            nPartida = *i;
        }
    }
    //Verificacion si esta conectado directamente
    map<string, int> :: iterator it;
    bool ban = false;
    for(it = nPartida.getTabla().begin(); it != nPartida.getTabla().end(); it++){
        if(destino == it->first){
            costoEnvio = it->second;
            ban = true;
        }
    }
    if(ban == true & costoEnvio != 0){
        cout << "El costo del envio del enrutador " << partida << " al enrutador " << destino << " es: " << costoEnvio << endl;
    }
    else{
        cout << "El enrutador " << partida << " NO esta conectado directamente con el enrutador " << destino << endl;
    }
}

void Red::optimizacionDelEnvio()
{

}

void Red::generarRedAleatoria()
{
    int nEnrutadores = 0;
    cout << "Cuantos enrutadores va a tener su red?: "; cin >> nEnrutadores;
    vector<string> nombres; // Va a contener los nombres de todos los nodos.
    int numeroLetra = 65;
    char letra = numeroLetra;
    string _nombre(1,letra);

    for(int i = 1; i <= nEnrutadores; i++){
        string nombre(1,letra);
        nombres.push_back(nombre);
        letra++;
    }
    for(int i = 0; i < nEnrutadores; i++){
        Nodo *n = new Nodo;
        n->setNombre(nombres[i]);
        vector<string> *nombresAuxiliar = new vector<string>;
        for(auto it = nombres.begin(); it != nombres.end(); it++){
            if(*it == nombres[i]){
            }
            else{
                for(auto it2 = nombresAuxiliar->begin(); it2 != nombresAuxiliar->end(); it2++){
                        if(*it == *it2){
                            break;
                        }
                }
                nombresAuxiliar->push_back(*it);
                srand((unsigned)time(NULL));
                int _costo = rand() % 99;
                n->setTabla(*it, _costo);
            }
        }
        enrutadores.push_back(*n);
        delete nombresAuxiliar;
    }

}

void Red::redCreadaUsuario()
{
    int nEnrutadores = 0;
    cout << "Cuantos enrutadores va a tener su red?: "; cin >> nEnrutadores;
    for(int i = 0; i < nEnrutadores; i++){
        Nodo *n = new Nodo;
        string *_nombre = new string;
        cout <<"Ingresa el nombre del nodo: "; cin >> *_nombre;
        n->setNombre(*_nombre);
        cout << "A continuacion va a ingresar los nombres y costos de los enrutadores que estan conectados directamente al nodo " << *_nombre << "." << endl;
        for(int j = 0; j < (nEnrutadores-1); j++){
            string *nombreConectado = new string;
            int *_costo = new int;
            cout << "Ingrese el nombre del enrutador conectado a " << *_nombre << " : "; cin >> *nombreConectado;
            cout << "El enrutador " << *_nombre << " va a estar concetado directamente a " << *nombreConectado  << "." << endl;
            cout << "Ingrese el costo del envio: "; cin >> *_costo;
            n->setTabla(*nombreConectado,*_costo);

        }
        enrutadores.push_back(*n);
        delete _nombre;

    }
}

void Red::cambiarCostoEnvio(string nombreInicial, string nombreDestino)
{
    int nuevoCosto = 0;
    cout << "Ingrese el nuevo costo de envio: "; cin >> nuevoCosto;
    for(auto it = enrutadores.begin(); it != enrutadores.end(); it++){ // Busqueda del nodo seleccionado en el vector de enrutadores de la red.
        auto jt = *it;
        if(jt.getNombre() == nombreInicial){
            for(auto k = jt.getTabla().begin(); k != jt.getTabla().end(); k++){ // Busqueda en la tabla de enrutamiento del nodo seleccionado.
                if(k->first == nombreDestino){
                    it->cambiarCosto(nombreDestino, nuevoCosto);
                }
            }
        }
    }
    for(auto it = enrutadores.begin(); it != enrutadores.end(); it++){
        auto jt = *it;
        if(jt.getNombre() == nombreDestino){
            for(auto k = jt.getTabla().begin(); k != jt.getTabla().end(); k++){ // Busqueda en la tabla de enrutamiento del nodo seleccionado.
                if(k->first == nombreInicial){
                    it->cambiarCosto(nombreInicial, nuevoCosto);
                }
            }
        }
    }
}

void Red::saberCosto(string nombreInicial, string nombreDestino)
{
    int costo = 0;
    for(auto it = enrutadores.begin(); it != enrutadores.end(); it++){
        auto jt = *it;
        if(jt.getNombre() == nombreInicial){
            for(auto k = jt.getTabla().begin(); k != jt.getTabla().end(); k++){
                if(k->first == nombreDestino){
                    costo = k->second;
                    cout << "El costo del envio del enrutador " << nombreInicial << " hasta el enrutador " << nombreDestino << " es: " << costo << endl;
                    break;
                }
            }
        }
    }
}





Red::Red()
{

}

