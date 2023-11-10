#pragma once
#include "ResponseDto.h"
#include "DetalleStockDto.h"
#include "StockDto.h"
class Stock
{
private:
	int idProducto;
	int cantidadTotal;
	vector<DetalleStockDto> detalleStock;
	char tipoTransaccion;
public:
	Response<Stock> gestionarStock(int cantidad, int idProducto, char tipoTransaccion);
	Response<StockDto> sumarStock(int cantidad, int idProducto);
	Response<StockDto> restarStock(int cantidad, int idProducto);
};

