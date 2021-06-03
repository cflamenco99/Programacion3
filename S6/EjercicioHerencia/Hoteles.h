#include<iostream>
#include"Hospedaje.h"

using namespace std;

class Hoteles : public Hospedaje
{
private:
    bool comida = false;
    int precioComida = 1000; 
public:
    Hoteles()
    {

    }
    Hoteles(string lugar, string color, int precio, bool comida) : Hospedaje(lugar,color,precio)
    {
        this->comida = comida;
    }

    int getPrecio()
    {
        int precioFinal = Hospedaje::getPrecio();

        if(comida == true)
        {
            return precioFinal += precioComida;
        }
        else
        {
            return precioFinal;
        }
    }

    void setComida(bool comida)
    {
        this->comida = comida;
    }

    void mostrarDatos()
    {
        cout<<"Mostrando Confirmacion de Datos: \n";
        cout<<"Lugar: "<<getLugar()<<endl;
        cout<<"Color: "<<getColor()<<endl;
        cout<<"Comida: "<<comida<<endl;
        cout<<"Precio: "<<getPrecio()<<endl;
    }
    ~Hoteles();
};