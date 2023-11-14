#include <iostream>
#include <cstring>
#include "Producto.h"
#include "Archivo.h"
#include <vector>
#include "TablaDto.h"

using namespace std;

Producto::Producto(){
	_id = 0;
	_precioCosto = 0;
	_precioVenta = 0;
	_cantidad = 0;
	*_nombreProducto = {};
	*_descripcionProducto = {};
	_estado = false;
}

#pragma region GETTERS

int Producto::getId() {
	return _id;
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

void Producto::setId(int id) {
	_id = id;
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

Producto Producto::cargarProductos() {
	Response <Producto> registro;
	Archivo <Producto> archivo("productos.dat");
	float pCosto, pVenta;
	int cantidad;
	string nombreProducto, descripcionProducto;
	Producto producto;

	cout << "NOMBRE DE PRODUCTO: ";
	cin.ignore();
	getline(cin, nombreProducto);

	cout << "DESCRIPCION PRODUCTO: ";
	cin.ignore();
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

	/*registro = archivo.grabarRegistroArchivo(producto);

	if (registro.getSuccess())
	{
		registro.setSuccess("Producto grabado correctamente", registro.getData());
	}
	else
	{
		registro.setFailure("El producto no se pudo grabar");
	}
	
	cout << registro.getMessage() << endl;
	cout << "----------------------" << endl;

	_sleep(2000);*/

	return producto;

}

void Producto::mostrarProductos()
{
	cout << "ID PRODUCTO: ";
	cout << getId() << endl;
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

Producto Producto::listarYSeleccionarProductoVenta() {
	Archivo<Producto> archivoProducto("productos.dat");
	vector<Producto> listaProductos = archivoProducto.listarRegistroArchivo();
	TablaDto<Producto> tabla("productos", listaProductos, false);
	tabla.generarTablaProductos(listaProductos);


	int idProducto;
	cout << "Seleccione el producto: ";
	cin >> idProducto;

	for (Producto prod : listaProductos) {
		if (prod.getId() == idProducto) {
			return prod;
		}
	}
}