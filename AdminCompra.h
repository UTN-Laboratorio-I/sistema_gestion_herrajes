#pragma once
#include "Sistema.h"

class AdminCompra
{
private:
	Sistema* _sistema;
	bool modulo_compra_activo;
public:

	AdminCompra(Sistema* sistema);

	void setModuloCompraActivo(bool);

	void administrarModuloCompra();

	void crearCompraProducto();

	void pantallaListarProducto();

	void pantallaBuscarProducto();

};

