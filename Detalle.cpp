#include "Detalle.h"
#include "Producto.h"

Detalle::Detalle() {};

Detalle::Detalle(Producto producto, int cantidad) {
	_producto = producto;
	_cantidad = cantidad;
};

Producto Detalle::getProducto() {
	return _producto;
}

int Detalle::getCantidad() {
	return _cantidad;
}

void Detalle::setProducto(Producto producto) {
	_producto = producto;
}

void Detalle::setCantidad(int cantidad) {
	_cantidad = cantidad;
}


