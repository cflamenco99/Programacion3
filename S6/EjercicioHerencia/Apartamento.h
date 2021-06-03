#include<iostream>
#include"Hospedaje.h"

using namespace std;

class Apartamento : public Hospedaje
{
private:
    int tiempo; // En meses
    int habitaciones;
public:
    Apartamento(string lugar, string color,int precio,int tiempo, int habitaciones) : Hospedaje(lugar,color,precio)
    {
        this->tiempo = tiempo;
        this->habitaciones = habitaciones;
    }

    int getPrecio()
    {
        int precioFinal=Hospedaje::getPrecio();

        return precioFinal*tiempo*habitaciones;
    }

    void setTiempo(int tiempo)
    {
        this->tiempo = tiempo;
    }

    void setHabitaciones(int habitaciones)
    {
        this->habitaciones = habitaciones;
    }

    void mostrarDatos()
    {
        cout<<"Mostrando Confirmacion de Datos: \n";
        cout<<"Lugar: "<<getLugar()<<endl;
        cout<<"Color: "<<getColor()<<endl;
        cout<<"Habitaciones: "<<habitaciones<<endl;
        cout<<"Tiempo: "<<tiempo<<endl;
        cout<<"Precio: "<<getPrecio()<<endl;
    }
};