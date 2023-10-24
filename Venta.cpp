#include <iostream>
#include "Venta.h"
#include "InterfazUI.h"
#include "Cliente.h"
#include "Caja.h"
#include "ResponseDto.h"

using namespace std;
Venta::Venta() {
	_clienteId = 0;
	_tipo = 'v';
};

void Venta::setId(int id) {
	_id = id;
}
int Venta::getId() {
	return _id;
}
void Venta::setClienteId(int clienteId) {
	_clienteId = clienteId;
}
int Venta::getClienteId() {
	return _clienteId;
}

void Venta::setProducto(Producto producto) {
	_producto = producto;
}
Producto Venta::getProducto() {
	return _producto;
}

void Venta::setTipoTransaccion(char tipoTransaccion) { _tipoTransaccion = tipoTransaccion; }
char Venta::getTipoTransaccion() { return _tipoTransaccion; }

void Venta::agregarADetalleVenta(Producto producto, int cantidad) {
	Detalle detalle(producto, cantidad);
	_detalle.push_back(detalle);
}

void Venta::agregarProducto(Producto producto) {
	int cant;
	cout << "¿Cuantas unidades de " << producto.getNombreProducto() << "? ";
	cin >> cant;

	this->agregarADetalleVenta(producto, cant);
}

Response<Venta> Venta::crearNuevaVenta(Sistema* sistema) {
	InterfazUI ventas_UI(sistema); //Utilizo ésta instancia para utilizar limpiarConsola y
	//headerDinamico, y así evitar que la consola se ensucie entre pantalla y pantalla.
	Archivo<Venta> archivoVenta("ventas.dat");
	Response<Venta> response;
	Venta venta;
	bool finalizarVenta = false;


	while (!finalizarVenta) {
		Producto producto;
		char opc;

		ventas_UI.headerDinamico();
		//Obtener listado de productos disponibles para venta:
		producto = producto.listarYSeleccionarProductoVenta();

		ventas_UI.headerDinamico();
		//Seleccionar cantidad y añadir al carrito:
		venta.agregarProducto(producto);

		ventas_UI.headerDinamico();
		//Consultar si desea finalizar la venta:
		cout << "Desea finalizar la venta? (s/n): ";
		cin >> opc;
		if (opc == 's' || opc == 'S') {
			finalizarVenta = !finalizarVenta;
			response.setSuccess("Venta creada correctamente", venta);
		}
	}
	return response;
}