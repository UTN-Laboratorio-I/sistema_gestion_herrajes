#include <iostream>
#include <cstring>
#include "Producto.h"
#include "Archivo.h"
#include <vector>
#include "TablaDto.h"
#include "conio.h"

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

Producto Producto::cargarProductos(bool inventario) {
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

	getline(cin, descripcionProducto);

	if (!inventario)
	{
	cout << "PRECIO DE COSTO:$ ";
	cin >> pCosto;
	cout << "CANTIDAD: ";
	cin >> cantidad;
	producto.setPrecioCosto(pCosto);
	producto.setCantidad(cantidad);
	}
	/*cout << "PRECIO DE VENTA: ";
	cin >> pVenta;*/

	producto.setNombreProducto(nombreProducto);
	producto.setDescripcionProducto(descripcionProducto);
	
	//setPrecioVenta(pVenta);

	producto.setEstado(true);

	return producto;

}

void Producto::mostrarProducto()
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
	//modificar stock según inventario:
	Archivo<StockDto> archivoStock("stock.dat");
	vector<StockDto> stock;
	stock = archivoStock.listarRegistroArchivo();

	for (Producto prod : listaProductos) {
		for (StockDto s : stock) {
			if (s.getId() == prod.getId()) {
				prod.setCantidad(s.getCantidadTotal());
			}
		}

		TablaDto<Producto> tabla("productos", listaProductos, false);

		cout << "LISTA DE PRODUCTOS: " << endl;
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
}

Producto Producto::listarYSeleccionarProductoCompra() {
	Archivo<Producto> archivoProducto("productos.dat");
	vector<Producto> listaProductos = archivoProducto.listarRegistroArchivo();
	//modificar stock según inventario:
	Archivo<StockDto> archivoStock("stock.dat");
	vector<StockDto> stock;
	stock = archivoStock.listarRegistroArchivo();

	for (Producto prod : listaProductos) {
		for (StockDto s : stock) {
			if (s.getId() == prod.getId()) {
				prod.setCantidad(s.getCantidadTotal());
			}
		}

		TablaDto<Producto> tabla("carrito compras", listaProductos, false);

		cout << "LISTA DE PRODUCTOS: " << endl;
		tabla.generarTablaProductosCompra(listaProductos);

		int idProducto;
		cout << "Seleccione el producto: ";
		cin >> idProducto;

		for (Producto prod : listaProductos) {
			if (prod.getId() == idProducto) {
				return prod;
			}
		}
	}
}



Response <Producto> Producto::responseCargarProducto()
{
	Response <Producto> response;
	Response <Producto> registro;
	Archivo <Producto> archivo("productos.dat");
	float pCosto;
	int cantidad;
	string nombreProducto, descripcionProducto;
	Producto producto;


	system("cls");

	producto = producto.cargarProductos(true);

	 registro = archivo.grabarRegistroArchivo(producto);

	if (registro.getSuccess())
	{
		response.setSuccess("Producto guardado correctamente", registro.getData());

	}
	else
	{
		response.setFailure("No se puedo guardar el producto");
	}

	cout << response.getMessage() << endl;
	cout << "----------------------" << endl << endl;

	_sleep(2000);

	return response;
}

Producto Producto::cargarProductoAmodificar(bool inventario)
{
	Response <Producto> response;
	Response <Producto> registro;
	Archivo <Producto> archivo("productos.dat");
	float pCosto;
	int cantidad;
	string nombreProducto, descripcionProducto;
	Producto producto;

	system("cls");

	cout << "------- CARGA DE NUEVOS DATOS DE PRODUCTO -------" << endl << endl;

	cout << "NOMBRE DE PRODUCTO: ";
	cin.ignore();
	getline(cin, nombreProducto);

	cout << "DESCRIPCION PRODUCTO: ";
	getline(cin, descripcionProducto);

	if (!inventario)
	{
		cout << "PRECIO DE COSTO:$ ";
		cin >> pCosto;
		cout << "CANTIDAD: ";
		cin >> cantidad;
		producto.setPrecioCosto(pCosto);
		producto.setCantidad(cantidad);
	}
	/*cout << "PRECIO DE VENTA: ";
	cin >> pVenta;*/
	//setPrecioVenta(pVenta);

	producto.setNombreProducto(nombreProducto);
	producto.setDescripcionProducto(descripcionProducto);
	producto.setEstado(true);

	return producto;

}

