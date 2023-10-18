#include "Venta.h"

Venta::Venta() {}

void Venta::setId(int id) {
	_id = id;
}
int Venta::getId() {
	return _id;
}
void Venta::setProveedorId(int proveedorId) {
	_proveedorId = proveedorId;
}
int Venta::getProveedorId() {
	return _proveedorId;
}

Response<Venta> crearNuevaVenta() {
	Archivo<Venta> archivo("Ventas.dat");
	Venta venta;
	Response<Venta> response;

	return response;
}