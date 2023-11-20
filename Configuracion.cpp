#include "Configuracion.h"
#include <fstream>
#include <iostream>
#include "Archivo.h"
using namespace std;

Configuracion::Configuracion()
{
	Response<Configuracion> configuracion;
	Archivo<Configuracion> archivoConfig("configuracion.dat");
	configuracion = archivoConfig.buscarUnRegistro(0);

	if (configuracion.getSuccess())
	{
		_margenUtilidad = configuracion.getData()._margenUtilidad;
		_formatoFecha = configuracion.getData()._formatoFecha;
	}
	else
	{
		_margenUtilidad = 0.0;
		_formatoFecha = 0;
	}
}

Configuracion::~Configuracion()
{
}

void Configuracion::setMargenUtilidad(float m)
{
	Archivo<Configuracion> archivoConfig("configuracion.dat");
	_margenUtilidad = m;

	archivoConfig.grabarOModificarRegistro(*this, 1, [](Configuracion c) {return c.getMargenUtilidad() != -1; });
}

void Configuracion::setFormatoFecha(int f)
{
	Archivo<Configuracion> archivoConfig("configuracion.dat");
	_formatoFecha = f;

	archivoConfig.grabarOModificarRegistro(*this, 1, [](Configuracion c) {return c.getMargenUtilidad() != -1; });
}

float Configuracion::getMargenUtilidad()
{
	return _margenUtilidad;
}

int Configuracion::getFormatoFecha()
{
	return _formatoFecha;
}

//void Configuracion::setFormatoMoneda(int opc) {
//	Archivo<Configuracion> archivoConfig("configuracion.dat");
//	_formatoMoneda = opc;
//
//	archivoConfig.grabarOModificarRegistro(*this, 1, [](Configuracion c) {return c.getMargenUtilidad() != -1; });
//}
//
//int Configuracion::getFormatoMoneda() {
//	return _formatoMoneda;
//}

