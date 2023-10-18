#pragma once
#include "Sistema.h"
class AdminVenta
{
private:
	string _nombreModulo;
	Sistema* _sistema;
public:
	AdminVenta(Sistema* sistema);
	bool moduloVentaActivo();
	void moduloVentaSalir();
	void administrarModuloVenta();
	void registrarNuevaVenta();
	void pantallaListarProducto();
	void pantallaBuscarProducto();
};

