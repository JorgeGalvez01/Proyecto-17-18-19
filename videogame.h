#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"
#include <vector>

class VideoGame
{
private:
    string usuario;
    vector <Civilizacion> civilizaciones;

public:
    VideoGame(){}
    VideoGame(const string &usuario);

    void setUsuario(const string &v);
    string getUsuario();
    void agregarCivilizacion(const Civilizacion &c);
    void insertarCivilizacion(size_t posicion, const Civilizacion &c);
    size_t size();
    void crearCivilizaciones(const Civilizacion &c, size_t cantidad);
    void primeraCivilizacion();
    void ultimaCivilizacion();

    void ordenarNombre();
    void ordenarX();
    void ordenarY();
    void ordenarPuntuacion();

    void eliminar(const string &nombre);
    Civilizacion* buscar(const Civilizacion &c);

    void modificar(const Civilizacion &c, const string &aux);
    void modificarX(const Civilizacion &c, int &aux);
    void modificarY(const Civilizacion &c, int &aux);
    void modificarPuntuacion(const Civilizacion &c, float &aux);

    void total();

    void respaldar();
    void recuperar();
    //friend VideoGame& operator <<(VideoGame &v, const Civilizacion &c)
    //{
    //v.agregarCivilizacion(c);
    //    return v;
    //}
};

#endif