#pragma once
#include "Sistema.h"

class AdminCompra
{
private:
	Sistema* _sistema;
	string _nombreModulo;
public:

	AdminCompra(Sistema* sistema);

	bool moduloCompraActivo();

	void moduloCompraSalir();

	void administrarModuloCompra();

	void crearCompraProducto();

	void pantallaListarProducto();

	void pantallaBuscarProducto();

};