Response<Producto> Producto::modificarOdarBajaProducto(bool modificar)
{
	vector <Producto> vectorProducto;
	Archivo <Producto> archivoProducto("productos.dat");
	vectorProducto = archivoProducto.listarRegistroArchivo();

	TablaDto <Producto> tablaProductos("reporte productos", vectorProducto, true, false);
	tablaProductos.generarReporteProductos(vectorProducto);

	int id = vectorProducto.back().getId();

	Response <Producto> responseProducto;

	Helper helper;

	bool continuar = false;
	int idProducto;
	int opc;
	Producto producto;

	while (!continuar)

	{
		
		//En caso de que modificar sea false
		if (!modificar)
		{
			producto.darBajaProducto(id);
			continuar = false;
			break;
		}
		
		cout << endl << "Ingrese ID de producto que desea modificar: ";
		cin >> idProducto;

		if (idProducto < 1 || idProducto > id)
		{
			cout << endl << "El numero de ID seleccionado no existe, seleccione un ID valido..." << endl;
			_sleep(2000);
			continue;
		}

		int posicion = archivoProducto.buscarPosRegistro(producto, idProducto);

		responseProducto = archivoProducto.listarUnRegistro(posicion, producto);

		cout << endl;

		verProductoAmodificar(responseProducto);

		cout << endl << "Desea modificarlo ?" << endl;

		cout << "1) Si - 2) No - 0) Atras" << endl;
		cin >> opc;

		if (opc == 1)
		{
			helper.limpiarConsola();

			cout << endl;

			verProductoAmodificar(responseProducto);

			producto = cargarProductoAmodificar(true);
			cout << endl;
			responseProducto.setSuccess("Producto modificado correctamente!", producto);
			archivoProducto.modificarRegistroObajaRegistro(producto, posicion);

			cout << responseProducto.getMessage();
			_sleep(2000);
			continuar = true;
		}
		else if (opc == 0)
		{
			responseProducto.setFailure("No se ha modificado ningun producto, volviendo al menu anterior...");
			cout << responseProducto.getMessage();
			_sleep(2000);
			return responseProducto;
			break;
		}

	}
}

void Producto::verProductoAmodificar(Response <Producto> responseProducto)
{
	cout << "El producto seleccionado es: " << " ID: " << responseProducto.getData().getId() << " - " <<responseProducto.getData().getNombreProducto() << " - " << responseProducto.getData().getDescripcionProducto() << endl;
}

Producto Producto::darBajaProducto(int id)
{
	vector <Producto> vectorProducto;
	Archivo <Producto> archivoProducto("productos.dat");
	vectorProducto = archivoProducto.listarRegistroArchivo();

	TablaDto <Producto> tablaProductos("reporte productos", vectorProducto, true, false);
	tablaProductos.generarReporteProductos(vectorProducto);

	id = vectorProducto.back().getId();

	Response <Producto> responseProducto;

	Helper helper;

	bool continuar = false;
	int idProducto;
	int opc;
	Producto producto;

	while (!continuar)
	{

		cout << endl << "Ingrese ID de producto que desea eliminar: ";
		cin >> idProducto;

		if (idProducto < 1 || idProducto > id)
		{
			cout << endl << "El numero de ID seleccionado no existe, seleccione un ID valido..." << endl;
			_sleep(2000);
			continue;
		}

		int posicion = archivoProducto.buscarPosRegistro(producto, idProducto);

		responseProducto = archivoProducto.listarUnRegistro(posicion, producto);

		cout << endl;

		verProductoAmodificar(responseProducto);

		cout << endl << "desea eliminarlo?" << endl;

		cout << "1) Si - 2) No - 0) Atras" << endl;
		cin >> opc;

		if (opc != 1)
		{
			responseProducto.setFailure("No se a eliminado ningun producto, volviendo al menu anterior...");
			continuar = true;
			break;
		}

		cout << "Esta seguro que desea eliminar el producto: " << responseProducto.getData().getId() << " " << responseProducto.getData().getNombreProducto() << " - " << responseProducto.getData().getDescripcionProducto() << endl;
		cout << "1) Si - 2) No - 0) Atras" << endl;

		cin >> opc;

		if (opc == 1)
		{
			producto = responseProducto.getData();
			producto.setEstado(false);

			archivoProducto.modificarRegistroObajaRegistro(producto, posicion, true);

			responseProducto.setSuccess("Producto eliminado correctamente", producto);
			continuar = true;
			break;
		}
		else if (opc != 1)
		{
			responseProducto.setFailure("No se a eliminado ningun producto, volviendo al menu anterior...");
			continuar = true;
			break;
		}

	}
	cout << endl << responseProducto.getMessage();

	_sleep(4000);

	return producto;
}

void Producto::mostrarProductos()
{
	vector <Producto> vectorProductos;
	Archivo <Producto> archivoProducto("productos.dat");
	vectorProductos = archivoProducto.listarRegistroArchivo();

	TablaDto <Producto> tablaProductos("reporte productos", vectorProductos, true, false);
	tablaProductos.generarReporteProductos(vectorProductos);

	cout << endl;

	cout << "Seleccione una tecla para volver al menu anterior..." << endl;
	getch();

}