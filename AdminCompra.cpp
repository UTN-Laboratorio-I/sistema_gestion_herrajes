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

	while (moduloCompraActivo()) {
		compras_UI.ver_MenuCompras();
		int opc = _sistema->getPantalla();

		switch (opc) {
		case 1:
			compras_UI.headerDinamico();
			crearNuevaCompra();
			break;
		case 2:
			compras_UI.headerDinamico();
			mostrarCompras();
			break;
		case 0: //SALIR DEL MÓDULO COMPRA:
			moduloCompraSalir();
			break;
		}
	}
	return;
}



void AdminCompra::crearNuevaCompra() {
	Archivo <Producto> archivoProd ("productos.dat");
	Archivo <Compra> archivoComp ("compras.dat");
	Producto producto;
	Response <Producto> responseProducto;
	Response <Proveedor> responseProveedor;
	Proveedor proveedor;
	Compra Compra;
	Helper header;
	InterfazUI subCompras_UI(_sistema);


	bool continuar = true;

	while (continuar)
	{	
		subCompras_UI.headerDinamico();
		subCompras_UI.ver_SubMenuCrearCompraProducto();
		int opc = _sistema->getPantalla();
		switch(opc)
		{
		case 1:
			subCompras_UI.headerDinamico();
			responseProveedor = proveedor.buscarProveedor();
			if (!responseProveedor.getSuccess()){break;}
			header.limpiarConsola();
			subCompras_UI.headerDinamico();
			proveedor.ver_ProveedorEncontrado(responseProveedor);
			//proveedor = proveedorExistente.getData();
			responseProducto = producto.cargarProductos();
			break;
		case 2:
			subCompras_UI.headerDinamico();
			responseProveedor = proveedor.cargarProveedor();
			//proveedor = responseNuevoProveedor.getData();
			//responseNuevoProveedor.setData(proveedor);
			producto.cargarProductos();
			 //proveedor = responseNuevoProveedor.getData();
			break;
		case 0:
			subModuloCompraSalir();
			continuar = false;
			break;
		default: 
			break;
		}
	}

}


void AdminCompra :: mostrarCompras() {

}
