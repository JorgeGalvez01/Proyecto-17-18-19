#include "civilizacion.h"

#include <iostream>
#include <fstream>

using namespace std;

Civilizacion::Civilizacion(const string &nombre, int x, int y, float puntuacion)
{
    this->nombre = nombre;
    this->x = x;
    this->y = y;
    this->puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string &valor)
{
    nombre = valor;
}
string Civilizacion::getNombre()
{
    return nombre;
}

void Civilizacion::setX(int valor)
{
    x = valor;
}
int Civilizacion::getX()
{
    return x;
}

void Civilizacion::setY(int valor)
{
    y = valor;
}
int Civilizacion::getY()
{
    return y;
}

void Civilizacion::setPuntuacion(float valor)
{
    puntuacion = valor;
}
float Civilizacion::getPuntuacion()
{
    return puntuacion;
}

void Civilizacion::agregarFinal(const Aldeano &a)
{
    aldeanos.push_back(a);
    setPuntuacion(getPuntuacion() + 100);
}

void Civilizacion::agregarInicio(const Aldeano &a)
{
    aldeanos.push_front(a);
    setPuntuacion(getPuntuacion() + 100);
}

void Civilizacion::print()
{
    cout << left;
    cout << setw(15) << "Nombre";
    cout << setw(6) << "Edad";
    cout << setw(8) << "Genero";
    cout << setw(7) << "Salud";
    cout << endl;
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++)
    {
        cout << *it << endl;
    }
}

void Civilizacion::eliminarNombre(const string &nombre)
{
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++)
    {
        Aldeano &a = *it;
        if (nombre == a.getNombre())
        {
            aldeanos.erase(it);
            break;
        }
    }
}



void Civilizacion::eliminarSalud(float salud)
{
    aldeanos.remove_if([salud](const Aldeano &a) 
    {
        return a.getSalud() < salud;
    });
}

bool comparador(const Aldeano &a)
{
    return a.getEdad() >= 60;
}
void Civilizacion::eliminarEdad()
{
    aldeanos.remove_if(comparador);
}

void Civilizacion::ordenarNombre()
{
    aldeanos.sort();
}

void Civilizacion::ordenarEdad()
{
    aldeanos.sort([] (const  Aldeano &a1, const Aldeano &a2) 
    {
        return a1.getEdad() > a2.getEdad();
    });
}

void Civilizacion::ordenarSalud()
{
    aldeanos.sort([] (const  Aldeano &a1, const Aldeano &a2)
    {
        return a1.getSalud() > a2.getSalud();
    });
}

Aldeano* Civilizacion::buscar(const Aldeano &a)
{
    auto it = find(aldeanos.begin(), aldeanos.end(), a);
    if (it == aldeanos.end())
    {
        return nullptr;
    }
    else
    {
        return &(*it);
    }
}

void Civilizacion::modificarNombre(const Aldeano &a, const string &aux)
{
    auto it = find(aldeanos.begin(), aldeanos.end(), a);
    {
        Aldeano &a = *it;
        a.setNombre(aux);
    }
}

void Civilizacion::modificarEdad(const Aldeano &a, int &aux)
{
    auto it = find(aldeanos.begin(), aldeanos.end(), a);
    {
        Aldeano &a = *it;
        a.setEdad(aux);
    }
}

void Civilizacion::modificarGenero(const Aldeano &a,const string &aux)
{
    auto it = find(aldeanos.begin(), aldeanos.end(), a);
    {
        Aldeano &a = *it;
        a.setGenero(aux);
    }
}

void Civilizacion::modificarSalud(const Aldeano &a, float &aux)
{
    auto it = find(aldeanos.begin(), aldeanos.end(), a);
    {
        Aldeano a = *it;
        a.setSalud(aux);
    }
}

void Civilizacion::respaldarAldeanos()
{
    ofstream archivo(getNombre() + ".txt");

    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++)
    {
        Aldeano &a = *it; 
        archivo << a.getNombre() << endl;
        archivo << a.getEdad()   << endl;
        archivo << a.getGenero() << endl;
        archivo << a.getSalud()  << endl;
    }
    archivo.close();
}

void Civilizacion::recuperarAldeanos()
{
    ifstream archivo(getNombre() + ".txt");
    if (archivo.is_open())
    {
        Aldeano a;
        string temp;
        int edad;
        float salud;

        while (true)
        {
            getline(archivo, temp);
            if(archivo.eof())
            {
                break;  
            }
            a.setNombre(temp);

            getline(archivo, temp);
            edad = stoi(temp);
            a.setEdad(edad);

            getline(archivo, temp);
            a.setGenero(temp);

            getline(archivo, temp);
            salud = stof(temp);
            a.setSalud(salud);
            
            agregarFinal(a);
        }
    }
    archivo.close();
}