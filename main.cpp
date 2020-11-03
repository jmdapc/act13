#include<iostream>
#include "arreglo.h"

using namespace std;

void mostrar(Arreglo<string> &arreglo)
{
    for (size_t i = 0; i < arreglo.size(); i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

int main()
{
    Arreglo<string> arreglo;
    arreglo.insertar_final("T");
    arreglo.insertar_final("O");
    arreglo.insertar_inicio("A");
    arreglo.insertar_inicio("P");
    mostrar(arreglo);

    arreglo.insertar("R",2);
    mostrar(arreglo);

    arreglo.eliminar_inicio();
    arreglo.eliminar_final();
    arreglo.eliminar(1);
    mostrar(arreglo);
}