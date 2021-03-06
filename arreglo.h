#ifndef ARREGLO_H
#define ARREGLO_H

#include<iostream>
using namespace std;

template<class T>
class Arreglo
{
    T *arreglo;
    size_t tam;
    size_t cont;
    const static size_t MAX = 5;
    void expandir();

    public:
        Arreglo();
        ~Arreglo();
        void insertar_inicio(const T &s);
        void insertar_final(const T &s);
        void insertar(const T &s, size_t index);
        void eliminar_inicio();
        void eliminar_final();
        void eliminar(size_t index);

        T* buscar(const T &s);
        Arreglo<T*> buscar_todos(const T &s);
        size_t size();

        T operator[](size_t p)
        {
            return arreglo[p];
        }
        friend Arreglo<T>& operator<< (Arreglo<T> &a, const T& s)
        {
            a.insertar_final(s);

            return a;
        }
};

template <class T>
Arreglo<T>::Arreglo()
{
    arreglo = new T[MAX];
    cont = 0;
    tam = MAX;
}
template <class T>
Arreglo<T>::~Arreglo()
{
    delete[] arreglo;
}
template <class T>
void Arreglo<T>::insertar_final(const T &s)
{
    if(cont == tam){
        expandir();
    }
    arreglo[cont] = s;
    cont++;
}
template <class T>
void Arreglo<T>::insertar_inicio(const T &s)
{
    if(cont == tam){
        expandir();
    }
    for(size_t i = cont; i>0;i--){
        arreglo[i] = arreglo[i-1];
    }
    arreglo[0] = s;
    cont++;
}
template <class T>
void Arreglo<T>::insertar(const T &s, size_t index)
{
    if (index >= cont)
    {
        cout << "Posición no valida" << endl;
        return;
    }

    if (cont == tam)
    {
        expandir();
    }

    for (size_t i = cont; i > index; i--)
    {
        arreglo[i] = arreglo[i - 1];
    }

    arreglo[index] = s;
    cont++;
}

template <class T>
void Arreglo<T>::eliminar_inicio()
{
    if (cont == 0){
        cout << "No hay ningún elemento para eliminar" << endl;
        return;
    }

    cont--;
    for (size_t i = 0; i < cont; i++)
    {
        arreglo[i] = arreglo[i + 1];
    }
}

template <class T>
void Arreglo<T>::eliminar_final()
{
    if (cont == 0){
        cout << "No hay ningún elemento para eliminar" << endl;
        return;
    }
    cont--;
}

template <class T>
void Arreglo<T>::eliminar(size_t index)

{
    if (cont == 0){
        cout << "No hay ningún elemento para eliminar" << endl;
        return;
    }

    if (index >= cont)
    {
        cout << "Posición no valida" << endl;
        return;
    }

    cont--;
    for (size_t i = index; i < cont; i++)
    {
        arreglo[i] = arreglo[i + 1];
    }

}
template <class T>
T* Arreglo<T>::buscar(const T& s)
{
    for(size_t i=0;i<cont;i++){
        if(s==arreglo[i]){
            return &arreglo[i];
        }
    }
    return nullptr;
}
template <class T>
Arreglo<T*> Arreglo<T>::buscar_todos(const T& s)  
{
    Arreglo<T*> ptrs;
    for(size_t i=0;i<cont;i++){
        if(s==arreglo[i]){
            ptrs.insertar_final(&arreglo[i]);
        }
    }
    return ptrs;
}
template <class T>
size_t Arreglo<T>::size()
{
    return cont;
}
template <class T>
void Arreglo<T>::expandir()
{
    T *nuevo = new T[tam+MAX];

    for(size_t i=0; i<cont;i++){
        nuevo[i] = arreglo[i];
    }
    delete[] arreglo;
    arreglo = nuevo;
    tam = tam + MAX;
}

#endif 