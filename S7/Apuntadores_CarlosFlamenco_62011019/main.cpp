#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>

#pragma region Validaciones
bool esAnioValido(int anio)
{
	if(anio > 2021)
	{
		return false;
	}
	return true;	
}

bool esMesValido(int mes)
{
	if(mes <= 0 || mes > 12 )
	{
		return false;
	}
	return true;
}

bool esDiaValido(int dia)
{
	if(dia <= 0 || dia > 31 )
	{
		return false;
	}
	return true;
}

bool esHoraValido(int hora)
{
	if(hora <= 0 || hora > 24 )
	{
		return false;
	}
	return true;
}

bool esMinutoValido(int minuto)
{
	if(minuto <= 0 || minuto >= 60)
	{
		return false;
	}
	return true;
}

string concatenarDosStrings(const string &s1, const string &s2)
{
    return s1 + s2;
}

string GetMesString(int mes)
{
	switch (mes) {
  case 1:
    return "Enero";
    break;
  case 2:
    return "Febrero";
    break;
  case 3:
    return "Marzo";
    break;
  case 4:
    return "Abril";
    break;
  case 5:
    return "Mayo";
    break;
  case 6:
    return "Junio";
    break;
  case 7:
    return "Julio";
    break;
  case 8:
    return "Agosto";
    break;
  case 9:
    return "Septiembre";
    break;
  case 10:
    return "Octubre";
    break;
  case 11:
    return "Noviembre";
    break;
  case 12:
    return "Diciembre";
    break;
}

}
#pragma endregion Validaciones

void mostrarFechaHora (int anio, int mes, int dia, int hora, int minuto)
{
	if(!esAnioValido(anio) || !esMesValido(mes) || !esDiaValido(dia) || !esHoraValido(hora) ||!esMinutoValido(minuto))
	{
		cout << "ERROR: Formatos ingresados invalidos.";
		return;
	}
	
	//Declaramos buffer y string para construir fecha.
	char buffer [33];
	string Fecha = "";
	
	//Uso de apuntadores y funcion ITOA en año.
	int *diaApuntador = &dia;
	itoa (*diaApuntador,buffer,10);	
	Fecha += concatenarDosStrings("", buffer);
	
	//Uso de apuntadores y funcion GetMesString en mes.
	int *mesApuntador = &mes;
	Fecha += concatenarDosStrings(" de ", GetMesString(*mesApuntador));
	
	//Uso de apuntadores y funcion ITOA en año.
	int *anioApuntador = &anio;
	itoa (*anioApuntador,buffer,10);	
	Fecha += concatenarDosStrings(" de ", buffer);
	
	//Uso de apuntadores y funcion ITOA en hora.
	int *horaApuntador = &hora;
	itoa (*horaApuntador,buffer,10);	
	Fecha += concatenarDosStrings(", ", buffer);
	
	//Uso de apuntadores y funcion ITOA en minuto.
	int *minutoApuntador = &minuto;
	itoa (*minutoApuntador,buffer,10);	
	Fecha += concatenarDosStrings(":", buffer);	

	//Imprimimos la fecha ya construida
	cout << Fecha;
}

int longitud(char *s)
{
    return (*s) ? 1 + longitud(s + 1) : 0;
}

int main(int argc, char** argv) {
	cout <<"Ejercicio #1\n";
	mostrarFechaHora(2016, 9, 15, 13, 30);
	
	cout <<"\nEjercicio #2\n";
	cout <<"La longitud de la cadena es: " << longitud("Prueba de longitud");
	
	return 0;
}
