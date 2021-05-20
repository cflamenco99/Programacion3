#include <iostream>
#include <random>
#include <string>
using namespace std;

constexpr int MIN = 00;
constexpr int MAX = 99;

class FuncionesGenerales
{
public:

	FuncionesGenerales()
	{

	}

	bool EsApuestaValida(int Apuesta)
	{
		if (Apuesta == 5)
		{
			return true;
		}
		if (Apuesta == 10)
		{
			return true;
		}
		if (Apuesta ==  15 )
		{
			return true;
		}
		if (Apuesta == 20 )
		{
			return true;
		}
		if (Apuesta == 25 )
		{
			return true;
		}
		if (Apuesta == 30 )
		{
			return true;
		}
		if (Apuesta ==  40 )
		{
			return true;
		}
		if (Apuesta == 50)
		{
			return true;
		}
		return false;
	}

	bool EsJugadaValida(int Jugada)
	{
		for (int i = 0; i <= 99; i++)
		{
			if (Jugada = i)
			{
				return true;
			}
		}
		return false;
	}

	bool AciertoValido(int jugada, int PrimerNumeroGanador, int SegundoNumeroGanador, int TercerNumeroGanador)
	{
		if (jugada == PrimerNumeroGanador)
		{
			return true;
		}
		if (jugada ==  SegundoNumeroGanador)
		{
			return true;
		}
		if (jugada == TercerNumeroGanador)
		{
			return true;
		}
		return false;
	}

	int GetPremioEnEfectivo(int Aciertos, int Apuesta)
	{
		int PremioEfectivo = 0;
		switch (Apuesta)
		{
		case 5:
			PremioEfectivo = Aciertos == 1 ? 20 : 0;
			PremioEfectivo = Aciertos == 2 ? 150 : 0;
			PremioEfectivo = Aciertos == 3 ? 100000 : 0;
			break;

		case 10:
			PremioEfectivo = Aciertos == 1 ? 40 : 0;
			PremioEfectivo = Aciertos == 2 ? 300 : 0;
			PremioEfectivo = Aciertos == 3 ? 200000 : 0;
			break;

		case 15:
			PremioEfectivo = Aciertos == 1 ? 60 : 0;
			PremioEfectivo = Aciertos == 2 ? 450 : 0;
			PremioEfectivo = Aciertos == 3 ? 300000 : 0;
			break;

		case 20:
			PremioEfectivo = Aciertos == 1 ? 80 : 0;
			PremioEfectivo = Aciertos == 2 ? 600 : 0;
			PremioEfectivo = Aciertos == 3 ? 400000 : 0;
			break;

		case 25:
			PremioEfectivo = Aciertos == 1 ? 100 : 0;
			PremioEfectivo = Aciertos == 2 ? 750 : 0;
			PremioEfectivo = Aciertos == 3 ? 500000 : 0;
			break;

		case 30:
			PremioEfectivo = Aciertos == 1 ? 120 : 0;
			PremioEfectivo = Aciertos == 2 ? 900 : 0;
			PremioEfectivo = Aciertos == 3 ? 600000 : 0;
			break;

		case 40:
			PremioEfectivo = Aciertos == 1 ? 160 : 0;
			PremioEfectivo = Aciertos == 2 ? 1200 : 0;
			PremioEfectivo = Aciertos == 3 ? 800000 : 0;
			break;

		case 50:
			PremioEfectivo = Aciertos == 1 ? 200 : 0;
			PremioEfectivo = Aciertos == 2 ? 1500 : 0;
			PremioEfectivo = Aciertos == 3 ? 1000000 : 0;
			break;
		}
		return PremioEfectivo;
	}
};

class LaJugada
{
public:

	LaJugada()
	{

	}

	LaJugada(int _PrimerJugada, int _SegundaJugada, int _TerceraJugada, int _Apuesta)
	{
		PrimerJugada = _PrimerJugada;
		SegundaJugada = _SegundaJugada;
		TerceraJugada = _TerceraJugada;
		Apuesta = _Apuesta;
	}

	int PrimerJugada;
	int SegundaJugada;
	int TerceraJugada;
	int Apuesta;
};

class Sorteo
{
public:

	Sorteo()
	{
		//Operaciones para generar numeros random
		std::random_device rd;
		std::default_random_engine eng(rd());
		std::uniform_int_distribution<int> distr(MIN, MAX);

		PrimerNumeroGanador = distr(eng);
		SegundoNumeroGanador = distr(eng);
		TercerNumeroGanador = distr(eng);
	}

