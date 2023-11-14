#include <iostream>
#include "Sistema.h"
#include "Reporte.h"
#pragma once

class AdminReporte
{

private:
	string _nombreModulo;
	string _nombreSubModuloCliente;
	string _nombreSubModuloProveedor;
	string _nombreSubModuloProducto;
	string _nombreSubModuloVenta;
	Sistema* _sistema;

public:
	//Constructor:
	AdminReporte(Sistema* sistema);

	//Getters/Setters:
	string getNombreModulo();

	//Administradores de m�dulo y subm�dulos:
	void administrarModuloReporte();
	void administrarSubModuloReporteCliente();
	void administrarSubModuloReporteProveedor();
	void administrarSubModuloReporteProducto();
	void administrarSubModuloReporteCaja();

	//Verificadores de estado del m�dulo:
	bool moduloReporteActivo();
	bool subModuloReporteActivo(string subModulo);

	//Salir de m�dulo y subm�dulos:
	void moduloReporteSalir();
	void subModuloReporteSalir();

	//L�gica del subm�dulos:
	void pantallaReporteClientes();
	void pantallaReporteProveedores();
	void pantallaReporteProductos();
	void pantallaReporteVentas();

};

