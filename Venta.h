#pragma once
#include "Transaccion.h"
class Venta :
	public Transaccion
{
private:
	int _id;
	int _clienteId;

public:
	Venta();

	void setId(int id);
	int getId();
	void setClienteId(int clienteId);
	int getClienteId();

	Response<Venta> crearNuevaVenta();
};

