#include<iostream>
#include "arreglo.h"
#include "computadora.h"

using namespace std;

void mostrar(Arreglo<Computadora> &arreglo)
{
    for (size_t i = 0; i < arreglo.size(); i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

int main()
{
    Arreglo<Computadora> computadora;
    Computadora c01("Macbook Air","IOS",8,256);
    Computadora c02("Macbook Pro","IOS",16,128);
    Computadora c03("Macbook Air","IOS",8,256);
    Computadora c04("iMac","IOS",8,512);
    Computadora c05("Macbook Air","IOS",8,256);

    computadora << c01 << c02 << c03 << c04 <<c05;
    mostrar(computadora);

    Computadora Bc = Computadora();
    Bc.setNombreEquipo("Macbook Air");

    cout << endl << "Buscando:" << endl;
    cout << Bc << endl;

    Computadora *ptr = computadora.buscar(Bc);
    if (ptr != nullptr)
    {
        cout << endl << "Econtrado:" << endl;
        cout << *ptr << " ";
        cout << endl;
    }else
    {
        cout << endl << "No encontrado" << endl;
    }
    cout << endl << "Buscar todas:" << endl;
    Computadora BTC = Computadora("iMac", "IOS", 8, 512);
    cout << BTC << endl;

    Arreglo<Computadora *> ptrs = computadora.buscar_todos(BTC);
    if (ptrs.size() > 0)
    {
        cout << endl << "Econtrado:" << endl;
        for (size_t i = 0; i < ptrs.size(); i++)
        {
            Computadora *c = ptrs[i];
            cout << *c << endl;
        }
    }
    else
    {
        cout << "No existen coincidencias" << endl;
    }

    return 0;

    
    /*Arreglo<string> arreglo;
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

    string *s = arreglo.buscar("T");
    cout << s << " " << *s << endl;
    *s = "S";
    mostrar(arreglo);*/
}