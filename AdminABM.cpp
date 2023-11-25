#include "AdminABM.h"
#include "InterfazUI.h"
#include "Cliente.h"
#include "Proveedor.h"

#pragma region Getters/Setters
string AdminABM::getNombreModulo(){return _nombreModulo;}
#pragma endregion Getters/Setters

//Constructor:
AdminABM::AdminABM(Sistema* sistema) : _sistema(sistema)
{
	_sistema = sistema;
	_nombreModulo = "ABM";
	_nombreSubModuloCliente = "ABM Clientes";
	_nombreSubModuloProveedor = "ABM Proveedores";
	_nombreSubModuloProducto = "ABM Productos";
}

void AdminABM::administrarModuloABM()
{
	InterfazUI ABM_UI(_sistema);

	while (moduloABMActivo()) {
		ABM_UI.ver_MenuABM();
		int opc = _sistema->getPantalla();

		switch (opc) {
		case 1:
			_sistema->setModulo("ABM Clientes");
			administrarSubModuloABMCliente();
			break;
		case 2:
			_sistema->setModulo("ABM Proveedores");
			administrarSubModuloABMProveedor();
			break;
		case 3:
			_sistema->setModulo("ABM Productos");
			administrarSubModuloABMProducto();
			break;
		case 0: //SALIR DEL MÓDULO ABM:
			moduloABMSalir();
		}
	}
	return;
}

void AdminABM::administrarSubModuloABMCliente() {
	InterfazUI ABM_UI(_sistema);
	Helper helper;

	while (subModuloABMActivo(_nombreSubModuloCliente)) {
		ABM_UI.ver_SubMenuABMCliente();
		int opc = _sistema->getPantalla();
		Cliente nuevoCliente;

		switch (opc) {
		case 1:
			helper.limpiarConsola();
			ABM_UI.headerDinamico();
			nuevoCliente.cargarCliente();
			break;
		case 2:
			nuevoCliente.modificarOdarBajaCliente();
			break;
		case 3:
			nuevoCliente.modificarOdarBajaCliente(false);
			break;
		case 4:
			nuevoCliente.mostarCliente();
			break;
		case 0:
			subModuloABMSalir();
		}
	}
}

void AdminABM::administrarSubModuloABMProveedor() {
	InterfazUI ABM_UI(_sistema);

	while (subModuloABMActivo(_nombreSubModuloProveedor)) {
		ABM_UI.ver_SubMenuABMProveedor();
		int opc = _sistema->getPantalla();
		Proveedor nuevoProveedor;

		switch (opc) {
		case 1:
			nuevoProveedor.cargarProveedor();
			break;
		case 2:
			nuevoProveedor.modificarOdarBajaProveedor();
			break;
		case 3:
			nuevoProveedor.modificarOdarBajaProveedor(false);
			break;
		case 4:
			nuevoProveedor.mostarProveedor();
			break;
		case 0:
			subModuloABMSalir();
		}
	}

}

void AdminABM::administrarSubModuloABMProducto() {
	InterfazUI ABM_UI(_sistema);
	Helper helper;

	while (subModuloABMActivo(_nombreSubModuloProducto)) {
		ABM_UI.ver_SubMenuABMProducto();
		int opc = _sistema->getPantalla();
		Producto nuevoProducto;

		switch (opc) {
		case 1:
			nuevoProducto.responseCargarProducto();
			break;
		case 2:
			nuevoProducto.modificarOdarBajaProducto();
			break;
		case 3:
			nuevoProducto.modificarOdarBajaProducto(false);
			break;
		case 4:
			nuevoProducto.mostrarProductos();
			break;
		case 0:
			subModuloABMSalir();
			break;
		}
	}
}



bool AdminABM::moduloABMActivo()
{
	if (_sistema->getModulo() == _nombreModulo) {
		return true;
	}
	else {
		return false;
	}
}

bool AdminABM::subModuloABMActivo(string subModulo)
{
	if (_sistema->getModulo() == subModulo) {
		return true;
	}
	else {
		return false;
	}
}

void AdminABM::moduloABMSalir()
{
	_sistema->setModuloPantalla("Principal", 888);
	return;
}


void AdminABM::subModuloABMSalir()
{
	_sistema->setModuloPantalla("ABM", -1);
	return;
}



void AdminABM::pantallaABMClientes(){}