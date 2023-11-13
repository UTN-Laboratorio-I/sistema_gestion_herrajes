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

