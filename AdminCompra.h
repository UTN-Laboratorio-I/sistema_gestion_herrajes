#pragma once
#include "Sistema.h"
#include "Producto.h"

class AdminCompra
{
public:
	void compraProducto()
	{
		Producto prod;

		prod.cargarProductos();
		prod.mostrarProductos();
	}
private:


};

