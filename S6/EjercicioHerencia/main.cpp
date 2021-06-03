#include<iostream>
#include<string>
#include"AirBnB.h"
#include"Hoteles.h"
#include"Apartamento.h"

using namespace std;

void menu();

int main()
{
    menu();
}

void menu()
{
    int opt;
    string color,lugar;
    char comida='f';
    int precio, tiempo, personas , cuartos;
    Hoteles *h1;
    Apartamento *ap1;
    AirBnB *ab1;
    do
    {
        system("cls");
        cout<<"===MENU===\n";
        cout<<"1. Hospedarse en Hotel\n";
        cout<<"2. Hospedarse en AirBnB\n";
        cout<<"3. Hospedarse en Apartamento\n";
        cout<<"4. Salir\n";
        cout<<"Digite una opcion: ";
        cin>>opt;

        switch (opt)
        {
        case 1:
            system("cls");
            cout<<"\nDigite los Datos: \n";
            cin.ignore();
            cout<<"Lugar: ";
            getline(cin,lugar);
            cout<<"Color: ";
            getline(cin,color);
            cout<<"Precio: ";
            cin>>precio;
            cout<<"Comida (s/n): ";
            cin>>comida;
            if(comida == 's')
            {
               h1 = new Hoteles(lugar,color,precio,true) ;
               system("cls");
               h1->mostrarDatos();
               system("pause");
            }
            else
            {
                h1 = new Hoteles(lugar,color,precio,false) ;
                system("cls");
                h1->mostrarDatos();
                system("pause");
            }
            break;
        case 2:
            system("cls");
            cout<<"\nDigite los Datos: \n";
            cin.ignore();
            cout<<"Lugar: ";
            getline(cin,lugar);
            cout<<"Color: ";
            getline(cin,color);
            cout<<"Precio: ";
            cin>>precio;
            cout<<"Personas: ";
            cin>>personas;
            cout<<"Tiempo: ";
            cin>>tiempo;
            ab1 = new AirBnB(lugar,color,precio,personas,tiempo);
            system("cls");
            ab1->mostrarDatos();
            system("pause");
            break;
        case 3:
            system("cls");
            cout<<"\nDigite los Datos: \n";
            cout<<"Lugar: ";
            cin.ignore();
            getline(cin,lugar);
            cout<<"Color: ";
            getline(cin,color);
            cout<<"Precio: ";
            cin>>precio;
            cout<<"Tiempo: ";
            cin>>tiempo;
            cout<<"Habitaciones: ";
            cin>>cuartos;
            ap1 = new Apartamento(lugar,color,precio,tiempo,cuartos);
            system("cls");
            ap1->mostrarDatos();
            system("pause");
            break;
        case 4:
            break;
        default:
            break;
        }

    } while (opt != 4);
    
}