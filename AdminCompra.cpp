#include <iostream>
#include "AdminCompra.h"
#include "InterfazUI.h"
#include "Producto.h"

//Constructor:
AdminCompra::AdminCompra(Sistema* sistema) : _sistema(sistema){
	_nombreModulo = "compras";
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

//Sale del modulo compra hacia el principal:
void AdminCompra::moduloCompraSalir() {
	_sistema->setModuloPantalla("principal", 888);
}

//Administra el módulo compras:
void AdminCompra::administrarModuloCompra() {
	InterfazUI compras_UI(_sistema);

	while (moduloCompraActivo()) {
		compras_UI.ver_MenuCompras();
		int opc = _sistema->getPantalla();

		switch (opc) {
		case 1:
			//_sistema->setModuloPantalla("compras", 1);
			//compras_UI.ver_menuCrearCompraProducto();
			crearCompraProducto();
			break;
		case 2:
			//_sistema->setModuloPantalla("compras", 2);
			
			break;
		case 0: //SALIR DEL MÓDULO COMPRA:
			moduloCompraSalir();
			break;
		}
	}
	return;
}

void AdminCompra::crearCompraProducto() {
	Producto producto;
	producto.cargarProductos();

}

