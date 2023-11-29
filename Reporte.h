#pragma once
#include <iostream>
#include <string>
#include "Sistema.h"

using namespace std;

class Reporte
{
private:
	const char* _nombreArchivo;
	string _nombreModulo;

public:
	Reporte();
	Reporte(const char* nombreArchivo, string nombreModulo);

	int opcionesMenuReporte();

	void generarReporteClientes();
	void generarReporteProveedores();
	void generarReporteProductos(Sistema *sistema);
	void generarReporteUsuarios();
	void generarReporteTransacciones();
};

