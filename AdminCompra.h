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

	bool subModuloCompraActivo();

	void moduloCompraSalir();

	void subModuloCompraSalir();

	void administrarModuloCompra();

	//void crearNuevaCompra();

	void pantallaListarProducto();

	void pantallaBuscarProducto();

	void subModuloCompra();

	void mostrarCompras();

};

