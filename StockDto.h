#pragma once
#include <iostream>
#include <vector>
#include "DetalleStockDto.h"

using namespace std;

class StockDto
{
private:
	//ajuste de lista de precio en %
	//Al vender, se toma el margen de utilidad al mayor precio de compra producto.
	int idProducto; //Yerba
	int cantidadTotal; // 30 unidades
	/*vector<DetalleStockDto> detalleStock;*/

		//Cliente compra 22 unidades -> 10 unidades a 200 y 12 unidades a 150
public:
	StockDto();
	StockDto(int idProducto, int cantidad);
	~StockDto();
	int getIdProducto();
	int getCantidadTotal();
	//vector<DetalleStockDto> getDetalleStock();
	void setIdProducto(int idProducto);
	void setCantidadTotal(int cantidadTotal);
	//void setDetalleStock(vector<DetalleStockDto> detalleStock);

};
