#include "AdminVenta.h"
#include "InterfazUI.h"
#include "Venta.h"
#include "Cliente.h"

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
			//registrarNuevaVenta();
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
//void AdminVenta::registrarNuevaVenta() {
//	InterfazUI ventas_UI(_sistema);
//	Venta venta;
//	//Cliente cliente;
//	//Transaccion transaccion(_sistema);
//	bool continuar = false;
//
//	while (!continuar) {
//		int opc;
//		opc = ventas_UI.ver_VentasClienteExistente();
//
//		switch (opc) {
//		case 1:
//			//Cliente existente;
//		case 2:
//			//Nuevo cliente
//			//Response<Cliente> responseNuevoCliente = cliente.crearNuevoCliente();
//			//cliente = responseNuevoCliente.getData();
//		case 0: //SALIR DEL REGISTRO DE NUEVA VENTA AL MENU VENTA:
//			continuar = true;
//			break;
//		}
//
//	}
//}