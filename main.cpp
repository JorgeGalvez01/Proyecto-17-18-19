#include <iostream>
#include "videogame.h"
#include "menuCivilizacion.h"

using namespace std;

int main()
{

    VideoGame v;
    int opcion;

    while (true)
    {
        cout << "1) Nombre de usuario" << endl;
        cout << "2) Agregar civilizacion" << endl;
        cout << "3) Insertar civilizacion" << endl;
        cout << "4) Crear civilizaciones" << endl;
        cout << "5) Primera civilizacion" << endl;
        cout << "6) Ultima civilizacion" << endl;
        cout << "7) Ordenar" << endl;
        cout << "8) Eliminar" << endl;
        cout << "9) Buscar" << endl; 
        cout << "10) Modificar" << endl;
        cout << "11) Resumen" << endl;
        cout << "12) Respaldar" << endl;
        cout << "13) Recuperar civilizaciones" << endl;
        cout << "0) Salir" << endl;

        cin >> opcion;
        cin.sync();

        if (opcion == 1)
        {
            string usuario;

            cout << "Usuario: ";
            cin >> usuario;
            v.setUsuario(usuario);

            cout << "Bienvenido " << v.getUsuario() << endl;
        }
        else if (opcion == 2)
        {
            Civilizacion c;
            cin >> c;
            v.agregarCivilizacion(c);
            cin.ignore();
        }
        else if (opcion == 3)
        {
            Civilizacion c;
            cin >> c;

            size_t posicion;
            cout << "Posicion: " << endl;
            cin >> posicion;

            if (posicion >= v.size())
            {
                cout << "posicion invalida";
            }
            else
            {
                v.insertarCivilizacion(posicion, c);
            }
        }
        else if (opcion == 4)
        {
            Civilizacion c;
            cin >> c;

            size_t cantidad;
            cout << "Cantidad: ";
            cin >> cantidad; cin.ignore();

            v.crearCivilizaciones(c, cantidad);
        }
        else if (opcion == 5)
        {
            v.primeraCivilizacion();
        }
        else if (opcion == 6)
        {
            v.ultimaCivilizacion();
        }

        else if (opcion == 7)
        {
            while (opcion != 0)
            {
                size_t opcion;
                cout << "1) Ordenar por nombre" << endl;
                cout << "2) Ordenar por posicion en X" << endl;
                cout << "3) Ordenar por posicion en Y" << endl;
                cout << "4) Ordenar por puntucion" << endl;
                cout << "0) Salir" << endl; 

                cin >> opcion;

                if (opcion == 1)
                {
                    v.ordenarNombre();
                    break;
                }
                else if (opcion == 2)
                {
                    v.ordenarX();
                    break;
                }
                else if (opcion == 3)
                {
                    v.ordenarY();
                    break;
                }
                else if (opcion == 4)
                {
                    v.ordenarPuntuacion();
                    break;
                }
                else if (opcion == 0)
                {
                    break;
                }
            }
        }

        else if (opcion == 8)
        {
            string nombre;

            cout << "Nombre de la civilizacion a eliminar: ";
            cin >> nombre;

            v.eliminar(nombre);  
        }

        else if (opcion == 9)
        {
            Civilizacion c;
            cin >> c;

            Civilizacion *ptr = v.buscar(c);
            if(ptr == nullptr)
            {
                cout << "Civilizacion no encontrada" << endl;
            }
            else
            {  
                cout << *ptr << endl;
                menu(*ptr);
            }
        }
        else if (opcion == 10)
        {
            Civilizacion c;
            cin >> c;

            Civilizacion *ptr = v.buscar(c);
            if(ptr == nullptr)
            {
                cout << "No encontrado" << endl;
            }
            else
            {
                cout << *ptr << endl;
            
                size_t opcion; 
                while(ptr != nullptr)
                {
                    cout << "1) Modificar nombre" << endl;
                    cout << "2) Modificar posicion en x" << endl;
                    cout << "3) Modificar posicion en y" << endl;
                    cout << "4) Modificar puntuacion" << endl;
                    cout << "0) Salir" << endl;

                    cin >> opcion;

                    if (opcion == 1)
                    {
                        string aux;
                        
                        cout << "Ingresa el nuevo nombre: ";
                        cin >> aux;
                        v.modificar(c, aux);
                        break; 
                    }
                    else if (opcion == 2)
                    {
                        int aux;
                        cout << "Ingresa la nueva posicion X: ";
                        cin >> aux;
                        v.modificarX(c, aux);

                        break;
                    }
                    else if (opcion == 3)
                    {
                        int aux;
                        cout << "Ingresa la nueva posicion Y: ";
                        cin >> aux;
                        v.modificarY(c, aux);
                        break;
                    }
                    else if (opcion == 4)
                    {
                        float aux;
                        cout << "Ingresa la nueva puntuacion: ";
                        cin >> aux;
                        v.modificarPuntuacion(c, aux);
                        break;
                    }
                    else if (opcion == 0)
                    {
                        break;
                    }
                }
            }
        }
        
        else if (opcion == 11)
        {
            cout << "Usuario: " << v.getUsuario() << endl;
            v.total();
        }
        else if(opcion == 12)
        {
            v.respaldar();
        }
        else if (opcion == 13)
        {
            v.recuperar();
        }
        else if (opcion == 0)
        {
            break;
        }
        
    }
    return 0;
}