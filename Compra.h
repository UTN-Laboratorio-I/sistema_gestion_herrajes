#pragma once

#include "Transaccion.h"

class Compra : private Transaccion 
{
private:
	int _id;
	int _idCompra;

public:
	Compra();
	
	void setId(int id) { _id = id; };
	void setIdCompra(int idCompra) { _idCompra = idCompra; };

	int getId() { return _id; }
	int getIdCompra() { return _idCompra; }

	bool crearNuevaCompra();

};

