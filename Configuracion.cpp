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
	Response<Configuracion> configuracion = archivoConfig.obtenerConfiguracion();

	if (configuracion.getSuccess())
	{
		_margenUtilidad = configuracion.getData()._margenUtilidad;
		_formatoFecha = configuracion.getData()._formatoFecha;
		_carpetaBackUp = configuracion.getData()._carpetaBackUp;
	}
	else
	{
		_margenUtilidad = 0.0;
		_formatoFecha = 0;
		_carpetaBackUp = "";
	}
}

void Configuracion::setMargenUtilidad(int m)
{
	Response<Configuracion> response;
	Archivo<Configuracion> archivoConfig("configuracion.dat");
	float conversion = m / 100.0;
	_margenUtilidad = conversion;

	response = archivoConfig.grabarOModificarConfiguracion(*this);

	if (response.getSuccess()) {
		cout << "Margen de utilidad actualizado con exito." << endl;
	}
	else {
		cout << "No se pudo actualizar el margen de utilidad." << endl;
	}
	
}

void Configuracion::setFormatoFecha(int f)
{
	Response<Configuracion> response;
	Archivo<Configuracion> archivoConfig("configuracion.dat");
	_formatoFecha = f;

	response = archivoConfig.grabarOModificarConfiguracion(*this);

	if (response.getSuccess()) {
		cout << "Margen de utilidad actualizado con exito." << endl;
	}
	else {
		cout << "No se pudo actualizar el margen de utilidad." << endl;
	}
}

float Configuracion::getMargenUtilidad()
{
	return _margenUtilidad;
}

int Configuracion::getFormatoFecha()
{
	return _formatoFecha;
}

void Configuracion::setCarpetaBackUp(const char* carpeta)
{
	Response<Configuracion> response;
	Archivo<Configuracion> archivoConfig("configuracion.dat");
	_carpetaBackUp = carpeta;


	response = archivoConfig.grabarOModificarConfiguracion(*this);

	if (response.getSuccess()) {
		cout << "La carpeta de backups fue grabada." << endl;
	}
	else {
		cout << "No se pudo actualizar la carpeta de backups." << endl;
	}
}

const char* Configuracion::getCarpetaBackUp()
{
	return _carpetaBackUp;
}
