#include "civilizacion.h"

Aldeano capturar()
{
        Aldeano a;

        string nombre, genero;
        int edad;
        float salud;

        cout << "Nombre: ";cin.ignore();
        getline(cin, nombre);
        a.setNombre(nombre);

        cout << "Edad: ";
        cin >> edad; cin.ignore();
        a.setEdad(edad);

        cout << "Genero: ";
        getline(cin, genero);
        a.setGenero(genero);

        cout << "Salud: ";
        cin >> salud;
        a.setSalud(salud);

        return a;
}

void menu(Civilizacion &c)
{
    size_t opcion;
    while (true)
    {
        cout << "1) Agregar aldeano" << endl;
        cout << "2) Eliminar aldeano" << endl;
        cout << "3) Clasificar aldeanos" << endl;
        cout << "4) Buscar aldeano" << endl;
        cout << "5) Modificar aldeano" << endl;
        cout << "6) Mostrar aldeanos" << endl;
        cout << "7) Recuperar aldeanos" << endl;
        cout << "0) Salir" << endl;
        cin >> opcion;
        if (opcion == 1)
        {
            while(true)
            {
                Aldeano a;
                cout << "1) Agregar aldeano al inicio" << endl;
                cout << "2) Agregar aldeano al final" << endl;
                cout << "0) salir" << endl;
                cin >> opcion;
                if (opcion == 1)
                {
                    c.agregarInicio(capturar());
                }
                else if (opcion == 2)
                {
                    c.agregarFinal(capturar());
                }
                else if (opcion == 0)
                {
                    break;
                }
            }
        }
        else if (opcion == 2)
        {
            while (true)
            {
                cout << "1) Eliminar por nombre" << endl;
                cout << "2) Eliminar por salud" << endl;
                cout << "3) Eliminar por edad" << endl;
                cout << "0) salir" << endl;
                cin >> opcion;
                if (opcion == 1)
                {
                    string nombre;
                    cout <<"Nombre: ";
                    cin.ignore();
                    getline(cin, nombre);
                    c.eliminarNombre(nombre);
                    break;
                }
                else if (opcion == 2)
                {
                    size_t salud;
                    cout << "Salud:";
                    cin >> salud; cin.ignore();
                    c.eliminarSalud(salud);
                    break;
                }
                else if (opcion == 3)
                {
                    c.eliminarEdad();
                    break;
                }  
                else if(opcion == 0)
                {
                        break;
                } 
            }
        }
        else if (opcion == 3)
        {
            cout << "1) Clasificar aldeano por nombre" << endl;
            cout << "2) Clasificar aldeano por edad" << endl;
            cout << "3) Clasificar aldeano por salud" << endl;
            cout << "0) Salir" << endl;
            cin >> opcion;
            if (opcion == 1)
            {
                c.ordenarNombre();
            }
            else if (opcion == 2)
            {
                c.ordenarEdad();
            }
            else if (opcion == 3)
            {
                c.ordenarSalud();
            }
            else if (opcion == 0)
            {
                break;
            }
        }
        else if (opcion == 4)
        {       
            Aldeano *ptr = c.buscar(capturar());
            if(ptr == nullptr)
            {
                cout << "Aldeano no encontrado" << endl;
            }
            else
            {  
                cout << *ptr << endl;
            }
        }
        else if (opcion == 5)
        {
            Aldeano a;
            cin.ignore();
            cin >> a;
            Aldeano *ptr = c.buscar(a);
            if(ptr == nullptr)
            {
                    cout << "No encontrado" << endl;
            }
            else
            {
                    cout << *ptr << endl;
            }
            while(ptr != nullptr)
            {
                    cout << "1) Modificar nombre" << endl;
                    cout << "2) Modificar edad" << endl;
                    cout << "3) Modificar genero" << endl;
                    cout << "4) Modificar salud" << endl;
                    cout << "0) Salir" << endl;

                    cin >> opcion;

                    if (opcion == 1)
                    {
                            string aux;
                            
                            cout << "Ingresa el nuevo nombre: ";
                            cin >> aux;
                            c.modificarNombre(a, aux);
                            break; 
                    }
                    else if (opcion == 2)
                    {
                            int aux;
                            cout << "Ingresa la nueva edad: ";
                            cin >> aux;
                            c.modificarEdad(a, aux);
                    }
                    else if (opcion == 3)
                    {
                            string aux;
                            cout << "Ingresa el nuevo genero: ";
                            cin >> aux;
                            c.modificarGenero(a, aux);
                    }
                    else if (opcion == 4)
                    {
                            float aux;
                            cout << "Ingresa la nueva salud: ";
                            cin >> aux;
                            c.modificarSalud(a, aux);
                    }
                    else if (opcion == 0)
                    {
                            break;
                    }
            }
        }
        else if (opcion == 6)
        {
                c.print();
        }
        else if (opcion == 7)
        {
            c.recuperarAldeanos();
        }
        
        else if (opcion == 0)
        {
                break;
        }
    }
    
}