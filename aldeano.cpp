#include "aldeano.h"

void Aldeano::setNombre(const string &nombre)
{
    this -> nombre = nombre;
}
string Aldeano::getNombre() const
{
    return nombre;
}

void Aldeano::setEdad(int edad)
{
    this -> edad = edad;
}
int Aldeano::getEdad() const
{
    return edad;
}

void Aldeano::setGenero(const string &genero)
{
    this -> genero = genero;
}
string Aldeano::getGenero()
{
    return genero;
}

void Aldeano::setSalud(float salud)
{
    this -> salud = salud;
}
float Aldeano::getSalud() const
{
    return salud;
}

