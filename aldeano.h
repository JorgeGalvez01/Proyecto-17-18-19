#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include <iomanip>
using namespace std;

class Aldeano
{
public:
    Aldeano() {}
    Aldeano(const string &nombre, int edad, const string genero, float salud)
    : nombre(nombre), edad(edad), genero(genero), salud(salud){}

    void setNombre(const string &nombre);
    string getNombre() const;

    void setEdad(int edad);
    int getEdad()const;

    void setGenero(const string &genero);
    string getGenero();

    void setSalud(float salud);
    float getSalud() const;

    friend ostream& operator<<(ostream &out, const Aldeano &a)
    {
        out << left;
        out << setw(15) << a.nombre;
        out << setw(6) << a.edad;
        out << setw(10) << a.genero;
        out << setw(7) << a.salud;

        return out;
    }
    friend istream& operator>> (istream &in, Aldeano &a)
    {
        cout << "Nombre: ";
        getline(cin, a.nombre);

        cout << "Edad: ";
        cin >> a.edad;

        cout << "Genero: ";
        cin >> a.genero;

        cout << "Salud: ";
        cin >> a.salud;

        return in;
    }

    bool operator<(const Aldeano &a) const
    {
        return nombre < a.getNombre();
    }

    bool operator==(const Aldeano &a)
    {
        return nombre == a.nombre;
    }

    bool operator==(const Aldeano &a) const 
    {
        return nombre == a.nombre;
    }
private:
    string nombre;
    int edad;
    string genero;
    float salud;

};

#endif