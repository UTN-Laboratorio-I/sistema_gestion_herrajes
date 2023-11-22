#include "Helper.h"
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
	if (tabla == "carrito compras") return 12;
	if (tabla== "reporte clientes") return 4;
	if (tabla == "reporte proveedores") return 5;
	if (tabla == "reporte productos") return 6;
	if (tabla == "reporte usuarios") return 7;
	if (tabla == "reporte transacciones")return 11;
}

