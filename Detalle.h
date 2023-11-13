#pragma once
#include "Producto.h"
class Detalle
{
private:
	Producto _producto;
	int _cantidad;
public:
	Detalle();
	Detalle(Producto producto, int cantidad);
	Producto getProducto();
	void setIdProducto(int idProducto);
	int getCantidad();
	void setIdProducto(int idProducto);
	void setProducto(Producto producto);
	void setCantidad(int cantidad);
};

