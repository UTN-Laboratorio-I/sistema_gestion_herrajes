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
			//compras_UI.ver_menuCrearCompraProducto();
			crearNuevaCompra();
			break;
		case 2:
			compras_UI.headerDinamico();
			//mostrarProductos();
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
	Archivo <Proveedor> archivoProv ("proveedores.dat");
	Archivo <Compra> archivoComp ("compras.dat");
	Response <Proveedor> responseNuevoProveedor;
	Response <Proveedor> proveedorExistente;
	Producto producto;
	Proveedor proveedor;
	Compra Compra;

	bool continuar = false;
	int opc;

	while (!continuar)
	{
		cin >> opc;
		switch(opc)
		{
		case 1: 
			//proveedorExistente = buscarProveedor();
			//proveedor = proveedorExistente.getData();
			producto.cargarProductos();
			break;
		case 2:
			 //responseNuevoProveedor = proveedor.crearNuevoProveedor();
			 //proveedor = responseNuevoProveedor.getData();
			break;
		case 0:
			continuar = true;
			continue;
		default:
			break;
		}
			continuar = true;


	}

	archivoProd.grabarRegistroArchivo(producto);
	//archivoProv.grabarRegistroArchivo(proveedor);
	//archivoComp.grabraRegistroArchivo(compra);
}

Proveedor buscarProveedor(Archivo <Proveedor> arch)
{
	Proveedor proveedor;

	int idProv;
	cout << "INGRESE ID DE PROVEEDOR: ";
	cin >> idProv;

	//proveedor = arch.buscarProvID(idProv);

	return proveedor;
}

