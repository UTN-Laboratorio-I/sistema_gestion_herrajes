#include "Stock.h"
#include "Producto.h"
#include "StockDto.h"

Stock::Stock() {};



//GETTERS

int Stock::getIdProducto() {
	return idProducto;
}

int Stock::getCantidad()
{
	return cantidadTotal;
}

//

Response<Stock> Stock::gestionarStock(int cantidad, int idProducto, char tipoTransaccion) {
	Response<Stock> response;
	Response<StockDto> responseDto;
	
	switch (tipoTransaccion) {
	case 'v':
			responseDto = restarStock<StockDto>(cantidad, idProducto);
			break;
	case 'c':
			responseDto = sumarStock<StockDto>(cantidad, idProducto);
			break;
	default:
			break;
	}
	return response;
}

//Función para pasar como parametro:
template <class T>
bool Stock::validarStock(int idProducto, T objetoArchivo) {
	T stock = (T)objetoArchivo;
	if (idProducto == stock.getId()) {
		return true;
	}
	return false;
}

typedef bool(Stock:: *validarStock)(int, int);
template <class T>
Response<StockDto> Stock::sumarStock(int cantidad, int idProducto) {
	Response<StockDto> response;
	Archivo<StockDto> archivoStock("stock.dat");
	int cantidadActualizada = cantidad;
	response = archivoStock.buscarUnRegistro(idProducto);
	if (response.getSuccess()) {
	cantidadActualizada = response.getData().getCantidadTotal() + cantidad;
	}

	StockDto stock(idProducto, cantidadActualizada);

	auto funcionValidar = [this](int idProducto, T objetoArchivo) {return validarStock(idProducto, objetoArchivo); };

	response = archivoStock.grabarOModificarRegistro(stock, idProducto, funcionValidar);

	return response;
}

typedef bool(Stock::* validarStock)(int, int);
template <class T>
Response<StockDto> Stock::restarStock(int cantidad, int idProducto) {
	Response<StockDto> response;
	Archivo<StockDto> archivoStock("stock.dat");
	int cantidadActualizada = cantidad;
	response = archivoStock.buscarUnRegistro(idProducto);
	if (response.getSuccess()) {
		cantidadActualizada = response.getData().getCantidadTotal() - cantidad;
	}
	StockDto stock(idProducto, cantidadActualizada);

	auto funcionValidar = [this](int idProducto, T idArchivo) {return validarStock(idProducto, idArchivo); };
	response = archivoStock.grabarOModificarRegistro(stock, idProducto, funcionValidar);

	return response;
}

void Stock::mostrarStock()
{
	Archivo <Producto> archivoProducto("productos.dat");
	Response <Producto> responseProducto;
	Producto producto;

	responseProducto = archivoProducto.listarUnRegistro(this->getIdProducto(), producto);

	cout << responseProducto.getData().getId() << endl;
	cout << responseProducto.getData().getDescripcionProducto() << endl;
	cout << this->getCantidad() << endl;

}