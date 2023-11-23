#include "Helper.h"
#include "Fecha.h"
#include <iostream>
#include <functional>
#include <string>
#include <chrono>
#include <thread>


using namespace std;

Helper::Helper(){}

Helper::~Helper(){}

void Helper::limpiarConsola()
{
	system("cls");
}

void Helper::delayMensaje(string mensaje, int segundos = 3)
{

	cout << mensaje << endl << endl;
	cout << "---------------------------------" << endl;
	this_thread::sleep_for(chrono::seconds(segundos));
}

/// <summary>
/// Convierte el nombre de una tabla a un número entero
/// Para utilizar dentro de switch (En tablaDto.h)
/// </summary>
int Helper::conversorNombreTablaSwitch(string tabla) {

	if (tabla == "usuarios") return 0;
	if (tabla == "productos") return 1;
	if (tabla == "clientes") return 2;
	if (tabla == "carrito") return 3;
	if (tabla== "reporte clientes") return 4;
	if (tabla == "reporte proveedores") return 5;
	if (tabla == "reporte productos") return 6;
	if (tabla == "reporte usuarios") return 7;
	if (tabla == "reporte transacciones")return 11;
}

string Helper::conversorFormatoFecha(int formatoFecha, Fecha& fecha) {
	string date;
	string anio = std::to_string(fecha.getAnio());
	string mes = std::to_string(fecha.getMes());
	string dia = std::to_string(fecha.getDia());
	switch (formatoFecha) {
	case 1: // DD/MM/AAAA
		date = "" + dia + "/" + mes + "/" + anio + "";
		break;
	case 2: //MM/DD/AAAA
		date = "" + mes + "/" + dia + "/" + anio + "";
		break;
	case 3: //AAAA/MM/DD
		date = "" + anio + "/" + mes + "/" + dia + "";
		break;
	default:// DD/MM/AAAA
		date = "" + dia + "/" + mes + "/" + anio + "";
		break;
	}
	return date;
}