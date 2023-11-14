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

	//Administradores de módulo y submódulos:
	void administrarModuloReporte();
	void administrarSubModuloReporteCliente();
	void administrarSubModuloReporteProveedor();
	void administrarSubModuloReporteProducto();
	void administrarSubModuloReporteCaja();

	//Verificadores de estado del módulo:
	bool moduloReporteActivo();
	bool subModuloReporteActivo(string subModulo);

	//Salir de módulo y submódulos:
	void moduloReporteSalir();
	void subModuloReporteSalir();

	//Lógica del submódulos:
	void pantallaReporteClientes();
	void pantallaReporteProveedores();
	void pantallaReporteProductos();
	void pantallaReporteVentas();

};

