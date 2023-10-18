#include "AdminVenta.h"
#include "InterfazUI.h"

//Constructor:
AdminVenta::AdminVenta(Sistema* sistema) : _sistema(sistema) {
	_nombreModulo = "Ventas";
}

//Verifica si el módulo ventas está activo:
bool AdminVenta::moduloVentaActivo() {
	return _sistema->getModulo() == _nombreModulo;
}

//Sale del modulo venta hacia el principal:
void AdminVenta::moduloVentaSalir() {
	_sistema->setModuloPantalla("Principal", 888);
}

//Administra el módulo ventas:
void AdminVenta::administrarModuloVenta() {
	InterfazUI ventas_UI(_sistema);

	while (moduloVentaActivo()) {
		ventas_UI.ver_MenuVentas();
		int opc = _sistema->getPantalla();

		switch (opc) {
		case 1:
			//ventas_UI.ver_menuCrearVentaProducto();
			//crearVentaProducto();
			break;
		case 2:
			//_sistema->setModuloPantalla("ventas", 2);
			break;
		case 0: //SALIR DEL MÓDULO VENTA:
			moduloVentaSalir();
			break;
		}
	}
	return;
}

//Registra una nueva venta:
void AdminVenta::registrarNuevaVenta() {
	InterfazUI ventas_UI(_sistema);

	bool continuar = false;

	while (!continuar) {
	}
}