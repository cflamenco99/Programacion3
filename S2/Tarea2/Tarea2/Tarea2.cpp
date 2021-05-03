#include <iostream>
#include <random>
#include <string>
using namespace std;

constexpr int MIN = 0;
constexpr int MAX = 5;

int main()
{
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<int> distr(MIN, MAX);

    int CantidadPartidosPendientes = 0, GolesEquipoA = 0, GolesEquipoB = 0, PuntosEquipoA = 0, PuntosEquipoB = 0, DebeIngresarNombreEquipo = 0, OpcionEscogida = 0;
	char NombreEquipo[60];

	cout << "\n¿Desea ingresar el nombre de su equipo? SI(1) / NO(0): ";
	cin >> DebeIngresarNombreEquipo;

	if (DebeIngresarNombreEquipo == 1)
	{
		cout << "\n¿Cual es el nombre de su equipo? ";
		cin >> NombreEquipo;
	}

	cout << "\nIngrese la cantidad de partidos pendientes: ";
	cin >> CantidadPartidosPendientes;

	for (int i = 0; i < CantidadPartidosPendientes; i++)
	{
		GolesEquipoA = distr(eng);
		GolesEquipoB = distr(eng);
		if (GolesEquipoA > GolesEquipoB)
		{
			PuntosEquipoA += 3;
		}
		else if (GolesEquipoA < GolesEquipoB)
		{
			PuntosEquipoB += 3;
		}
		else
		{
			PuntosEquipoA += 1;
			PuntosEquipoB += 1;
		}
	}

	cout << "Presione (1) para imprimir resultados o (2) para declarar campeon a su equipo: ";
	cin >> OpcionEscogida;

	if (OpcionEscogida == 1)
	{
		cout << "Los puntos alcanzados del equipo A fueron: " << PuntosEquipoA << "\n";
		cout << "Los puntos alcanzados del equipo B fueron: " << PuntosEquipoB << "\n";
	}
	else
	{
		cout << "Su equipo " << NombreEquipo << " ha quedado campeon!!!";
	}

    return EXIT_SUCCESS;
}