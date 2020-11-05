#include "computadora.h"

Computadora::Computadora(){
    
}
Computadora::Computadora(const string &nombreEquipo, const string &sistemaOp, int memoriaRam, int memoriaSSD)
{
    this->nombreEquipo = nombreEquipo;
    this->sistemaOp = sistemaOp;
    this->memoriaRam = memoriaRam;
    this->memoriaSSD = memoriaSSD;
}

void Computadora::setNombreEquipo(const string &v)
{
    nombreEquipo = v;
}
string Computadora::getNombreEquipo()
{
    return nombreEquipo;
}
void Computadora::setSistemaOp(const string &v)
{
    sistemaOp = v;
}
string Computadora::getSistemaOp()
{
    return sistemaOp;
}
void Computadora::setMemoriaRam(int v)
{
    memoriaRam = v;
}
int Computadora::getMemoriaRam()
{
    return memoriaRam;
}
void Computadora::setMemoriaSSD(int v)
{
    memoriaSSD = v;
}
int Computadora::getMemoriaSSD()
{
    return memoriaSSD;
}
