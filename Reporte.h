#pragma once
#include <iostream>
#include <string>

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
	void generarReporteProductos();
	void generarReporteUsuarios();
	void generarReporteTransacciones();
};

