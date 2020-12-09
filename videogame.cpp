#include "videogame.h"
#include <fstream>
#include <algorithm>


VideoGame::VideoGame(const string &usuario)
{
    this -> usuario = usuario;
}

void VideoGame::setUsuario(const string &v)
{
    usuario = v;
}
string VideoGame::getUsuario()
{
    return usuario;
}

void VideoGame::agregarCivilizacion(const Civilizacion &c)
{
    civilizaciones.push_back(c);
}

void VideoGame::insertarCivilizacion(size_t posicion, const Civilizacion &c)
{
    civilizaciones.insert(civilizaciones.begin() + posicion, c);
}

size_t VideoGame::size()
{
    return civilizaciones.size();
}

void VideoGame::crearCivilizaciones(const Civilizacion &c, size_t cantidad)
{
    civilizaciones = vector <Civilizacion> (cantidad, c);
}

void VideoGame::primeraCivilizacion()
{
    if (civilizaciones.size() > 0)
    {
    cout << left;
    cout << setw(10) << "Nombre";
    cout << setw(5) << "x";
    cout << setw(5) << "y";
    cout << setw(15) << "Puntuacion";
    cout << endl;

    Civilizacion &c = civilizaciones.front();
    cout << c << endl;
    }
    else 
    {
        cout << "No hay civilizaciones registradas" << endl;
    }
}

void VideoGame::ultimaCivilizacion()
{
    if (civilizaciones.size() > 0)
    {
        cout << left;
        cout << setw(10) << "Nombre";
        cout << setw(5) << "x";
        cout << setw(5) << "y";
        cout << setw(15) << "Puntuacion";
        cout << endl;

        Civilizacion &c = civilizaciones.back();
        cout << c << endl;
    }
    else
    {
        cout << "No hay civilizaciones registradas" << endl;
    }   
}

void VideoGame::ordenarNombre()
{
    sort(civilizaciones.begin(), civilizaciones.end());
}

void VideoGame::ordenarX()
{
    sort(civilizaciones.begin(), civilizaciones.end(), 
    [] (Civilizacion c1, Civilizacion c2) {return c1.getX() > c2.getX();});
}


void VideoGame::ordenarY()
{
    sort(civilizaciones.begin(), civilizaciones.end(),
    [] (Civilizacion c1, Civilizacion c2) {return c1.getY() > c2.getY();});
}

void VideoGame::ordenarPuntuacion()
{
    sort(civilizaciones.begin(), civilizaciones.end(),
    [] (Civilizacion c1, Civilizacion c2) {return c1.getPuntuacion() > c2.getPuntuacion();});
}

void VideoGame::eliminar(const string &nombre)
{
    for (auto it = civilizaciones.begin(); it != civilizaciones.end(); it++)
    {
        Civilizacion &c = *it;

        if (nombre == c.getNombre())
        {
            civilizaciones.erase(it);
            break;
        }
        else 
        {
            cout << "Civilizacion no encontrada" << endl;
        }
    }
}

Civilizacion* VideoGame::buscar(const Civilizacion &c)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);
    if (it == civilizaciones.end())
    {
        return nullptr;
    }
    else
    {
        return &(*it);
    }
}

void VideoGame::modificar(const Civilizacion &c ,const string &aux)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);
    {
        Civilizacion &c = *it;
        c.setNombre(aux);
    }
}

void VideoGame::modificarX(const Civilizacion &c, int &aux)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);
    {
        Civilizacion &c = *it;
        c.setX(aux);
    }
}

void VideoGame::modificarY(const Civilizacion &c, int &aux)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);
    {
        Civilizacion &c = *it;
        c.setY(aux);
    }
}

void VideoGame::modificarPuntuacion(const Civilizacion &c, float &aux)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);
    {
        Civilizacion &c = *it;
        c.setPuntuacion(aux);
    }
}

void VideoGame::total()
{
    cout << left;
    cout << setw(10) << "Nombre";
    cout << setw(5) << "x";
    cout << setw(5) << "y";
    cout << setw(15) << "Puntuacion";
    cout << endl;

    for (size_t i = 0; i < civilizaciones.size(); i++)
    {
        Civilizacion &c = civilizaciones[i];
        cout << c << endl;
    }
}

void VideoGame::respaldar()
{
    ofstream archivo("civilizaciones.txt");

    for (int i = 0; i < civilizaciones.size(); ++i) 
    {
        Civilizacion &c = civilizaciones[i];
        archivo << c.getNombre() << endl;
        c.respaldarAldeanos();
    }
    archivo.close();
}

void VideoGame::recuperar()
{
    ifstream archivo("civilizaciones.txt");
    if (archivo.is_open())
    {
        Civilizacion c;
        string temp;

        while (true)
        {
            getline(archivo, temp);
            if(archivo.eof())
            {
                break;  
            }
            c.setNombre(temp);
            agregarCivilizacion(c);
        }
    }
    archivo.close();
}

