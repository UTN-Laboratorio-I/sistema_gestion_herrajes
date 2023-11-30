#pragma once
#include "Fecha.h"
#include <iostream>
#include <vector>

using namespace std;
class Helper
{
public:
	Helper();
	~Helper();

	static void limpiarConsola();
	static void delayMensaje(string mensaje, int segundos);

	static int conversorNombreTablaSwitch(string tabla);

	static string conversorFormatoFecha(int formatoFecha, Fecha& fecha);
};

