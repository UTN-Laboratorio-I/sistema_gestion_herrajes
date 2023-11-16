#pragma once
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
};

