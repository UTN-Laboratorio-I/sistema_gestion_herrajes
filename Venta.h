#pragma once
#include "Transaccion.h"
class Venta :
	public Transaccion
{
private:
	int _id;
	int _clienteId;
	char _tipo;

public:
	Venta();

	void setId(int id);
	int getId();
	void setClienteId(int clienteId);
	int getClienteId();
	void setTipoTransaccion(char tipoTransaccion);
	char getTipoTransaccion();

	Response<Venta> crearNuevaVenta();
};