	int PrimerNumeroGanador;
	int SegundoNumeroGanador;
	int TercerNumeroGanador;
};

int main()
{	
	FuncionesGenerales Funciones;	
	Sorteo SorteoGanador;
	LaJugada Jugada;

	int PrimerJugada = 0, SegundaJugada = 0, TercerJugada = 0, OpcionMenu = 0, PremioEnEfectivo = 0, Aciertos = 0;
	float Apuesta = 0;
	int Centinela = 1;

	cout << "\n BIENVENIDO AL SORTEO!!! ";
	while (Centinela != 0)
	{		
		cout << "\n *** MENU *** ";
		cout << "\n 1. Crear Sorteo";
		cout << "\n 2. Vender Boletos";
		cout << "\n 3. Realizar Sorteo";
		cout << "\n 4. Resultados";
		cout << "\n 5. SALIR";

		cout << "\n\n Ingrese la opcion: ";
		cin >> OpcionMenu;


		switch (OpcionMenu)
		{
		case 1:
		{
			Sorteo NuevoSorteo;
			SorteoGanador = NuevoSorteo;
			cout << "\n **************************** SE HA CREADO UN NUEVO SORTEO!!! ****************************";
			break;
		}


		case 2:
		{
			cout << "\n **************************** Todas las jugadas deben estar entre el 00 y el 99 ****************************";
			// Pedimos los datos de la jugada
			cout << "\n Ingrese la primer jugada: ";
			cin >> PrimerJugada;
			while (!Funciones.EsJugadaValida(PrimerJugada))
			{
				cout << "\n Ingrese la primer jugada: ";
				cin >> PrimerJugada;
			}

			cout << "\n Ingrese la segunda jugada: ";
			cin >> SegundaJugada;
			while (!Funciones.EsJugadaValida(SegundaJugada))
			{
				cout << "\n Ingrese la segunda jugada: ";
				cin >> SegundaJugada;
			}


			cout << "\n Ingrese la tercer jugada: ";
			cin >> TercerJugada;
			while (!Funciones.EsJugadaValida(TercerJugada))
			{
				cout << "\n Ingrese la tercer jugada: ";
				cin >> TercerJugada;
			}


			cout << "\n Ingrese la cantidad de dinero que desea apostar: ";
			cin >> Apuesta;
			while (!Funciones.EsApuestaValida(Apuesta))
			{
				cout << "\n Ingrese la cantidad de dinero que desea apostar: ";
				cin >> Apuesta;
			}
			// Instanciamos un objeto con "La Jugada" del usuarios
			LaJugada NuevaJugada(PrimerJugada, SegundaJugada, TercerJugada, Apuesta);
			Jugada = NuevaJugada;
			break;
		}


		case 3:
			cout << "\n **************************** REALIZANDO SORTEO ****************************";
			cout << "\n **************************** SORTEO REALIZADO ****************************";
			if (Funciones.AciertoValido(Jugada.PrimerJugada, SorteoGanador.PrimerNumeroGanador, SorteoGanador.SegundoNumeroGanador, SorteoGanador.TercerNumeroGanador))
			{
				Aciertos++;
			}
			if (Funciones.AciertoValido(Jugada.SegundaJugada, SorteoGanador.PrimerNumeroGanador, SorteoGanador.SegundoNumeroGanador, SorteoGanador.TercerNumeroGanador))
			{
				Aciertos++;
			}
			if (Funciones.AciertoValido(Jugada.TerceraJugada, SorteoGanador.PrimerNumeroGanador, SorteoGanador.SegundoNumeroGanador, SorteoGanador.TercerNumeroGanador))
			{
				Aciertos++;
			}
			PremioEnEfectivo = Funciones.GetPremioEnEfectivo(Aciertos, Jugada.Apuesta);
			break;

		case 4:
			cout << "\n **************************** RESULTADOS ****************************";
			cout << "\n EL PRIMER NUMERO GANADOR DEL SORTEO FUE: " << SorteoGanador.PrimerNumeroGanador;
			cout << "\n EL SEGUNDO NUMERO GANADOR DEL SORTEO FUE: " << SorteoGanador.SegundoNumeroGanador;
			cout << "\n EL TERCER NUMERO GANADOR DEL SORTEO FUE: " << SorteoGanador.TercerNumeroGanador;

			cout << "\n USTED GANO UN PREMIO EN EFECTIVO DE: " << PremioEnEfectivo;
			break;
		default:
			Centinela = 0;
			cout << "\n HA TERMINADO EL JUEGO";
			break;
		}
	}


	
}