#include "AdminABM.h"
#include "InterfazUI.h"

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
	_sistema->setModuloPantalla("principal", 888);
	return;
}


void AdminABM::subModuloABMSalir()
{
	_sistema->setModuloPantalla("ABM", -1);
	return;
}

void AdminABM::administrarModuloABM()
{
	InterfazUI ABM_UI(_sistema);

	while (moduloABMActivo()) {
		ABM_UI.ver_MenuABM();
		int opc = _sistema->getPantalla();

		switch (opc) {
		case 1:
			ABM_UI.ver_SubMenuABMCliente();
			pantallaABMClientes();
			
			break;
		case 2:

			break;
		case 0: //SALIR DEL M�DULO ABM:
			moduloABMSalir();
			break;
		}
	}
	return;
}

void AdminABM::administrarSubModuloABMCliente() {
	InterfazUI ABM_UI(_sistema);

	while (subModuloABMActivo(_nombreSubModuloCliente)) {
		ABM_UI.ver_SubMenuABMCliente();
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
			subModuloABMSalir();
		}
	}
}

void AdminABM::pantallaABMClientes(){}