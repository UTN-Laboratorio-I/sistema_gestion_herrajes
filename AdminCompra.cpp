#include <iostream>
#include "AdminCompra.h"
#include "InterfazUI.h"
#include "Producto.h"

//Constructor:
AdminCompra::AdminCompra(Sistema* sistema) : _sistema(sistema){
	_nombreModulo = "Compras";
}

//Verifica si el m�dulo compras est� activo:
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
	_sistema->setModuloPantalla("Principal", 888);
}

//Administra el m�dulo compras:
void AdminCompra::administrarModuloCompra() {
	Producto prod;
	InterfazUI compras_UI(_sistema);

	while (moduloCompraActivo()) {
		compras_UI.ver_MenuCompras();
		int opc = _sistema->getPantalla();

		switch (opc) {
		case 1:
			//compras_UI.ver_menuCrearCompraProducto();
			crearCompraProducto();
			break;
		case 2:
			prod.mostrarProductos();
			
			break;
		case 0: //SALIR DEL M�DULO COMPRA:
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

