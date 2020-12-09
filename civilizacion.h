#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>
#include "aldeano.h"
#include <list>
#include <algorithm>

using namespace std;

class Civilizacion
{
private:
    string nombre;
    int x;
    int y;
    float puntuacion;

    list <Aldeano> aldeanos;

public:
    Civilizacion(){}
    Civilizacion(const string &nombre, int x, int y, float puntuacion);

    void setNombre(const string &nombre);
    string getNombre();

    void setX(int x);
    int getX();

    void setY(int y);
    int getY();
    
    void setPuntuacion(float puntuacion);
    float getPuntuacion();

    void agregarFinal(const Aldeano &a);
    void agregarInicio(const Aldeano &a);
    void print();

    void eliminarNombre(const string &nombre);
    void eliminarSalud(float salud);
    void eliminarEdad();

    void ordenarNombre();
    void ordenarEdad();
    void ordenarSalud();

    Aldeano* buscar(const Aldeano &a);

    void modificarNombre(const Aldeano &a, const string &aux);
    void modificarEdad(const Aldeano &a, int &aux);
    void modificarGenero(const Aldeano &a, const string &aux);
    void modificarSalud(const Aldeano &a, float &aux);

    void respaldarAldeanos();
    void recuperarAldeanos();

    friend ostream& operator<<(ostream &out, Civilizacion const &c)
    {
        out << left;
        out << setw(10) << c.nombre;
        out << setw(5) << c.x;
        out << setw(5) << c.y;
        out << setw(15) << c.puntuacion;

        return out;
    }
    friend istream& operator>>(istream &in, Civilizacion &c)
    {
        cout << "Nombre: ";
        getline(cin, c.nombre);

        cout << "Posicion x: ";
        cin >> c.x;

        cout << "Posicion y: ";
        cin >> c.y;

        cout << "Puntuacion: ";
        cin >> c.puntuacion;

        return in;
    }

    bool operator<(const Civilizacion& c) 
    {
        return nombre > c.nombre;
    }

    bool operator<(const Civilizacion& c) const
    {
        return nombre > c.nombre;
    }

    bool operator==(const Civilizacion& c)
    {
        return nombre == c.nombre;
    }

    bool operator==(const Civilizacion& c) const 
    {
        return nombre == c.nombre;
    }
};


#endif