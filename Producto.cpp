#include <iostream>
#include <cstring>
#include "Producto.h"
#include "Archivo.h"
#include <vector>
#include "TablaDto.h"
#include "conio.h"
#include<windows.h>

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

	cout << endl << endl << "------- CARGA DATOS DE PRODUCTO -------" << endl << endl;

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

Producto Producto::listarYSeleccionarProductoVenta(float margenUtilidad) {
	Archivo<Producto> archivoProducto("productos.dat");
	vector<Producto> listaProductos = archivoProducto.listarRegistroArchivo();
	//modificar stock seg�n inventario:
	Archivo<StockDto> archivoStock("stock.dat");
	vector<StockDto> stock;
	stock = archivoStock.listarRegistroArchivo();
	bool continuar = false;

	vector<Producto> listaProductosVendibles; //Ac� metemos productos con stock y activos.
	if (!continuar) {
	for (Producto prod : listaProductos) {
		for (StockDto s : stock) {
			if (s.getId() == prod.getId() && prod.getEstado() && s.getCantidadTotal() > 0) {
				//A�adimos el producto al listado en caso de tener stock y este activo p/ la venta:
				prod.setCantidad(s.getCantidadTotal());
				prod.setPrecioVenta(prod.getPrecioCosto() * margenUtilidad);
				listaProductosVendibles.push_back(prod);
			}
			//en caso de no tener stock, o que sea un producto dado de baja, no se a�ade al listado.
		}
	}

		TablaDto<Producto> tabla("productos", listaProductosVendibles, false);

		cout << "LISTA DE PRODUCTOS: " << endl;
		tabla.generarTablaProductos(listaProductosVendibles);

		int idProducto;
		cout << "Seleccione el Id de producto: ";
		cin >> idProducto;

		Producto productoSeleccionado = Producto();
		for (Producto prod : listaProductos) {
			if (prod.getId() == idProducto && prod.getEstado()) {
				prod.setPrecioVenta(prod.getPrecioCosto() * margenUtilidad);
				productoSeleccionado = prod;
			}
		}
		return productoSeleccionado;
	}
}

