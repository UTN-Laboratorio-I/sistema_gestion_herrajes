#include <iostream>
#include "AdminCompra.h"
#include "InterfazUI.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Helper.h"
#include "Compra.h"

//Constructor:
AdminCompra::AdminCompra(Sistema* sistema) : _sistema(sistema){
	_nombreModulo = "Compras";
}

//Verifica si el módulo compras está activo:
bool AdminCompra::moduloCompraActivo() {
	if (_sistema->getModulo() == _nombreModulo) {
		return true;
	}
	else {
		return false;
	}
}

bool AdminCompra::subModuloCompraActivo() {
	if (_sistema->getModulo() == _nombreModulo) {
		return true;
	}
	else {
		return false;
	}
}

void AdminCompra::subModuloCompraSalir() {
	_sistema->setModuloPantalla("Compras", 0);
}

//Sale del modulo compra hacia el principal:
void AdminCompra::moduloCompraSalir() {
	_sistema->setModuloPantalla("Principal", 888);
}

//Administra el módulo compras:
void AdminCompra::administrarModuloCompra() {
	Producto prod;
	InterfazUI compras_UI(_sistema);
	Compra compra;

	while (moduloCompraActivo()) {
		compras_UI.ver_MenuCompras();
		int opc = _sistema->getPantalla();

		switch (opc) {
		case 1:
			compras_UI.headerDinamico();
			_sistema->setSubModulo("Sub-modulo Compra");
			compra.realizarCompra(_sistema);
			break;
		case 2:
			compras_UI.headerDinamico();
			compra.mostrarProductosComprados();
			break;
		case 0: //SALIR DEL MÓDULO COMPRA:
			moduloCompraSalir();
			break;
		}
	}
	return;
}



