#include "Configuracion.h"
#include <fstream>
#include <iostream>
#include "Archivo.h"
using namespace std;

Configuracion::Configuracion()
{
}

Configuracion::~Configuracion()
{
}

void Configuracion::setConfiguracion() {
	Archivo<Configuracion> archivoConfig("configuracion.dat");
	Response<Configuracion> configuracion = archivoConfig.buscarUnRegistro(1);

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

void Configuracion::setId(int id)
{
	Archivo<Configuracion> archivoConfig("configuracion.dat");
	_id = id;

	archivoConfig.grabarOModificarObjeto(*this);
}

int Configuracion::getId()
{
	return _id;
}

void Configuracion::setMargenUtilidad(float m)
{
	Archivo<Configuracion> archivoConfig("configuracion.dat");
	_margenUtilidad = m;

	archivoConfig.grabarOModificarObjeto(*this);
}

void Configuracion::setFormatoFecha(int f)
{
	Archivo<Configuracion> archivoConfig("configuracion.dat");
	_formatoFecha = f;

	archivoConfig.grabarOModificarObjeto(*this);
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

