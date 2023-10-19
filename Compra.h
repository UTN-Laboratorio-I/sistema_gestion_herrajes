#pragma once

#include "Transaccion.h"
#include "ResponseDto.h"
#include "Proveedor.h"

class Compra : private Transaccion 
{
private:
	int _id;
	int _idCompra;

public:
	Compra();
	
	void setId(int id);
	void setIdCompra(int idCompra);

	int getId();
	int getIdCompra();

	bool crearNuevaCompra();

};

