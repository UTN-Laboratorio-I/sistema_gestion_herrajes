#include "StockDto.h"
#include "Archivo.h"

StockDto::StockDto(){}
StockDto::StockDto(int idProducto, int cantidad)
{
	this->idProducto = idProducto;
	this->cantidadTotal = cantidad;
}

StockDto::~StockDto()
{
}

int StockDto::getId() //idproducto
{
	return this->idProducto;
}

int StockDto::getCantidadTotal()
{
	return this->cantidadTotal;
}

//vector<DetalleStockDto> StockDto::getDetalleStock()
//{
//	return this->detalleStock;
//}

void StockDto::setIdProducto(int idProducto)
{
	this->idProducto = idProducto;
}

void StockDto::setCantidadTotal(int cantidadTotal)
{
	this->cantidadTotal = cantidadTotal;
}

//void StockDto::setDetalleStock(vector<DetalleStockDto> detalleStock)
//{
//	this->detalleStock = detalleStock;
//}

