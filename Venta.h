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
	Venta(int id, float monto, int productoId, int clienteId, Fecha fecha, Usuario usuario, char tipo, int proveedorId);
	void setId(int id);
	int getId();
	void setProveedorId(int proveedorId);
	int getProveedorId();
	bool crearNuevaVenta(float monto, char tipo, const char* usuario, int proveedorId);
};

