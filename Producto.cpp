#include <iostream>
#include "Producto.h"

Producto::Producto(){
	_idProducto = 0;
	_precioCosto = 0;
	_precioVenta = 0;
	_cantidad = 0;
	*_nombreProducto = {};
	*_descripcionProducto = {};
}
int Producto::getIdProducto() {
	return _idProducto;
}
float Producto::getPrecioCosto() {
	return _precioCosto;
}
float Producto::getPrecioVenta() {
	return _precioVenta;
}
int Producto::getCantidad() {
	return _cantidad;
}
std::string Producto::getNombreProducto() {
	return _nombreProducto;
}
std::string Producto::getDescripcionProducto() {
	return _descripcionProducto;
}
void Producto::setIdProducto(int id) {
	_idProducto = id;
}
void Producto::setPrecioCosto(float pCosto) {
	_precioCosto = pCosto;
}
void Producto::setPrecioVenta(float pVenta) {
	_precioVenta = pVenta;
}
void Producto::setCantidad(int cantidad) {
	_cantidad = cantidad;
}
void Producto::setNombreProducto(std::string nombre) {
	strcpy_s(_nombreProducto, nombre.c_str());
}
void Producto::setDescripcionProducto(std::string descripcion) {
	strcpy_s(_descripcionProducto, descripcion.c_str());
}

void Producto::cargarProductos() {
	const char* nombreArchivo = "productos.dat";
	Producto producto;
	Producto* productoLeido;
	Archivo<Producto> archivo;
	Archivo<Producto> leer;

	producto.setCantidad(10);
	producto.setDescripcionProducto("Producto de prueba");
	producto.setNombreProducto("Producto 1");
	producto.setPrecioCosto(100);

	bool grabo = archivo.grabarRegistroArchivo(producto, nombreArchivo);

	if (grabo) {
		std::cout << "Grabo el producto" << std::endl;
		
		std::vector<Producto> productoLeido = leer.listarRegistroArchivo(nombreArchivo);
		
		for (Producto p : productoLeido) {
			std::cout << p.getNombreProducto() << std::endl;
			std::cout << p.getDescripcionProducto() << std::endl;
			std::cout << p.getPrecioCosto() << std::endl;
			std::cout << p.getCantidad() << std::endl;

		}

	}
	else {
		std::cout << "No se grabo el registro" << std::endl;
	}


}
void Producto::mostrarProductos() {

}