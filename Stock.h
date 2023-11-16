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
	Stock();
	Response<Stock> gestionarStock(int cantidad, int idProducto, char tipoTransaccion);

	template <class T>
	Response<StockDto> sumarStock(int cantidad, int idProducto);

	template <class T>
	Response<StockDto> restarStock(int cantidad, int idProducto);

	template <class T>
	bool validarStock(int idProducto, T objeto);

	int getIdProducto();

	int getCantidad();

	void mostrarStock();

};

