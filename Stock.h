#pragma once
#include "ResponseDto.h"
class Stock
{
private:
	int cantidad;
	int idProducto;
	char tipoTransaccion;
public:
	Response<Stock> gestionarStock(int cantidad, int idProducto, char tipoTransaccion);
	Response<Stock> sumarStock(int cantidad, int idProducto);
	Response<Stock> restarStock(int cantidad, int idProducto);
};

