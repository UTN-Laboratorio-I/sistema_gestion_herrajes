#include <iostream>
#include <cstring>
#include "Producto.h"
#include "Archivo.h"
#include <vector>

using namespace std;

Producto::Producto(){
	_idProducto = 0;
	_precioCosto = 0;
	_precioVenta = 0;
	_cantidad = 0;
	*_nombreProducto = {};
	*_descripcionProducto = {};
	_estado = false;
}

#pragma region GETTERS

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

bool Producto::getEstado() { return _estado; }

#pragma endregion

#pragma region SETTERS

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

void Producto::setEstado(bool estado){ _estado = estado;}

#pragma endregion

void Producto::cargarProductos() {
	float pCosto, pVenta;
	int cantidad;
	string nombreProducto, descripcionProducto;
	vector <Producto> producto;
	Archivo <Producto> archivo("productos.dat");

	cout << "NOMBRE DE PRODUCTO: ";
	//cin.ignore();
	getline(cin, nombreProducto);
	cout << "DESCRIPCION PRODUCTO: ";
	getline(cin, descripcionProducto);
	cout << "PRECIO DE COSTO:$ ";
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
	setEstado(true);
	setIdProducto(archivo.contadorRegistros(producto, archivo));
}

void Producto::mostrarProductos()
{
	cout << "ID PRODUCTO: ";
	cout << getIdProducto() << endl;
	cout << "NOMBRE DE PRODUCTO: ";
	cout << getNombreProducto() << endl;
	cout << "DESCRIPCION PRODUCTO: ";
	cout << getDescripcionProducto() << endl;
	cout << "PRECIO DE COSTO:$ ";
	cout << getPrecioCosto() << endl;
	/*cout << "PRECIO DE VENTA: ";
	cout << pVenta;*/
	cout << "CANTIDAD: ";
	cout << getCantidad() << endl;
}

int Producto::funcion()
{
	vector <Producto> producto;
	Archivo <Producto> archivo("productos.dat");

	producto = archivo.listarRegistroArchivo();

	int cantidadReg = 0;

	for (Producto i : producto)
	{
		cantidadReg++;
	}

	return cantidadReg;
}