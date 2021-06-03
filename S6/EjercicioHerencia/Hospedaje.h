#ifndef HOSPEDAJE_H
#define HOSPEDAJE_H

#include<iostream>

using namespace std;

class Hospedaje
{
    private:
    int precio;
    string lugar;
    string color;

    public:
    Hospedaje()
    {

    }

    Hospedaje(string lugar, string color,int precio)
    {
        this->lugar = lugar;
        this->color = color;
        this->precio = precio;
    }

    int getPrecio()
    {
        return precio;
    }

    string getLugar()
    {
        return lugar;
    }

    string getColor()
    {
        return color;
    }

    void setLugar(string lugar)
    {
        this->lugar = lugar;
    }

    void setColor(string color)
    {
        this->color = color;
    }

};

#endif