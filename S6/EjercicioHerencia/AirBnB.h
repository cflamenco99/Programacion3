#include<iostream>
#include"Hospedaje.h"

using namespace std;

class AirBnB : public Hospedaje
{
private:
    int personas;
    int tiempo;
public:
    AirBnB(string lugar, string color,int precio, int personas, int tiempo) : Hospedaje(lugar,color,precio)
    {
        this->personas = personas;
        this->tiempo = tiempo;
    }

    int getPrecio()
    {
        int precioFinal = Hospedaje::getPrecio();

        return precioFinal*tiempo*personas;
    }

    void setPersonas(int personas)
    {
        this->personas = personas;
    }

    void setTiempo()
    {
        this->tiempo = tiempo;
    }

    void mostrarDatos()
    {
        cout<<"Mostrando Confirmacion de Datos: \n";
        cout<<"Lugar: "<<getLugar()<<endl;
        cout<<"Color: "<<getColor()<<endl;
        cout<<"Personas: "<<personas<<endl;
        cout<<"Tiempo: "<<tiempo<<endl;
        cout<<"Precio: "<<getPrecio()<<endl;
    }
};