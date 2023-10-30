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
			registrarNuevaVenta();
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
	Cliente cliente;
	Response<Cliente> responseCliente;
	Venta venta;
	Response<Venta> responseVenta;
	//Cliente cliente;
	bool continuar = false;

	while (!continuar) {
		int opc;
		opc = ventas_UI.ver_VentasClienteExistente();

		switch (opc) {
		case 1:
			_sistema->setSubModulo("Seleccion cliente existente");
			cliente = cliente.listarYSeleccionarClienteExistente();
			if (cliente.getIdCliente() == 0) {
				_sistema->setError("No hay clientes creados");
				ventas_UI.headerDinamico();
				system("pause");
				continuar = true;
			}
			else {
				venta.setClienteId(cliente.getIdCliente());
			}

			break;
		case 2:
			_sistema->setSubModulo("Creacion nuevo cliente");
			responseCliente = cliente.cargarCliente();
			cliente= responseCliente.getData();

			
			venta.setClienteId(cliente.getIdCliente());

			break;
		case 0: //SALIR DEL REGISTRO DE NUEVA VENTA AL MENU VENTA:
			continuar = true;
			break;
		}
		//Guardamos el ID del cliente en la venta:

		if (!continuar) {
			_sistema->setSubModulo("Nueva Venta");
			venta.crearNuevaVenta(_sistema); //Le paso el parametro sistema para
			//poder utilizar la UI (Sobre todo el limpiarConsola y headerDinamico)


			if (responseVenta.getSuccess()) {
			}
			else {
				_sistema->setError(responseVenta.getMessage());
			}	
		}

	}
	_sistema->limpiarError();
	_sistema->limpiarSubModulo();
}