Producto Producto::listarYSeleccionarProductoCompra() {
	Archivo<Producto> archivoProducto("productos.dat");
	vector<Producto> listaCompletaProductos = archivoProducto.listarRegistroArchivo();
	//modificar stock seg�n inventario:
	Archivo<StockDto> archivoStock("stock.dat");
	vector<StockDto> stock;
	Producto p;
	stock = archivoStock.listarRegistroArchivo();

	if (!listaCompletaProductos.empty()) {
		for (Producto prod : listaCompletaProductos) {
			for (StockDto s : stock) {
				if (s.getId() == prod.getId()) {
					prod.setCantidad(s.getCantidadTotal());

				}
			}
		}
	}
	TablaDto<Producto> tabla("productos compras", listaCompletaProductos, false);

	cout << "LISTA DE PRODUCTOS: " << endl;
	tabla.generarTablaProductosCompra(listaCompletaProductos);


	int idProducto;
	cout << "Seleccione el producto: ";
	cin >> idProducto;

	switch (idProducto) {
	case 999:
		return Producto();
		break;
	case 0:
		 p.setId(-1);
		 return	p;
		break;
	default:
		for (Producto prod : listaCompletaProductos) {
			if (prod.getId() == idProducto) {
				return prod;
			}
		}
		break;
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


	cout << endl << endl << "------- CARGA DE NUEVOS DATOS DE PRODUCTO -------" << endl << endl;

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
	tablaProductos.generarTablaProductos(vectorProducto);

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

			cout << endl << endl;

			helper.limpiarConsola();
			verProductoAmodificar(responseProducto);
			
			// modificaciones 23-11
			
			responseProducto = opcionModificar(responseProducto);

			producto = responseProducto.getData();
			
			cout << endl;
			//responseProducto.setSuccess("Producto modificado correctamente!", producto);
			archivoProducto.modificarRegistroObajaRegistro(producto, posicion);

			cout << responseProducto.getMessage();
			_sleep(4000);
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
	tablaProductos.generarTablaProductos(vectorProducto);

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
	tablaProductos.generarTablaProductos(vectorProductos);

	cout << endl;

	cout << "Seleccione una tecla para volver al menu anterior..." << endl;
	getch();

}

Response <Producto> Producto::opcionModificar(Response <Producto> &response)
{
	Producto producto;

	int opc;
	bool continuar = false;


	while (!continuar)
	{
		cout << endl <<"Desea modificar el registro completo o algun campo determinado?" << endl << endl;

		cout << "1) Campo determinado - 2) Todo el registro - 0) Atras" << endl << endl;

		
		cin >> opc;

		
		switch (opc)
		{
		case 1:
			system("cls");
			response = modificarCampos(response);
			continuar = true;
			break;
		case 2:
			system("cls");
			producto = cargarProductoAmodificar(true);
			response.setData(producto);
			response.setSuccess("El producto se ha modificado correctamente, volviendo al menu anterior...", producto);
			continuar = true;
			break;
		case 0:
			response.setFailure("No se ha modificado ningun campo, volviendo al menu anterior...");
			continuar = true;
			break;
		default:
			break;
		}

	}
	
	return response;

}

Response <Producto> Producto::modificarCampos(Response <Producto>& response)
{
	Producto producto;
	producto = response.getData();
	
	bool continuar = false;
	int campo;
	int opc=99;
	int contador = 0;

	string nombre, descripcion;
	float precioCosto;

	
	while (!continuar)
	{
		headerProductoAmodificar(response);

		cout << "Selecciones campo que desea modificar: " << endl;

		cout << "1) Nombre Producto - 2) Descripcion del Producto - 3) Precio de costo - 0) Atras" << endl;

		cin.ignore();
		cin >> campo;
		system("cls");

			switch (campo)
			{
			case 1:
				headerProductoAmodificar(response);
				cout << endl <<"Ingrese el nuevo nombre del Producto: ";
				cin.ignore();
				getline(cin, nombre);
				producto.setNombreProducto(nombre);
				response.setData(producto);
				contador++;
				response.setSuccess("Producto modificado correctamente", producto);
				break;
			case 2:
				headerProductoAmodificar(response);
				cout << endl <<"Ingrese nueva descripcion del Producto: ";
				cin.ignore();
				getline(cin, descripcion);
				producto.setDescripcionProducto(descripcion);
				response.setData(producto);
				contador++;
				response.setSuccess("Producto modificado correctamente", producto);
				break;
			case 3:
				headerProductoAmodificar(response);
				cout << endl <<"Ingrese el nuevo precio de costo del Producto: ";
				cin >> precioCosto;
				producto.setPrecioCosto(precioCosto);
				response.setData(producto);
				contador++;
				response.setSuccess("Producto modificado correctamente", producto);
				break;
			case 0:
				continuar = true;
				break;
			default:
				break;
			}
			
			system("cls");

			if (contador > 0)
			{

				headerProductoAmodificar(response);
				cout << "Desea modificar algun campo mas?" << endl;

				cout << "1) Si - 2) No, Guardar y salir" << endl;

				cin >> opc;

				if (opc == 2)
				{
					continuar = true;
				}

			}


		if (opc == 99 || campo == 0)
		{
			if (contador == 0)
			{	
				headerProductoAmodificar(response);
				response.setFailure("No se ha modificado ningun campo, volviendo al menu anterior...");
			}
		continuar = true;
		}
	}

	return response;
	
}

void Producto::headerProductoAmodificar(Response <Producto> response)
{
	system("cls");
	cout << "---------------------------------------------" << endl << endl;
	cout << "------------ PRODUCTO A MODFICAR ------------" << endl << endl;
	cout << "ID Producto:\t\t\t   N# " << response.getData().getId() << endl;
	cout << "Nombre del Producto: \t \t" << "1) " << response.getData().getNombreProducto() << endl;
	cout << "Descripcion del Producto: \t" << "2) " << response.getData().getDescripcionProducto() << endl;
	cout << "Precio de costo del Producto: \t" << "3) " << response.getData().getPrecioCosto() << endl << endl;
	cout << "---------------------------------------------" << endl << endl;
}