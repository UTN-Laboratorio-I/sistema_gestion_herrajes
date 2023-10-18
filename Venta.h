#pragma once
#include "Transaccion.h"
class Venta :
	private Transaccion
{
private:
	int _id;
	int _proveedorId;
public:
	Venta();

	void setId(int id);
	int getId();
	void setProveedorId(int proveedorId);
	int getProveedorId();

	Response<Venta> crearNuevaVenta(float monto, char tipo, const char* usuario, int proveedorId);
};

