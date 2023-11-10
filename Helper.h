#pragma once
#include <iostream>
using namespace std;
class Helper
{
public:
	Helper();
	~Helper();

	static void limpiarConsola();
	static void delayMensaje(string mensaje, int segundos);
};

