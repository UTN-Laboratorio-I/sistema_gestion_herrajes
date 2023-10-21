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
	~Detalle();
	Producto getProducto();
	int getCantidad();
	void setProducto(Producto producto);
	void setCantidad(int cantidad);
};

