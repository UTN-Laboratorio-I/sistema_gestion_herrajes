#pragma once

class DetalleStockDto
{
private:
	int precio;
	int cantidad;
public :
	DetalleStockDto();
	DetalleStockDto(int precio, int cantidad);
	int getPrecio();
	void setPrecio(int precio);
	int getCantidad();
	void setCantidad(int cantidad);
};

