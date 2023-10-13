#include "AdminReporte.h"
#include "InterfazUI.h"

#pragma region Getters/Setters
string AdminReporte::getNombreModulo(){return _nombreModulo;}
#pragma endregion Getters/Setters

//Constructor:
AdminReporte::AdminReporte(Sistema* sistema) : _sistema(sistema)
{
	_sistema = sistema;
	_nombreModulo = "Reportes";
	_nombreSubModuloCliente = "Reporte Clientes";
	_nombreSubModuloProveedor = "Reporte Proveedores";
	_nombreSubModuloProducto = "Reporte Productos";
	_nombreSubModuloVenta = "Reporte Ventas";
}

void AdminReporte::administrarModuloReporte()
{
	InterfazUI Reporte_UI(_sistema);

	while (moduloReporteActivo()) {
		Reporte_UI.ver_MenuReportes();
		int opc = _sistema->getPantalla();

		switch (opc) {
		case 1:
			_sistema->setModuloPantalla("Reporte Clientes", -1);
			administrarSubModuloReporteCliente();

			break;
		case 2:
			_sistema->setModuloPantalla("Reporte Proveedores", -1);
			administrarSubModuloReporteProveedor();

			break;
		case 3:
			_sistema->setModuloPantalla("Reporte Productos", -1);
			administrarSubModuloReporteProducto();

			break;
		case 4:
			_sistema->setModuloPantalla("Reporte Ventas", -1);
			administrarSubModuloReporteCaja();

			break;
		case 0: //SALIR DEL MÓDULO REPORTES:
			moduloReporteSalir();
			break;
		}
	}
	return;
}

void AdminReporte::administrarSubModuloReporteCliente() {
	InterfazUI Reporte_UI(_sistema);

	while (subModuloReporteActivo(_nombreSubModuloCliente)) {
		Reporte_UI.ver_SubMenuReportesCliente();
		int opc = _sistema->getPantalla();

		switch (opc) {
		case 1:
			//AGREGAR CLIENTE
			break;
		case 2:
			//ELIMINAR CLIENTE
			break;
		case 3:
			//MODIFICAR CLIENTE
			break;
		case 0:
			subModuloReporteSalir();
			break;
		}
	}
	return;
}

void AdminReporte::administrarSubModuloReporteProveedor() {
	InterfazUI Reporte_UI(_sistema);

	while (subModuloReporteActivo(_nombreSubModuloProveedor)) {
		Reporte_UI.ver_SubMenuReportesProveedor();
		int opc = _sistema->getPantalla();

		switch (opc) {
		case 1:
			//AGREGAR PROVEEDOR
			break;
		case 2:
			//ELIMINAR PROVEEDOR
			break;
		case 3:
			//MODIFICAR PROVEEDOR
			break;
		case 0:
			subModuloReporteSalir();
			break;
		}
	}
	return;
}

void AdminReporte::administrarSubModuloReporteProducto() {
	InterfazUI Reporte_UI(_sistema);

	while (subModuloReporteActivo(_nombreSubModuloProducto)) {
		Reporte_UI.ver_SubMenuReportesProducto();
		int opc = _sistema->getPantalla();

		switch (opc) {
		case 1:
			//AGREGAR PRODUCTO
			break;
		case 2:
			//ELIMINAR PRODUCTO
			break;
		case 3:
			//MODIFICAR PRODUCTO
			break;
		case 0:
			subModuloReporteSalir();
			break;
		}
	}
	return;
}

void AdminReporte::administrarSubModuloReporteCaja() {
	InterfazUI Reporte_UI(_sistema);

	while (subModuloReporteActivo(_nombreSubModuloVenta)) {
		Reporte_UI.ver_SubMenuReportesCaja();
		int opc = _sistema->getPantalla();

		switch (opc) {
		case 1:
			//AGREGAR VENTA
			break;
		case 2:
			//ELIMINAR VENTA
			break;
		case 3:
			//MODIFICAR VENTA
			break;
		case 0:
			subModuloReporteSalir();
			break;
		}
	}
	return;
}

bool AdminReporte::moduloReporteActivo()
{
	if (_sistema->getModulo() == _nombreModulo) {
		return true;
	}
	else {
		return false;
	}
}

bool AdminReporte::subModuloReporteActivo(string subModulo)
{
	if (_sistema->getModulo() == subModulo) {
		return true;
	}
	else {
		return false;
	}
}

void AdminReporte::moduloReporteSalir()
{
	_sistema->setModuloPantalla("principal", 888);
	return;
}

void AdminReporte::subModuloReporteSalir()
{
	_sistema->setModuloPantalla("Reportes", -1);
	return;
}

