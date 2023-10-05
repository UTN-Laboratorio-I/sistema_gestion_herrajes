#include <iostream>
#include "AdminCompra.h"
#include "InterfazUI.h"
#include "Producto.h"

AdminCompra::AdminCompra(Sistema* sistema) : _sistema(sistema){}


void AdminCompra::administrarModuloCompra() {
	InterfazUI compras_UI(_sistema);
	modulo_compra_activo = true;
	while (modulo_compra_activo) {
		int opc = compras_UI.ver_MenuCompras();

		switch (opc) {
		case 0:
			modulo_compra_activo = false;
			break;
		case 1:
			compras_UI.ver_menuCrearCompraProducto();
			crearCompraProducto();
			break;
		case 2:

			break;
		}
		opc = -1;
	}
}

void AdminCompra::crearCompraProducto() {
	Producto producto;
	//producto.cargarProductos();

}