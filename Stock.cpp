#include "Stock.h"
#include "Producto.h"
#include "StockDto.h"


Response<Stock> Stock::gestionarStock(int cantidad, int idProducto, char tipoTransaccion) {
	Response<Stock> response;
	Response<StockDto> responseDto;
	
	switch (tipoTransaccion) {
	case 'v':
			responseDto = restarStock(cantidad, idProducto);
			break;
	case 'c':
			responseDto = sumarStock(cantidad, idProducto);
			break;
	default:
			break;
	}
	return response;
}

Response<StockDto> Stock::sumarStock(int cantidad, int idProducto) {
	Response<StockDto> response;
	Archivo<StockDto> archivoStock("stock.dat");
	StockDto stock(idProducto, cantidad);

	int existente = archivoStock.buscarPosRegistro(stock, idProducto);

	if (existente != -1) {
		stock.setCantidadTotal(stock.getCantidadTotal() + cantidad);
	}

	response = archivoStock.grabarOModificarRegistro(stock, idProducto);

	if (!response.getSuccess()) {
		response.setFailure("No se ha podido registrar el cambio de stock");
	}
	return response;
}

Response<StockDto> Stock::restarStock(int cantidad, int idProducto) {
	Response<StockDto> response;
	Archivo<StockDto> archivoStock("stock.dat");
	StockDto stock(idProducto, cantidad);

	int existente = archivoStock.buscarPosRegistro(stock, idProducto);

	//En caso de que el producto ya esté registrado, sobreescribimos la cantidad:
	if (existente != -1) {
		stock.setCantidadTotal(stock.getCantidadTotal() - cantidad);
	}
	
	response = archivoStock.grabarOModificarRegistro(stock, idProducto);

	if (!response.getSuccess()) {
		response.setFailure("No se ha podido registrar el cambio de stock");
	}

	return response;
}