#include <iostream>
using namespace std;

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

<<<<<<< HEAD
void Producto::cargarProductos()
{	
	float pCosto, pVenta;
	int cantidad;
	string nombreProducto, descripcionProducto;

	cout << "NOMBRE DE PRODUCTO: ";
	getline(cin, nombreProducto);
	cout << "DESCRIPCION PRODUCTO: ";
	getline(cin,descripcionProducto);
	cout << "PRECIO DE COSTO: ";
	cin >> pCosto;
	/*cout << "PRECIO DE VENTA: ";
	cin >> pVenta;*/
	cout << "CANTIDAD: ";
	cin >> cantidad;
	
	setNombreProducto(nombreProducto);
	setDescripcionProducto(descripcionProducto);
	setPrecioCosto(pCosto);
	//setPrecioVenta(pVenta);
	setCantidad(cantidad);
}

void Producto::mostrarProductos()
{	
	cout << "NOMBRE DE PRODUCTO: ";
	cout << getNombreProducto() << endl;
	cout << "DESCRIPCION PRODUCTO: ";
	cout << getDescripcionProducto() << endl;
	cout << "PRECIO DE COSTO: ";
	cout << getPrecioCosto() << endl;
	/*cout << "PRECIO DE VENTA: ";
	cout << pVenta;*/
	cout << "CANTIDAD: ";
	cout << getCantidad() << endl;

}
=======
void Producto::cargarProductos() {
}
>>>>>>> develop
