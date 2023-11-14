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
	_nombreSubModuloUsuario = "Reporte Usuarios";
}

void AdminReporte::administrarModuloReporte()
{
	InterfazUI Reporte_UI(_sistema);

	while (moduloReporteActivo()) {
		Reporte_UI.ver_MenuReportes();
		int opc = _sistema->getPantalla();

		switch (opc) {
		case 1:
			_sistema->setModulo("Reporte Clientes");
			administrarSubModuloReporteCliente();

			break;
		case 2:
			_sistema->setModulo("Reporte Proveedores");
			administrarSubModuloReporteProveedor();

			break;
		case 3:
			_sistema->setModulo("Reporte Productos");
			administrarSubModuloReporteProducto();

			break;
		case 4:
			_sistema->setModulo("Reporte Ventas");
			administrarSubModuloReporteCaja();

			break;
		case 5:
			_sistema->setModulo("Reporte Usuarios");
			administrarSubModuloReporteUsuarios();
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
		const char* nombreArchivo = "clientes.dat";
		Reporte_UI.ver_SubMenuReportesCliente();
		int opc = _sistema->getPantalla();
		Reporte reporte(nombreArchivo, "reporte clientes");

		switch (opc) {
		case 1:
			_sistema->setSubModulo("Reporte Clientes");
			reporte.generarReporteClientes();
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
		const char* nombreArchivo = "proveedores.dat";
		Reporte reporte(nombreArchivo, "reporte proveedores");
		Reporte_UI.ver_SubMenuReportesProveedor();
		int opc = _sistema->getPantalla();

		switch (opc) {
		case 1:
			reporte.generarReporteProveedores();
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
		const char* nombreArchivo = "productos.dat";
		Reporte reporte(nombreArchivo, "reporte productos");
		Reporte_UI.ver_SubMenuReportesProducto();
		int opc = _sistema->getPantalla();

		switch (opc) {
		case 1:
			reporte.generarReporteProductos();
			break;
		case 2:
			//ELIMINAR PRODUCTO
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

void AdminReporte::administrarSubModuloReporteUsuarios() {
	InterfazUI Reporte_UI(_sistema);
	while (subModuloReporteActivo(_nombreSubModuloUsuario)) {
		const char* nombreArchivo = "usuarios.dat";
		Reporte reporte(nombreArchivo, "reporte usuarios");
		Reporte_UI.ver_SubMenuReportesUsuario();
		int opc = _sistema->getPantalla();

		switch (opc) {
		case 1:
			reporte.generarReporteUsuarios();
			break;
		case 2:
			//ELIMINAR USUARIO
			break;
		case 3:
			//MODIFICAR USUARIO
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
	_sistema->setModuloPantalla("Principal", 888);
	return;
}

void AdminReporte::subModuloReporteSalir()
{
	_sistema->setModuloPantalla("Reportes", -1);
	return;
}

