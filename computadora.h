#ifndef COMPUTADORA_H
#define COMPUTADORA_H
#include<iostream>
#include<iomanip>
using namespace std;

class Computadora{
    string sistemaOp;
    string nombreEquipo;
    int memoriaRam;
    int memoriaSSD;

    public:
    Computadora();
    Computadora(const string &nombreEquipo,
                const string &sistemaOp,
                int memoriaRam,
                int memoriaSSD);
    void setNombreEquipo(const string &v);
    string getNombreEquipo();
    void setSistemaOp(const string &v);
    string getSistemaOp();
    void setMemoriaRam(int v);
    int getMemoriaRam();
    void setMemoriaSSD(int v);
    int getMemoriaSSD();

    friend ostream& operator<<(ostream &out, const Computadora &c)
    {
        out << left;
        out << setw(15) << c.nombreEquipo;
        out << setw(18) <<  c.sistemaOp;
        out << setw(15) << c.memoriaRam;
        out << setw(15) << c.memoriaSSD;
        out << endl;

        return out;
    }

    friend istream& operator>>(istream &in,  Computadora &c)
    {
        cout << "Nombre: "; 
        getline(cin, c.nombreEquipo);
        cout << "Sistema Operativo: ";
        getline(cin, c.sistemaOp);
        cout << "Memoria Ram: ";
        cin >> c.memoriaRam;
        cout << "Memoria SSD: ";
        cin >> c.memoriaSSD;

        return in;
    }
    bool operator==(const Computadora &c)
    {
        return nombreEquipo == c.nombreEquipo;
    }
    bool operator==(const Computadora &c) const
    {
        return nombreEquipo == c.nombreEquipo;
    }
};

#endif